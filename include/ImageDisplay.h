#pragma once

#include "VisionSink.h"
#include "VisionConfiguration.h"
#include <string>

namespace Icarus
{
	class ImageDisplay : public VisionSink
	{
  private:
    std::string _imageName;
    VisionConfiguration* _config;

	protected:
		void Init();
		void Clean();
		void Sink(ImageData* source);

	public:
		ImageDisplay(VisionConfiguration* config);
    bool OpensWindow();
	};
}
