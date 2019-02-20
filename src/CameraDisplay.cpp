#include "stdafx.h"
#include "CameraDisplay.h"
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string.h>

using namespace cv;
using namespace std;

namespace Icarus
{
	void CameraDisplay::Init()
	{
    namedWindow(_windowName);
	}

	void CameraDisplay::Clean()
	{
    destroyWindow(_windowName);
	}

	CameraDisplay::CameraDisplay(const char * windowName)
	{
		_windowName = windowName;
	}

	void CameraDisplay::Sink(ImageData * source)
	{
		Mat* contents;
    contents = source->GetImageData();
    imshow(_windowName, *contents);
	}

  bool CameraDisplay::OpensWindow()
  {
    return true;
  }
}

