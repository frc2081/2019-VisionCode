#include "stdafx.h"
#include "RawCameraSource.h"

namespace Icarus
{
	void RawCameraSource::Source(ImageData* data)
	{
		CameraSource::Source(data);
		data->SetImageData(GetRawImage());
	}

	RawCameraSource::RawCameraSource(int cameraIndex)
		: CameraSource(1.0, cameraIndex)
	{
	}
}
