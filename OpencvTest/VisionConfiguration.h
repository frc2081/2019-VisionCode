#pragma once
namespace Icarus
{
	class VisionConfiguration
	{
	private:
		int _cameraIndex;

	public:
		VisionConfiguration(int cameraIndex);

		int GetCameraIndex();
	};
}