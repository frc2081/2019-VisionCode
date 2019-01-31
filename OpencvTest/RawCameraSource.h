#pragma once

#include "CameraSource.h"
#include "VisionSource.h"

namespace Icarus
{
	class RawCameraSource : public CameraSource
	{
	protected:
		virtual void Source(ImageData* data);

	public:
		RawCameraSource(VisionConfiguration* config);
	};
}