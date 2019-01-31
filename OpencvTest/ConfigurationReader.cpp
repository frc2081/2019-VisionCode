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
		double scale;
		int cameraIndex;

		if (argc < 3)
			return 1;
		
		scale = atof(argv[1]);
		cameraIndex = atoi(argv[2]);

		// TODO: Actually implement this.
		*config = new VisionConfiguration(cameraIndex);
		return 0;
	}

	void ConfigurationReader::DisplayUsage(char** argv)
	{
		printf("Usage: '%s' SCALE CAMERAINDEX", argv[0]);
	}
}
