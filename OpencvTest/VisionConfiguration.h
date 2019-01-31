#pragma once
namespace Icarus
{
	class VisionConfiguration
	{
	private:
		int _cameraIndex;
		char _sourceType;

	public:
		VisionConfiguration(int cameraIndex, char sourceType);

		int GetCameraIndex();
		char GetSourceType();
	};
}