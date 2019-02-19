#include "stdafx.h"
#include "VisionConfiguration.h"

using namespace std;

namespace Icarus
{
  VisionConfiguration::VisionConfiguration(int cameraIndex, char sourceType, int hueLow, int hueHigh,
      int satLow, int satHigh, int lumLow, int lumHigh, double exposure, string share)
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
    _shareDir = share;
  }

  int VisionConfiguration::GetCameraIndex()
  {
    return _cameraIndex;
  }

  char VisionConfiguration::GetSourceType()
  {
    return _sourceType;
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

  string VisionConfiguration::GetShareDir()
  {
    return _shareDir;
  }
}
