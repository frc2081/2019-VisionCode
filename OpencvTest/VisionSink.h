#pragma once

#include "ImageData.h"

namespace Icarus
{
	class VisionSink
	{
	public:
		virtual void Consume(ImageData* source) = 0;
	};
}