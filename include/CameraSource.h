#pragma once

#include "VisionSource.h"
#include "ImageData.h"
#include "GripPipeline.h"

namespace Icarus
{
	class CameraSource : public VisionSource
	{
	private:
		VisionConfiguration* _config;

		std::vector<Contour>* _contours;
		grip::GripPipeline* _pipeline;
		cv::VideoCapture* _cam;
		cv::Mat _rawImage, *_mask;

		void ReadFromCamera();

	protected:
		void Init();
		void Clean();
		virtual void Source(ImageData* data);

		cv::Mat* GetRawImage();
		cv::Mat* GetMask();
		std::vector<Contour>* GetContours();

	public:
		CameraSource(VisionConfiguration* config);
	};
}
