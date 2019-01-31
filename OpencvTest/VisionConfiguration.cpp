#include "stdafx.h"
#include "VisionConfiguration.h"

Icarus::VisionConfiguration::VisionConfiguration(int cameraIndex, char sourceType)
{
	_cameraIndex = cameraIndex;
	_sourceType = sourceType;
}

int Icarus::VisionConfiguration::GetCameraIndex()
{
	return _cameraIndex;
}

char Icarus::VisionConfiguration::GetSourceType()
{
	return _sourceType;
}
