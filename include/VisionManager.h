#pragma once
#include <opencv2/opencv.hpp>
#include "ImageData.h"
#include "GripPipeline.h"
#include "VisionConfiguration.h"
#include "VisionSink.h"
#include "VisionSource.h"
#include "IoEntity.h"

namespace Icarus
{
	class VisionManager : public IoEntity
	{
	private:
		VisionConfiguration* _config;
		ImageData _imageData;
		VisionSource* _source;
		VisionSink* _sink;

	protected:
		void Init();
		void Clean();

	public:
		VisionManager(VisionConfiguration* config, VisionSource* source, VisionSink* sink);
		virtual ~VisionManager();
		int Run();
	};
}
