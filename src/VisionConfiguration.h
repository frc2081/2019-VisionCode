#pragma once
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
		int _exposure;

	public:
		VisionConfiguration(int cameraIndex, char sourceType, int hueLow, int hueHigh,
		int satLow, int satHigh, int lumLow, int lumHigh, int exposure);

		int GetCameraIndex();
		char GetSourceType();

		int GetHueLow();
		int GetHueHigh();

		int GetSatLow();
		int GetSatHigh();

		int GetLumLow();
		int GetLumHigh();
		
		int GetExposure();
	};
}