#pragma once

#include <opencv2/opencv.hpp>
namespace Icarus
{
  typedef std::vector<cv::Point> Contour;
  
	class ImageData
	{
	private:
		cv::Mat* _imageData;
		std::vector<Contour>* _contours;

	public:
		ImageData();
		cv::Mat* GetImageData();
		std::vector<Contour>* GetContours();

		void SetImageData(cv::Mat* source);
		void SetContours(std::vector<Contour>* contours);
	};
}
