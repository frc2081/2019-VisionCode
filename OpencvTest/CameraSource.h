#pragma once

#include "VisionSource.h"
#include "ImageData.h"
#include "GripPipeline.h"

namespace Icarus
{
	class CameraSource : public VisionSource
	{
	private:
		int _cameraIndex;
		double _scale;

		grip::GripPipeline* _pipeline;
		cv::VideoCapture* _cam;
		cv::Mat _rawImage, *_mask;

	protected:
		void Init();
		void Clean();
		void Source(ImageData* data);

	public:
		CameraSource(double scale, int cameraIndex);
	};
	

}