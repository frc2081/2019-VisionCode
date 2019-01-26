#include "stdafx.h"
#include "ConfigurationReader.h"
#include <stdio.h>

namespace Icarus
{
	ConfigurationReader::ConfigurationReader()
	{
	}

	int ConfigurationReader::Read(int argc, char ** argv, VisionConfiguration ** config)
	{
		// TODO: Actually implement this.
		*config = new VisionConfiguration(1.0, 0);
		return 0;
	}

	void ConfigurationReader::DisplayUsage()
	{
		printf("This is not currently implemented.\n");
	}
}
