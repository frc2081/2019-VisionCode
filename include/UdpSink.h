#pragma once

#include "VisionSink.h"
#include "VisionConfiguration.h"

namespace Icarus
{
	class UdpSink : public VisionSink
	{
  private:
    VisionConfiguration* _config;

	protected:
		void Init();
		void Clean();
		void Sink(ImageData* source);

	public:
		UdpSink(VisionConfiguration* config);
    bool OpensWindow();
	};
}
