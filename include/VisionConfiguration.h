#pragma once

#include <string>

#define DEFAULT_EXPOSURE (double) 0
#define DEFAULT_CAMERA_INDEX 0

#define DEFAULT_SINK_TYPE NetworkTablesType
#define DEFAULT_SOURCE_TYPE CameraSourceType

#define DEFAULT_LOW_HUE 60
#define DEFAULT_HIGH_HUE 100
#define DEFAULT_LOW_SAT 200
#define DEFAULT_HIGH_SAT 255
#define DEFAULT_LOW_LUM 20
#define DEFAULT_HIGH_LUM 100
#define DEFAULT_TEST_IMAGE ""
#define DEFAULT_FILTER_TYPES "TPC"

namespace Icarus
{
  enum SourceTypes
  {
    UnknownSourceType = 0x0,
    CameraSourceType = 0x1,
    RawCameraSourceType = 0x2,
    TestSourceType = 0x3
  };

  enum SinkTypes
  {
    UnknownSinkType = 0x0,
    CameraDisplayType = 0x1,
    CommandLineType = 0x2,
    NetworkTablesType = 0x3
  };

  enum FilterTypes
  {
    NoFilterTypes = 0x0,
    TargetType = 0x1,
    TargetPairType = 0x2,
    ContourDrawingType = 0x4,
    AllFilterTypes = TargetType | TargetPairType | ContourDrawingType
  };

	class VisionConfiguration
	{
	private:
		int _cameraIndex;
		SourceTypes _sourceType;
    SinkTypes _sinkType;
    FilterTypes _filterTypes;
		int _hueLow, _hueHigh,
			_satLow, _satHigh,
			_lumLow, _lumHigh;
		double _exposure;
    std::string _testImage;

	public:
		VisionConfiguration(int cameraIndex,
        SourceTypes sourceType, SinkTypes sinkType, FilterTypes filterTypes,
        int hueLow, int hueHigh, int satLow, int satHigh, int lumLow, int lumHigh,
        double exposure, std::string testImage);

		int GetCameraIndex();
		SourceTypes GetSourceType();
    SinkTypes GetSinkType();
    FilterTypes GetFilterTypes();

		int GetHueLow();
		int GetHueHigh();

		int GetSatLow();
		int GetSatHigh();

		int GetLumLow();
		int GetLumHigh();
		
		double GetExposure();
    std::string GetTestImage();
	};
}
