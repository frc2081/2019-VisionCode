#include "stdafx.h"
#include "ConfigurationReader.h"
#include <stdio.h>
#include <stdlib.h>

namespace Icarus
{
	ConfigurationReader::ConfigurationReader()
	{
	}

	int ConfigurationReader::Read(int argc, char ** argv, VisionConfiguration ** config)
	{
		char sourceType;
		int cameraIndex;
		int hueLow, hueHigh,
			satLow, satHigh,
			lumLow, lumHigh;

		double exposure;
		if (argc < 10)
			return 1;
		
		cameraIndex = atoi(argv[1]);
		sourceType = argv[2][0];

		hueLow = atoi(argv[3]);
		hueHigh = atoi(argv[4]);

		satLow = atoi(argv[5]);
		satHigh = atoi(argv[6]);

		lumLow = atoi(argv[7]);
		lumHigh = atoi(argv[8]);

		exposure = atof(argv[9]);

		// TODO: Actually implement this.
		*config = new VisionConfiguration(cameraIndex, sourceType,
			hueLow, hueHigh,
			satLow, satHigh,
			lumLow, lumHigh,
			exposure);
		return 0;
	}

	void ConfigurationReader::DisplayUsage(char** argv)
	{
		printf("Usage: '%s' CAMERAINDEX SOURCETYPE\n\tCAMERAINDEX:  The index of the webcam to use.\n\tSOURCETYPE:   The type of source ('r' for raw, 'm' for masked.)\n", argv[0]);
	}
}
