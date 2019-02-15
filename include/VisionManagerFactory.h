#pragma once

#include "VisionManager.h"
#include "VisionSource.h"
#include "VisionSink.h"
#include "VisionConfiguration.h"

namespace Icarus
{
	class VisionManagerFactory
	{
	private:
		VisionConfiguration* _config;
		VisionManager* _manager;
		VisionSource* _source;
		VisionSink* _sink;
    VisionFilter* _filter;

	protected:
		virtual VisionManager* BuildManager();
		virtual VisionSource* BuildSource();
		virtual VisionSink* BuildSink();
    virtual VisionFilter* BuildFilter();

	public:
		VisionManagerFactory(int argc, char** argv);
		virtual ~VisionManagerFactory();

		VisionManager* Manager();
		VisionSource* Source();
		VisionSink* Sink();
    VisionFilter* Filter();
		VisionConfiguration* Config();
	};
}
