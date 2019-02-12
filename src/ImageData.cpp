#include "stdafx.h"
#include "ImageData.h"

namespace Icarus
{
	ImageData::ImageData()
	{
	}

	cv::Mat* ImageData::GetImageData()
	{
		return _imageData;
	}

	std::vector<std::vector<cv::Point>>* ImageData::GetContours()
	{
		return _contours;
	}

	void ImageData::SetImageData(cv::Mat* source)
	{
		_imageData = source;
	}

	void ImageData::SetContours(std::vector<std::vector<cv::Point>>* contours)
	{
		_contours = contours;
	}
}
