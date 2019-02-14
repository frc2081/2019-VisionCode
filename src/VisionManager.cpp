#include "stdafx.h"
#include "VisionManager.h"

using namespace std;
using namespace grip;
using namespace cv;

namespace Icarus
{
	VisionManager::VisionManager(VisionConfiguration* config, VisionSource* source, VisionSink* sink, VisionFilter* filter)
	{
		_config = config;
		_source = source;
		_sink = sink;
    _filter = filter;
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
      _filter->Filter(&data);
			_sink->Consume(&data);
      if (_sink->OpensWindow() && waitKey(1) == 27)
        break;
		}

		return 0;
	}
}
