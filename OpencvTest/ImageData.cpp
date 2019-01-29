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

	std::vector<cv::KeyPoint>* ImageData::GetBlobData()
	{
		return _blobData;
	}

	void ImageData::SetImageData(cv::Mat* source)
	{
		_imageData = source;
	}

	void ImageData::SetBlobData(std::vector<cv::KeyPoint>* blobData)
	{
		_blobData = blobData;
	}
}
