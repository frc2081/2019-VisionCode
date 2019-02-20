#include "stdafx.h"
#include "ConfigurationReader.h"
#include <stdio.h>
#include <unistd.h>
#include <libgen.h>

using namespace std;

namespace Icarus
{
	ConfigurationReader::ConfigurationReader()
	{
	}

#define SET_DEFAULT_CONFIG_VALUES()                           \
  hueLow = DEFAULT_LOW_HUE;                                   \
  hueHigh = DEFAULT_HIGH_HUE;                                 \
  satLow = DEFAULT_LOW_SAT;                                   \
  satHigh = DEFAULT_HIGH_SAT;                                 \
  lumLow = DEFAULT_LOW_LUM;                                   \
  lumHigh = DEFAULT_HIGH_LUM;                                 \
  sinkType = DEFAULT_SINK_TYPE;                               \
  sourceType = DEFAULT_SOURCE_TYPE;                           \
  filterTypes = GetFilterTypes((char*) DEFAULT_FILTER_TYPES); \
  cameraIndex = DEFAULT_CAMERA_INDEX;                         \
  testImage = DEFAULT_TEST_IMAGE;                             \
  exposure = DEFAULT_EXPOSURE;

	int ConfigurationReader::Read(int argc, char ** argv, VisionConfiguration ** config)
	{
    string testImage;
		SourceTypes sourceType;
    SinkTypes sinkType;
    FilterTypes filterTypes;
		int cameraIndex;
		int hueLow, hueHigh,
			satLow, satHigh,
			lumLow, lumHigh;
    double exposure;

    SET_DEFAULT_CONFIG_VALUES();

    int c;
    const char* optstr = ":c:s:k:f:e:v:i:h";
    while ((c = getopt(argc, argv, optstr)) != -1)
      switch(c)
      {
        case 'c':
          cameraIndex = GetCameraIndex(optarg);
          break;

        case 's':
          sourceType = GetSourceType(optarg);
          break;

        case 'k':
          sinkType = GetSinkType(optarg);
          break;

       case 'f':
          filterTypes = GetFilterTypes(optarg);
          break;

        case 'v':
          GetHslValues(optarg,
              &hueLow, &hueHigh,
              &satLow, &satHigh,
              &lumLow, &lumHigh);
          break;

        case 'e':
          exposure = GetExposure(optarg);
          break;

        case 'i':
          testImage = optarg;
          sourceType = TestSourceType;
          break;

        case 'h':
          return HELP_CODE;
      }

		*config = new VisionConfiguration(cameraIndex,
      sourceType, sinkType, filterTypes,
			hueLow, hueHigh,
			satLow, satHigh,
			lumLow, lumHigh,
			exposure, testImage);

		return ValidateConfiguration(*config);
	}

  int ConfigurationReader::GetCameraIndex(char* optarg)
  {
    return atoi(optarg);
  }

  SourceTypes ConfigurationReader::GetSourceType(char* optarg)
  {
    switch (*optarg)
    {
      case 'C':
        return CameraSourceType;

      case 'R':
        return RawCameraSourceType;

      case 'T':
        return TestSourceType;

      default:
        return UnknownSourceType;
    }
  }

  SinkTypes ConfigurationReader::GetSinkType(char* optarg)
  {
    switch (*optarg)
    {
      case 'C':
        return CameraDisplayType;

      case 'T':
        return CommandLineType;

      case 'W':
        return NetworkTablesType;

      default:
        return UnknownSinkType;
    }
  }

  FilterTypes ConfigurationReader::GetFilterTypes(char* optarg)
  {
    FilterTypes types = NoFilterTypes;
    for(int i=0; optarg[i] != 0; i++)
      types = (FilterTypes) (types | GetFilterType(optarg[i]));

    return types;
  }


  FilterTypes ConfigurationReader::GetFilterType(char filter)
  {
    switch(filter)
    {
      case 'T':
        return TargetType;

      case 'P':
        return TargetPairType;

      case 'C':
        return ContourDrawingType;

      default:
        return NoFilterTypes;
    }
  }


  void ConfigurationReader::GetHslValues(char* optarg,
      int* hueLow, int* hueHigh,
      int* satLow, int* satHigh,
      int* lumLow, int* lumHigh)
  {
    sscanf(optarg, "%d,%d,%d,%d,%d,%d",
        hueLow, hueHigh,
        satLow, satHigh,
        lumLow, lumHigh);
  }

  double ConfigurationReader::GetExposure(char* optarg)
  {
    return atof(optarg);
  }

	void ConfigurationReader::DisplayUsage(char** argv)
	{
    char* bin = basename(argv[0]);
    printf("Usage: '%s' [-c CAMERA_INDEX] [-s SOURCE_TYPE] [-k SINK_TYPE] [-f FILTER_TYPES]\n"
           "            [-v HSV_VALUES] [-e EXPOSURE] [-i TEST_IMAGE] [-h]\n\n"
  "   -c CAMERA_INDEX     Index of camera to use.  (Default: %d)\n\n"
  "   -s SOURCE_TYPE      Which source to use (Default: Camera Source):\n"
  "                         'C' Camera Source\n"
  "                         'R' Raw Camera Source\n"
  "                         'T' Test Source\n\n"
  "   -k SINK_TYPE        Which sink to use (Default: Network Tables):\n"
  "                         'C' Camera Display\n"
  "                         'T' Command Line\n"
  "                         'W' Network Tables\n\n"
  "   -f FILTER_TYPES     Filters to apply (Default: '%s')\n"
  "                         'T' Target Filter           - Limits contours to target shapes.\n"
  "                         'P' Target Pair Filter      - Limits contours to a target pair.\n"
  "                         'C' Contour Drawing Filter  - Draws contours on final image.\n\n"
  "   -v HSV_VALUES       HSV Values, comma separated.\n"
  "                         Ex: %d,%d,%d,%d,%d,%d\n\n"
  "   -e EXPOSURE         Exposure setting for camera (Default: %0.2f)\n\n"
  "   -i TEST_IMAGE       Uses TEST_IMAGE as the source for a test source.\n\n"
  "   -h                  Prints this help information.\n",
    bin,
    DEFAULT_CAMERA_INDEX,
    DEFAULT_FILTER_TYPES,
    DEFAULT_LOW_HUE,
    DEFAULT_HIGH_HUE,
    DEFAULT_LOW_SAT,
    DEFAULT_HIGH_SAT,
    DEFAULT_LOW_LUM,
    DEFAULT_HIGH_LUM,
    DEFAULT_EXPOSURE);
	}

  int ConfigurationReader::ValidateConfiguration(VisionConfiguration* config)
  {
    return 0;
  }
}
