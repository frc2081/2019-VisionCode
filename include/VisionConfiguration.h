#pragma once

#include <string>

namespace Icarus
{
	class VisionConfiguration
	{
	private:
		int _cameraIndex;
		char _sourceType;
		int _hueLow, _hueHigh,
			_satLow, _satHigh,
			_lumLow, _lumHigh;
		double _exposure;
    std::string _shareDir;

	public:
		VisionConfiguration(int cameraIndex, char sourceType, int hueLow, int hueHigh,
		int satLow, int satHigh, int lumLow, int lumHigh, double exposure, std::string share);

		int GetCameraIndex();
		char GetSourceType();

		int GetHueLow();
		int GetHueHigh();

		int GetSatLow();
		int GetSatHigh();

		int GetLumLow();
		int GetLumHigh();
		
		double GetExposure();
    std::string GetShareDir();
	};
}
