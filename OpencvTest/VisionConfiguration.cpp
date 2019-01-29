#include "stdafx.h"
#include "VisionConfiguration.h"

Icarus::VisionConfiguration::VisionConfiguration(double scale, int cameraIndex)
{
	_scale = scale;
	_cameraIndex = cameraIndex;
}

double Icarus::VisionConfiguration::GetScale()
{
	return _scale;
}

int Icarus::VisionConfiguration::GetCameraIndex()
{
	return _cameraIndex;
}
