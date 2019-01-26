#include "stdafx.h"
#include "VisionManager.h"
#include <opencv2\opencv.hpp>
#include <opencv2\imgcodecs.hpp>

using namespace std;
using namespace grip;
using namespace cv;

namespace Icarus
{
	void VisionManager::LoadImageData(ImageData* data)
	{
		vector<KeyPoint>* _blobs;

		if (!_initialized)
			throw "Attempted to load image data without initializing.";

		*_cam >> _rawImage;
		_pipeline->Process(_rawImage);
		_blobs = _pipeline->GetFindBlobsOutput();

		data->SetImageData(_pipeline->GetMaskOutput());
		data->SetBlobData(_pipeline->GetFindBlobsOutput());
	}

	VisionManager::VisionManager(VisionConfiguration* config, VisionSink* sink)
	{
		_config = config;
		_sink = sink;
		_initialized = false;
	}

	VisionManager::~VisionManager()
	{
		Close();
	}

	void VisionManager::Initialize()
	{
		if (_initialized)
			return;
		
		_pipeline = new GripPipeline(_config->GetScale());
		_cam = new VideoCapture(_config->GetCameraIndex());

		_initialized = true;
	}

	void VisionManager::Close()
	{
		if (!_initialized)
			return;

		_cam->release();

		delete _pipeline;
		delete _cam;
		_initialized = false;
	}

	int VisionManager::Run()
	{		
		ImageData data;
		const char* windowName = "camera";		

		namedWindow(windowName);

		Initialize();
		while (1)
		{
			LoadImageData(&data);
			imshow(windowName, *data.GetImageData());

			if (waitKey(1) == 27)
				break;
		}
		Close();

		return 0;
	}
}