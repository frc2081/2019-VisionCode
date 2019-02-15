#include "stdafx.h"
#include "ImageData.h"

using namespace cv;
using namespace std;

namespace Icarus
{
	ImageData::ImageData()
	{
	}

	Mat* ImageData::GetImageData()
	{
		return _imageData;
	}

	vector<Contour>* ImageData::GetContours()
	{
		return _contours;
	}

	void ImageData::SetImageData(Mat* source)
	{
		_imageData = source;
	}

	void ImageData::SetContours(vector<Contour>* contours)
	{
		_contours = contours;
	}
}
