// OpencvTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "VisionManager.h"
#include "VisionConfiguration.h"
#include "ConfigurationReader.h"
#include "CameraSource.h"
#include "CameraDisplay.h"

using namespace Icarus;

int main(int argc, char** argv)
{
	int rtn;
	VisionConfiguration *config;
	ConfigurationReader reader;

	if (rtn = reader.Read(argc, argv, &config))
	{
		reader.DisplayUsage(argv);
		return rtn;
	}

	// TODO: Create a factory, and add window name as parameter to configuration.
	CameraDisplay sink("camera");
	CameraSource source(config->GetScale(), config->GetCameraIndex());
	VisionManager manager(config, &source, &sink);

	manager.Initialize();
	rtn = manager.Run();
	manager.Close();
	
	delete config;
	return rtn;	
}

