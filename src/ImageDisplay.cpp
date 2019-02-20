#include "stdafx.h"
#include "ImageDisplay.h"
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string.h>

static void SetInfo(char* info, Icarus::ImageData* data);

using namespace cv;
using namespace std;

namespace Icarus
{
	void ImageDisplay::Init()
	{
	  _imageName = _config->GetTestImage();
	}

	void ImageDisplay::Clean()
	{
		
	}

	ImageDisplay::ImageDisplay(VisionConfiguration* config)
	{
    _config = config;
	}

	void ImageDisplay::Sink(ImageData * source)
	{
		Mat* contents;
		contents = source->GetImageData();
		imwrite(_imageName, *contents);
		throw "kill";
	}

  bool ImageDisplay::OpensWindow()
  {
    return false;
  }
}
