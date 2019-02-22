#include "stdafx.h"
#include "UdpSink.h"
#include <sys/socket.h>
#include <stdio.h>

using namespace cv;
using namespace std;

namespace Icarus
{
	void UdpSink::Init()
	{
    OpenSocket();
    BindSocket();
    WaitForClient();
	}

	void UdpSink::Clean()
	{
    CloseSocket();
	}

	UdpSink::UdpSink(VisionConfiguration* config)
	{
    _config = config;
    memset((char*) &_address, 0, sizeof(_address));
	}

  void UdpSink::OpenSocket()
  {
    _opt = 1;
    if ((_socket = socket(UDP_ADDR_FAM, UDP_DATAGRAM, 0)) < 0)
      throw "Failed to open socket.";

    if (setsockopt(_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &_opt, sizeof(_opt)))
      throw "Failed to set socket options.";
  }

  void UdpSink::BindSocket()
  {
    // TODO: Make this part of the configuration.
    const int port = 48458;

    _address.sin_family = UDP_ADDR_FAM;
    _address.sin_addr.s_addr = htonl(INADDR_ANY);
    _address.sin_port = htons(port);

    if (bind(_socket, (struct sockaddr*) &_address, sizeof(_address)) < 0)
      throw "Failed to bind socket to port.";
  }

  void UdpSink::WaitForClient()
  {
    int received;
    socklen_t clientSize = sizeof(_client);
    received = recvfrom(_socket, _clientBuffer, SERVER_BUFFER_SIZE, 0, (struct sockaddr *) &_client, &clientSize);
    if (received <= 0)
      throw "Failed to receive.";

    _clientBuffer[received] = 0;
    printf("Received from client: %s\n", _clientBuffer);
  }

  void UdpSink::CloseSocket()
  {
  }

	void UdpSink::Sink(ImageData * source)
	{
    const char* message = "From the server, yo.";

    if (sendto(_socket, message, strlen(message), 0, (BaseAddress*) &_client, sizeof(_client)) < 0 )
        throw "Failed to send.";

	}

  bool UdpSink::OpensWindow()
  {
    return false;
  }
}
