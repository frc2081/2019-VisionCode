#pragma once

#include <opencv2/opencv.hpp>

namespace Icarus
{
	class ImageData
	{
	private:
		cv::Mat* _imageData;
		std::vector<std::vector<cv::Point>>* _contours;

	public:
		ImageData();
		cv::Mat* GetImageData();
		std::vector<std::vector<cv::Point>>* GetContours();

		void SetImageData(cv::Mat* source);
		void SetContours(std::vector<std::vector<cv::Point>>* contours);
	};
}
