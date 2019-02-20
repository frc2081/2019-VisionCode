#pragma once

#include "VisionConfiguration.h"

#define HELP_CODE 99999

namespace Icarus
{
	class ConfigurationReader
	{
  protected:
    int GetCameraIndex(char* optarg);
    SourceTypes GetSourceType(char* optarg);
    SinkTypes GetSinkType(char* optarg);
    FilterTypes GetFilterTypes(char* optarg);
    FilterTypes GetFilterType(char filter);
    void GetHslValues(char* optarg,
        int* hueLow, int* hueHigh,
        int* satLow, int* satHigh,
        int* lumLow, int* lumHigh);
    double GetExposure(char* optarg);
    int ValidateConfiguration(VisionConfiguration* config);

	public:
		ConfigurationReader();
		int Read(int argc, char** argv, VisionConfiguration** config);
		void DisplayUsage(char** argv);
	};
}
