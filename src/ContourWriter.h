#pragma once

#include "VisionSink.h"
#include <networktables/NetworkTableInstance.h>

namespace Icarus
{
	enum VisionState
	{
		Unknown = 0,
		NoContoursDetected,
		OneContourDetected,
		TwoContoursDetected,
		TooManyContoursDetected
	};

	class ContourWriter : public VisionSink {

	protected:
		void Init();
		void Clean();
		void Sink(ImageData* source);
    nt::NetworkTableInstance* GetNetworkTables();

	public:
		ContourWriter();

	private:
		class VisionTargetData {
		public:
			int TargetHeight;
			int TargetWidth;
			int TargetDistFromCenter;
			static ContourWriter::VisionTargetData BadData();

		};

		class VisionData {
		public:
			ContourWriter::VisionTargetData LeftTarget;
			ContourWriter::VisionTargetData RightTarget;
			bool IsValid;
			static ContourWriter::VisionData BadData();
		};

    nt::NetworkTableInstance _networkTables;

		VisionState GetState(ImageData* source);
		
		ContourWriter::VisionTargetData GetTargetData(std::vector<cv::Point> contour, int ImageCenter);

		ContourWriter::VisionData GetVisionData(ImageData* source); 

		void WriteVisionData(VisionData Data);
		
	};

	
	
}
