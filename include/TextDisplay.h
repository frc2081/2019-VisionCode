#pragma once

#include "VisionSink.h"

namespace Icarus
{
	class TextDisplay : public VisionSink
	{
	private:

	protected:
		void Init();
		void Clean();
		void Sink(ImageData* source);
    virtual void PrintContour(Contour contour);

	public:
		TextDisplay();
	};
}
