#pragma once
namespace Icarus
{
	class VisionConfiguration
	{
	private:
		double _scale;
		int _cameraIndex;

	public:
		VisionConfiguration(double scale, int cameraIndex);

		double GetScale();
		int GetCameraIndex();
	};
}