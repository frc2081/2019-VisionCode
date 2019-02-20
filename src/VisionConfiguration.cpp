#include "stdafx.h"
#include "VisionConfiguration.h"

using namespace std;

namespace Icarus
{
  VisionConfiguration::VisionConfiguration(int cameraIndex,
      SourceTypes sourceType, SinkTypes sinkType, FilterTypes filterTypes,
      int hueLow, int hueHigh, int satLow, int satHigh, int lumLow, int lumHigh,
      double exposure, string testImage)
  {
    _cameraIndex = cameraIndex;
    _sourceType = sourceType;
    _sinkType = sinkType;
    _filterTypes = filterTypes;

    _hueLow = hueLow;
    _hueHigh = hueHigh;

    _satLow = satLow;
    _satHigh = satHigh;

    _lumLow = lumLow;
    _lumHigh = lumHigh;

    _exposure = exposure;
    _testImage = testImage;
  }

  int VisionConfiguration::GetCameraIndex()
  {
    return _cameraIndex;
  }

  SourceTypes VisionConfiguration::GetSourceType()
  {
    return _sourceType;
  }

  SinkTypes VisionConfiguration::GetSinkType()
  {
    return _sinkType;
  }

  FilterTypes VisionConfiguration::GetFilterTypes()
  {
    return _filterTypes;
  }

  int VisionConfiguration::GetHueLow()
  {
    return _hueLow;
  }

  int VisionConfiguration::GetHueHigh()
  {
    return _hueHigh;
  }

  int VisionConfiguration::GetSatLow()
  {
    return _satLow;
  }

  int VisionConfiguration::GetSatHigh()
  {
    return _satHigh;
  }

  int VisionConfiguration::GetLumLow()
  {
    return _lumLow;
  }

  int VisionConfiguration::GetLumHigh()
  {
    return _lumHigh;
  }

  double VisionConfiguration::GetExposure()
  {
    return _exposure;
  }

  string VisionConfiguration::GetTestImage()
  {
    return _testImage;
  }
}
