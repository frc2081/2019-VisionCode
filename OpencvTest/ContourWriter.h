#pragma once

#include "VisionSink.h"


namespace Icarus
{
	class ContourWriter :public VisionSink {
	protected:
		void Init();
		void Clean();
		void Sink(ImageData* source);

	public:
		ContourWriter();

	private:
		VisionState GetState(ImageData* source);

	};

	enum VisionState
	{
		Unknown = 0,
		NoContoursDetected,
		OneContourDetected,
		TwoContoursDetected,
		TooManyContoursDetected
	};
	

	
}