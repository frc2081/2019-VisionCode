#include "stdafx.h"
#include "VisionManagerFactory.h"
#include "ConfigurationReader.h"

#include "CameraSource.h"
#include "CameraDisplay.h"
#include "ImageDisplay.h"
#include "RawCameraSource.h"
#include "ContourWriter.h"
#include "UdpSink.h"
#include "TargetFilter.h"
#include "TargetPairFilter.h"
#include "ContourDrawingFilter.h"
#include "DataOverlayFilter.h"
#include "TextDisplay.h"
#include "TestSource.h"

using namespace std;

namespace Icarus
{
	VisionManager * VisionManagerFactory::BuildManager()
	{
		return new VisionManager(Config(), Source(), Sink(), Filters());
	}

	VisionSource * VisionManagerFactory::BuildSource()
	{
    SourceTypes sourceType;
		VisionConfiguration* config = Config();

		sourceType = config->GetSourceType();
    switch(sourceType)
    {
      case RawCameraSourceType:
        return new RawCameraSource(config);

      case TestSourceType:
        return new TestSource(config);

      default:
        return new CameraSource(config);
    }
	}

	VisionSink * VisionManagerFactory::BuildSink()
	{
		SinkTypes sinkType;
		VisionConfiguration* config = Config();

		sinkType = config->GetSinkType();
    switch (sinkType)
    {
      case CameraDisplayType:
        return new CameraDisplay("camera");

      case CommandLineType:
        return new TextDisplay();

      case ImageDisplayType:
        return new ImageDisplay(config);

      case UdpSinkType:
        return new UdpSink(config);
      
      default:
        return new ContourWriter();
    }
	}

#define ADD_FILTER(ftype, filterClass) if ((filterTypes & ftype) != 0) filters->push_back(new filterClass);
  vector<VisionFilter*>* VisionManagerFactory::BuildFilters()
  {
    vector<VisionFilter*>* filters = new vector<VisionFilter*>();
    VisionConfiguration* config = Config();
    FilterTypes filterTypes = config->GetFilterTypes();

    // Warning: The order in which filters are added is very important.
    ADD_FILTER(TargetType, TargetFilter);
    ADD_FILTER(TargetPairType, TargetPairFilter);
    ADD_FILTER(ContourDrawingType, ContourDrawingFilter);
    ADD_FILTER(DataOverlayType, DataOverlayFilter);

    return filters;
  }

	VisionManagerFactory::VisionManagerFactory(int argc, char ** argv)
	{
		ConfigurationReader reader;
		if (reader.Read(argc, argv, &_config))
		{
			reader.DisplayUsage(argv);
			throw "Failed to parse inputs.";
		}

		_manager = NULL;
		_source = NULL;
		_sink = NULL;
    _filters = NULL;
	}


#define FACT_CLEAN(ptr) if (ptr != NULL) delete ptr;
	VisionManagerFactory::~VisionManagerFactory()
	{
		delete _config;
		FACT_CLEAN(_manager);
		FACT_CLEAN(_source);
		FACT_CLEAN(_sink);

    if (_filters != NULL)
    {
      for(auto i = _filters->begin(); i != _filters->end(); i++)
        delete *i;

      delete _filters;
    }
	}

	VisionManager * VisionManagerFactory::Manager()
	{
		if (_manager == NULL)
			_manager = BuildManager();

		return _manager;
	}

	VisionSource * VisionManagerFactory::Source()
	{
		if (_source == NULL)
			_source = BuildSource();

		return _source;
	}

	VisionSink * VisionManagerFactory::Sink()
	{
		// TODO: Make this more configurable.
		if (_sink == NULL)
			_sink = BuildSink();

		return _sink;
	}

  vector<VisionFilter*>* VisionManagerFactory::Filters()
  {
    if (_filters == NULL)
      _filters = BuildFilters();

    return _filters;
  }

	VisionConfiguration * VisionManagerFactory::Config()
	{
		return _config;
	}
}
