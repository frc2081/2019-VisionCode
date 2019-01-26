#pragma once
#include <opencv2\opencv.hpp>
#include "ImageData.h"
#include "GripPipeline.h"
#include "VisionConfiguration.h"
#include "VisionSink.h"

namespace Icarus
{
	class VisionManager
	{
	private:
		bool _initialized;
		VisionConfiguration* _config;
		ImageData _imageData;
		VisionSink* _sink;
		grip::GripPipeline* _pipeline;
		cv::VideoCapture* _cam;
		cv::Mat _rawImage, *_mask;

		void LoadImageData(ImageData* data);

	public:
		VisionManager(VisionConfiguration* config, VisionSink* sink);
		virtual ~VisionManager();

		void Initialize();
		void Close();
		int Run();
	};
}