#pragma once

#include "VisionSink.h"

namespace Icarus
{
	class CameraDisplay : public VisionSink
	{
	private:
		void Decorate(ImageData* source);

	protected:
		const char* _windowName;

		void Init();
		void Clean();
		void Sink(ImageData* source);

	public:
		CameraDisplay(const char* windowName);
	};
}