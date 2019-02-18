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
    std::vector<VisionFilter*>* _filters;

	protected:
		void Init();
		void Clean();

	public:
		VisionManager(VisionConfiguration* config, VisionSource* source, VisionSink* sink, std::vector<VisionFilter*>* filters);
		virtual ~VisionManager();
		int Run();
	};
}
