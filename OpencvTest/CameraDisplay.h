#pragma once

#include "VisionSink.h"

namespace Icarus
{
	class CameraDisplay : public VisionSink
	{
	private:
		bool _initialized;
		const char* _windowName;

		void Initialize();
		void Close();

	public:
		CameraDisplay(const char* windowName);
		void Consume(ImageData* source);
	};
}