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

		if (argc < 3)
			return 1;
		
		cameraIndex = atoi(argv[1]);
		sourceType = argv[2][0];

		// TODO: Actually implement this.
		*config = new VisionConfiguration(cameraIndex, sourceType);
		return 0;
	}

	void ConfigurationReader::DisplayUsage(char** argv)
	{
		printf("Usage: '%s' CAMERAINDEX SOURCETYPE\n\tCAMERAINDEX:  The index of the webcam to use.\n\tSOURCETYPE:   The type of source ('r' for raw, 'm' for masked.)\n", argv[0]);
	}
}
