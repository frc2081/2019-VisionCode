// OpencvTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "VisionManager.h"
#include "VisionConfiguration.h"
#include "ConfigurationReader.h"

using namespace Icarus;

int main(int argc, char** argv)
{
	int rtn;
	VisionConfiguration *config;
	ConfigurationReader reader;

	if (rtn = reader.Read(argc, argv, &config))
	{
		reader.DisplayUsage();
		return rtn;
	}

	VisionManager manager(config);
	rtn = manager.Run();
	
	delete config;
	return rtn;	
}

