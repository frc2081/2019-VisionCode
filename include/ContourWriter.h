#pragma once

#include "VisionSink.h"
#include <networktables/NetworkTableInstance.h>
#include <networktables/NetworkTable.h>

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
    std::shared_ptr<nt::NetworkTable> GetNetworkTable();
    int GetHeartbeat();

	public:
		ContourWriter();
    bool OpensWindow();

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

    nt::NetworkTableInstance _networkTableInstance;
    std::shared_ptr<nt::NetworkTable> _networkTable;
    int _heartbeat;

		VisionState GetState(ImageData* source);
		
		ContourWriter::VisionTargetData GetTargetData(Contour contour, int ImageCenter);

		ContourWriter::VisionData GetVisionData(ImageData* source); 

		void WriteVisionData(VisionData Data);

		void GetTargetVectors(ImageData* source, Contour* Left, Contour* Right);

    void FlushData();
		
	};
}
