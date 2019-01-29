#pragma once

#include "VisionSink.h"

namespace Icarus
{
	class CameraDisplay : public VisionSink
	{
	protected:
		const char* _windowName;

		void Init();
		void Clean();
		void Sink(ImageData* source);

	public:
		CameraDisplay(const char* windowName);
	};
}