#pragma once

#include "VisionSink.h"
#include "VisionConfiguration.h"
#include <netinet/in.h>

#define SERVER_BUFFER_SIZE 1024

namespace Icarus
{
	class UdpSink : public VisionSink
	{
  private:
    VisionConfiguration* _config;
    int _socket;
    int _opt;
    struct sockaddr_in _address, _client;
    unsigned char _clientBuffer[SERVER_BUFFER_SIZE];

	protected:
		void Init();
		void Clean();
		void Sink(ImageData* source);
    void OpenSocket();
    void BindSocket();
    void WaitForClient();
    void CloseSocket();

	public:
		UdpSink(VisionConfiguration* config);
    bool OpensWindow();
	};
}
