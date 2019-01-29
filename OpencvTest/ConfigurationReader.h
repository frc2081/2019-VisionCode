#pragma once

#include "VisionConfiguration.h"

namespace Icarus
{
	class ConfigurationReader
	{
	private:
	public:
		ConfigurationReader();
		int Read(int argc, char** argv, VisionConfiguration** config);
		void DisplayUsage(char** argv);
	};
}