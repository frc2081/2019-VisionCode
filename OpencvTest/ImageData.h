#pragma once

#include <opencv2\opencv.hpp>

namespace Icarus
{
	class ImageData
	{
	private:
		cv::Mat* _imageData;
		std::vector<cv::KeyPoint>* _blobData;

	public:
		ImageData();
		cv::Mat* GetImageData();
		std::vector<cv::KeyPoint>* GetBlobData();

		void SetImageData(cv::Mat* source);
		void SetBlobData(std::vector<cv::KeyPoint>* blobData);
	};
}