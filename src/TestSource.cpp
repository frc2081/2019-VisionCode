#include "stdafx.h"
#include "TestSource.h"

using namespace std;
using namespace grip;
using namespace cv;

namespace Icarus
{
	void TestSource::Init()
	{
		_pipeline = new GripPipeline(_config);
    ReadTestImage();
	}

	void TestSource::Clean()
	{
		delete _pipeline;
	}

	void TestSource::Source(ImageData * data)
	{	
		data->SetImageData(&_testImage);
		data->SetContours(_contours);
	}

  void TestSource::ReadTestImage()
  {
    const char* testImageName = "SimulatedTargets.png";
    string testImage = _config->GetShareDir() + "/" + testImageName;

    _testImage = imread(testImage);
    _pipeline->Process(_testImage);
    _contours = _pipeline->GetFilterContoursOutput();
  }

	TestSource::TestSource(VisionConfiguration * config)
	{
		_config = config;
	}
}
