#include "UdpSettings.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <opencv2/opencv.hpp>

void ParseInput(int argc, char** argv, char** ip, int* port);

int OpenSocket();
void BindSocket(int socket, int port, Address* client);
void Connect(int socket, int port, char* serverIp, Address* client, Address* server);
void Receive(int socket, Address* client, Address* server);
void ReceiveImageData(int socket, Address* client, Address* server, cv::Mat* image);

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
  char* serverIp;
  int socket, port;
  Address client, server;

  try
  {
    ParseInput(argc, argv, &serverIp, &port);
    socket = OpenSocket();
    BindSocket(socket, port, &client);
    Connect(socket, port, serverIp, &client, &server);
    Receive(socket, &client, &server);
  }
  catch(char const* error)
  {
    fprintf(stderr, "Error (%s): %s\n", strerror(errno), error);
    return 1;
  }

  return 0;
}


int OpenSocket()
{
  int opt, sck;
  if ((sck = socket(UDP_ADDR_FAM, UDP_DATAGRAM, 0)) <0)
    throw "Failed to open socket.";

  if (setsockopt(sck, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    throw "Failed to set socket options.";

  return sck;
}

#define CLEAR_ADDRESS(addr) memset((char*) addr, 0, sizeof(*addr));
void BindSocket(int socket, int port, Address* client)
{
  CLEAR_ADDRESS(client);
  client->sin_family = UDP_ADDR_FAM;
  client->sin_addr.s_addr = htonl(INADDR_ANY);
  client->sin_port = htons(0);

  if(bind(socket, (BaseAddress*) client, sizeof(*client)) < 0)
    throw "Failed to bind socket to port.";
}

void Connect(int socket, int port, char* serverIp, Address* client, Address* server)
{
  CLEAR_ADDRESS(server);

  struct hostent *serverHost;

  serverHost = gethostbyname(serverIp);
  if(!serverHost)
    throw "Failed to get server by IP.";

  const char* message = "OPEN";
  server->sin_family = UDP_ADDR_FAM;
  server->sin_port = htons(port);
  if (inet_aton(serverIp, &server->sin_addr)==0)
    throw "Failed to set server IP.";

  //memcpy((void*) &server->sin_addr, serverHost->h_addr_list[0], serverHost->h_length);
  if (sendto(socket, message, strlen(message), 0, (BaseAddress*) server, sizeof(*server)) < 0 )
      throw "Failed to send.";
}

void Receive(int socket, Address* client, Address* server)
{
  for(;;)
    ReceiveImageData(socket, client, server, NULL);
}

void ReceiveImageData(int socket, Address* client, Address* server, Mat* image)
{
  int received;
  char serverBuffer[SERVER_BUFFER_SIZE];
  socklen_t serverSize = sizeof(*server);

  received = recvfrom(socket, serverBuffer, SERVER_BUFFER_SIZE, 0, (BaseAddress*) server, &serverSize);
  if (received <= 0)
    throw "Failed to receive.";

  serverBuffer[received] = 0;
  printf("Message from server: %s\n", serverBuffer);
}

void ParseInput(int argc, char** argv, char** ip, int* port)
{
  if (argc < 3)
    throw "Missing arguments.";

  *ip = argv[1];
  *port = atoi(argv[2]);
}
