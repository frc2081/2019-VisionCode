#include "stdafx.h"
#include "VisionSource.h"

namespace Icarus
{
	void VisionSource::GetImageData(ImageData * data)
	{
		AssertInitialized();
		Source(data);
	}
}
