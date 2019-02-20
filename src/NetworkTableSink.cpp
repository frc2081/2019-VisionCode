#include "stdafx.h"
#include "NetworkTableSink.h"
#include <thread>
#include <chrono>

using namespace std;
using namespace cv;
using namespace std::chrono;
using namespace nt;

namespace Icarus
{
	void NetworkTableSink::Init()
	{
    _networkTableInstance.StartClientTeam(2081);
    _networkTable = _networkTableInstance.GetTable("datatable");
	}

	void NetworkTableSink::Clean()
	{
    _networkTableInstance.StopClient();
    _networkTable = NULL;
	}

	void NetworkTableSink::Sink(ImageData * source)
	{
		WriteVisionData(GetVisionData(source));
	}

  shared_ptr<NetworkTable> NetworkTableSink::GetNetworkTable()
  {
    return _networkTable;
  }

  int NetworkTableSink::GetHeartbeat()
  {
    const int maxHeart = 32000;
    return _heartbeat = ++_heartbeat % maxHeart;
  }

	NetworkTableSink::NetworkTableSink()
	{
    _heartbeat = 0;
    _networkTableInstance = nt::NetworkTableInstance::GetDefault();
	}
  
  bool NetworkTableSink::OpensWindow()
  {
    return false;
  }

	VisionState NetworkTableSink::GetState(ImageData * source)
	{
		vector<Contour>* contours = source->GetContours();
		int ContourNum = contours->size();

		switch (ContourNum)
		{
		case  0:
			return NoContoursDetected;

		case 1:
			return OneContourDetected;

		case 2:
			return TwoContoursDetected;

		default:
			return TooManyContoursDetected;
		}
	}

	NetworkTableSink::VisionTargetData NetworkTableSink::GetTargetData(Contour contour, int ImageCenter)
	{
		Rect bound = boundingRect(contour);
		NetworkTableSink::VisionTargetData Data;

		Data.TargetHeight = bound.height;
		Data.TargetWidth = bound.width;
		Data.TargetDistFromCenter = (bound.x + (bound.width / 2)) - ImageCenter;

		return Data;
	}

	NetworkTableSink::VisionData NetworkTableSink::GetVisionData(ImageData * source)
	{
		if (GetState(source) != TwoContoursDetected) {
			return NetworkTableSink::VisionData::BadData();
		}

		NetworkTableSink::VisionData Data;
		Data.IsValid = true;

		Contour Left, Right;
		int center = source->GetImageData()->cols / 2;

		GetTargetVectors(source, &Left, &Right);
		Data.LeftTarget = GetTargetData(Left, center);
		Data.RightTarget = GetTargetData(Right, center);

		return Data;
	}

	void NetworkTableSink::WriteVisionData(VisionData Data)
	{
    const int waitInMilliseconds = 20;
    this_thread::sleep_for(chrono::milliseconds(waitInMilliseconds));

    shared_ptr<NetworkTable> table = GetNetworkTable();

    // Target Data
    table->PutNumber("LeftTargetHeight", Data.LeftTarget.TargetHeight);
    table->PutNumber("RightTargetHeight", Data.RightTarget.TargetHeight);
    table->PutNumber("LeftTargetWidth", Data.LeftTarget.TargetWidth);
    table->PutNumber("RightTargetWidth", Data.RightTarget.TargetWidth);
    table->PutNumber("LeftTargetDistFromCenter", Data.LeftTarget.TargetDistFromCenter);
    table->PutNumber("RightTargetDistFromCenter", Data.RightTarget.TargetDistFromCenter);

    // Metadata
    table->PutBoolean("TargetDataValid", Data.IsValid);
    table->PutNumber("VisionHeartbeat", GetHeartbeat());

    FlushData();
	}

	NetworkTableSink::VisionData NetworkTableSink::VisionData::BadData()
	{
		NetworkTableSink::VisionData Bad;
		Bad.LeftTarget = NetworkTableSink::VisionTargetData::BadData();
		Bad.RightTarget = NetworkTableSink::VisionTargetData::BadData();
		Bad.IsValid = false;
		return Bad;
	}

	NetworkTableSink::VisionTargetData NetworkTableSink::VisionTargetData::BadData()
	{
		NetworkTableSink::VisionTargetData Bad;
		Bad.TargetDistFromCenter = -1;
		Bad.TargetHeight = -1;
		Bad.TargetWidth = -1;

		return Bad;
	}

	void NetworkTableSink::GetTargetVectors(ImageData* source, Contour* Left, Contour* Right){
			vector<Contour>* contours = source->GetContours();

			Contour a = contours->at(0);
			Contour b = contours->at(1);

			if(a.at(0).x < b.at(0).x){
				*Left = a;
				*Right = b;
			}else{
				*Left = b;
				*Right = a;
			}
			
  }

   void NetworkTableSink::FlushData()
  {
    _networkTableInstance.Flush();
  }
}
