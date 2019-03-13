#pragma once

#include <netinet/in.h>

#define SERVER_BUFFER_SIZE 1024
#define UDP_ADDR_FAM AF_INET
#define UDP_DATAGRAM SOCK_DGRAM

typedef struct sockaddr_in Address;
typedef struct sockaddr BaseAddress;
