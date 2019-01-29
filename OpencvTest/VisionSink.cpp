#include "stdafx.h"
#include "VisionSink.h"

namespace Icarus
{
	void VisionSink::Consume(ImageData * source)
	{
		AssertInitialized();
		Sink(source);
	}
}
