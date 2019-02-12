// OpencvTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "VisionManagerFactory.h"

using namespace Icarus;

int main(int argc, char** argv)
{
	int rtn;

	VisionManager* manager;
	VisionManagerFactory* factory = new VisionManagerFactory(argc, argv);

	manager = factory->Manager();
	
	manager->Initialize();
	rtn = manager->Run();
	manager->Close();
	
	delete factory;
	return rtn;	
}

