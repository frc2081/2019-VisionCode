#include "stdafx.h"
#include "VisionConfiguration.h"

Icarus::VisionConfiguration::VisionConfiguration(int cameraIndex, char sourceType, int hueLow, int hueHigh, int satLow, int satHigh, int lumLow, int lumHigh, double exposure)
{
	_cameraIndex = cameraIndex;
	_sourceType = sourceType;

	_hueLow = hueLow;
	_hueHigh = hueHigh;

	_satLow = satLow;
	_satHigh = satHigh;

	_lumLow = lumLow;
	_lumHigh = lumHigh;

	_exposure = exposure;
}

int Icarus::VisionConfiguration::GetCameraIndex()
{
	return _cameraIndex;
}

char Icarus::VisionConfiguration::GetSourceType()
{
	return _sourceType;
}

int Icarus::VisionConfiguration::GetHueLow()
{
	return _hueLow;
}

int Icarus::VisionConfiguration::GetHueHigh()
{
	return _hueHigh;
}

int Icarus::VisionConfiguration::GetSatLow()
{
	return _satLow;
}

int Icarus::VisionConfiguration::GetSatHigh()
{
	return _satHigh;
}

int Icarus::VisionConfiguration::GetLumLow()
{
	return _lumLow;
}

int Icarus::VisionConfiguration::GetLumHigh()
{
	return _lumHigh;
}

double Icarus::VisionConfiguration::GetExposure()
{
	return _exposure;
}
