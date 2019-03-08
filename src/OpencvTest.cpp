// OpencvTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "VisionManagerFactory.h"
#include <errno.h>

using namespace Icarus;

int main(int argc, char** argv)
{
	int rtn;

  try
  {
    VisionManager* manager;
    VisionManagerFactory* factory = new VisionManagerFactory(argc, argv);

    manager = factory->Manager();

    manager->Initialize();
    rtn = manager->Run();
    manager->Close();

    delete factory;
  }
  catch(char const* error)
  {
    fprintf(stderr, "Error (%s): %s\n", strerror(errno), error);
    rtn = errno == 0
      ? 1
      : errno;
  }
	
	return rtn;	
}

