#include "stdafx.h"
#include "UdpSink.h"

using namespace cv;
using namespace std;

namespace Icarus
{
	void UdpSink::Init()
	{
	}

	void UdpSink::Clean()
	{
	}

	UdpSink::UdpSink(VisionConfiguration* config)
	{
    _config = config;
	}

	void UdpSink::Sink(ImageData * source)
	{
	}

  bool UdpSink::OpensWindow()
  {
    return false;
  }
}
