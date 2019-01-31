#include "stdafx.h"
#include "VisionConfiguration.h"

Icarus::VisionConfiguration::VisionConfiguration(int cameraIndex)
{
	_cameraIndex = cameraIndex;
}

int Icarus::VisionConfiguration::GetCameraIndex()
{
	return _cameraIndex;
}
