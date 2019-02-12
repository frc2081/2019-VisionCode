#include "stdafx.h"
#include "VisionManagerFactory.h"
#include "ConfigurationReader.h"

#include "CameraSource.h"
#include "CameraDisplay.h"
#include "RawCameraSource.h"
#include "ContourWriter.h"

namespace Icarus
{
	VisionManager * VisionManagerFactory::BuildManager()
	{
		return new VisionManager(Config(), Source(), Sink());
	}

	VisionSource * VisionManagerFactory::BuildSource()
	{
		char sourceType;
		VisionConfiguration* config = Config();

		sourceType = config->GetSourceType();

		return sourceType == 'r'
			? new RawCameraSource(config)
			: new CameraSource(config);
	}

	VisionSink * VisionManagerFactory::BuildSink()
	{
		char sinkType;
		VisionConfiguration* config = Config();

		sinkType = config->GetSourceType();

		return sinkType == 'w'
		 ? (VisionSink*) new ContourWriter()
		 : new CameraDisplay("camera");
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
	}


#define FACT_CLEAN(ptr) if (ptr != NULL) delete ptr;
	VisionManagerFactory::~VisionManagerFactory()
	{
		delete _config;
		FACT_CLEAN(_manager);
		FACT_CLEAN(_source);
		FACT_CLEAN(_sink);
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

	VisionConfiguration * VisionManagerFactory::Config()
	{
		return _config;
	}
}
