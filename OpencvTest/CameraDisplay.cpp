#include "stdafx.h"
#include "CameraDisplay.h"
#include <opencv2\opencv.hpp>
#include <opencv2\imgcodecs.hpp>

using namespace cv;

namespace Icarus
{
	void CameraDisplay::Initialize()
	{
		if (_initialized)
			return;
		
		namedWindow(_windowName);
		_initialized = true;
	}

	void CameraDisplay::Close()
	{
		if (!_initialized)
			return;

		destroyWindow(_windowName);
		_initialized = false;
	}

	CameraDisplay::CameraDisplay(const char * windowName)
	{
		_windowName = windowName;
	}

	void CameraDisplay::Consume(ImageData * source)
	{
		Mat* contents;
		if (!_initialized)
			Initialize();

		contents = source->GetImageData();
		imshow(_windowName, *contents);
	}
}
