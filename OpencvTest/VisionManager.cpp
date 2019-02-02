#include "stdafx.h"
#include "VisionManager.h"
#include <opencv2\opencv.hpp>
#include <opencv2\imgcodecs.hpp>

using namespace std;
using namespace grip;
using namespace cv;

namespace Icarus
{
	VisionManager::VisionManager(VisionConfiguration* config, VisionSource* source, VisionSink* sink)
	{
		_config = config;
		_source = source;
		_sink = sink;
	}

	VisionManager::~VisionManager()
	{
		Close();
	}

	void VisionManager::Init()
	{
		_source->Initialize();
		_sink->Initialize();
	}

	void VisionManager::Clean()
	{
		_source->Close();
		_sink->Close();
	}

	int VisionManager::Run()
	{		
		ImageData data;
		while (1)
		{
			_source->GetImageData(&data);
			_sink->Consume(&data);

			if (_config->GetSourceType() != 'w' && waitKey(1) == 27)
				break;
		}

		return 0;
	}
}