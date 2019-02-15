#pragma once
#include <opencv2/opencv.hpp>
#include "ImageData.h"
#include "GripPipeline.h"
#include "VisionConfiguration.h"
#include "VisionSink.h"
#include "VisionSource.h"
#include "IoEntity.h"
#include "VisionFilter.h"

namespace Icarus
{
	class VisionManager : public IoEntity
	{
	private:
		VisionConfiguration* _config;
		ImageData _imageData;
		VisionSource* _source;
		VisionSink* _sink;
    VisionFilter* _filter;

	protected:
		void Init();
		void Clean();

	public:
		VisionManager(VisionConfiguration* config, VisionSource* source, VisionSink* sink, VisionFilter* filter);
		virtual ~VisionManager();
		int Run();
	};
}
