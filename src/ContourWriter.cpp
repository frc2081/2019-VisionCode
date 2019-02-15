#include "stdafx.h"
#include "ContourWriter.h"
#include <thread>
#include <chrono>

using namespace std;
using namespace cv;
using namespace std::chrono;
using namespace nt;

namespace Icarus
{
	void ContourWriter::Init()
	{
    _networkTableInstance.StartClientTeam(2081);
    _networkTable = _networkTableInstance.GetTable("datatable");
	}

	void ContourWriter::Clean()
	{
    _networkTableInstance.StopClient();
    _networkTable = NULL;
	}

	void ContourWriter::Sink(ImageData * source)
	{
		WriteVisionData(GetVisionData(source));
	}

  shared_ptr<NetworkTable> ContourWriter::GetNetworkTable()
  {
    return _networkTable;
  }

  int ContourWriter::GetHeartbeat()
  {
    const int maxHeart = 32000;
    return _heartbeat = ++_heartbeat % maxHeart;
  }

	ContourWriter::ContourWriter()
	{
    _heartbeat = 0;
    _networkTableInstance = nt::NetworkTableInstance::GetDefault();
	}
  
  bool ContourWriter::OpensWindow()
  {
    return false;
  }

	VisionState ContourWriter::GetState(ImageData * source)
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

	ContourWriter::VisionTargetData ContourWriter::GetTargetData(Contour contour, int ImageCenter)
	{
		Rect bound = boundingRect(contour);
		ContourWriter::VisionTargetData Data;

		Data.TargetHeight = bound.height;
		Data.TargetWidth = bound.width;
		Data.TargetDistFromCenter = (bound.x + (bound.width / 2)) - ImageCenter;

		return Data;
	}

	ContourWriter::VisionData ContourWriter::GetVisionData(ImageData * source)
	{
		if (GetState(source) != TwoContoursDetected) {
			return ContourWriter::VisionData::BadData();
		}

		ContourWriter::VisionData Data;
		Data.IsValid = true;

		Contour Left, Right;
		int center = source->GetImageData()->cols / 2;

		GetTargetVectors(source, &Left, &Right);
		Data.LeftTarget = GetTargetData(Left, center);
		Data.RightTarget = GetTargetData(Right, center);

		return Data;
	}

	void ContourWriter::WriteVisionData(VisionData Data)
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

	ContourWriter::VisionData ContourWriter::VisionData::BadData()
	{
		ContourWriter::VisionData Bad;
		Bad.LeftTarget = ContourWriter::VisionTargetData::BadData();
		Bad.RightTarget = ContourWriter::VisionTargetData::BadData();
		Bad.IsValid = false;
		return Bad;
	}

	ContourWriter::VisionTargetData ContourWriter::VisionTargetData::BadData()
	{
		ContourWriter::VisionTargetData Bad;
		Bad.TargetDistFromCenter = -1;
		Bad.TargetHeight = -1;
		Bad.TargetWidth = -1;

		return Bad;
	}

	void ContourWriter::GetTargetVectors(ImageData* source, Contour* Left, Contour* Right){
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


  void ContourWriter::FlushData()
  {
    _networkTableInstance.Flush();
  }
}
