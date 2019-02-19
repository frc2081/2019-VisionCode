#pragma once

#include "VisionSource.h"
#include "ImageData.h"
#include "GripPipeline.h"

namespace Icarus
{
	class TestSource : public VisionSource
	{
	private:
		VisionConfiguration* _config;
		grip::GripPipeline* _pipeline;
    std::vector<Contour>* _contours;
		cv::Mat _testImage;

	protected:
		void Init();
		void Clean();
		virtual void Source(ImageData* data);
    void ReadTestImage();

	public:
		TestSource(VisionConfiguration* config);
	};
}
