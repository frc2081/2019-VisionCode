#pragma once

#include "VisionSink.h"
#include "VisionConfiguration.h"
#include <netinet/in.h>

namespace Icarus
{
	class UdpSink : public VisionSink
	{
  private:
    VisionConfiguration* _config;
    int _socket;
    int _opt;
    struct sockaddr_in _address;

	protected:
		void Init();
		void Clean();
		void Sink(ImageData* source);
    void OpenSocket();
    void BindSocket();
    void CloseSocket();

	public:
		UdpSink(VisionConfiguration* config);
    bool OpensWindow();
	};
}
