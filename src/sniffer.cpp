
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <net/if.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/ip.h>

#include <vector>
#include <pthread.h>

#include "protheaders.h"
#include "PacketList.hpp"
#include "sniffer.hpp"

Sniffer::Sniffer()
{
}

int Sniffer::startCapturing()
{
	pthread_create(&tid, NULL, &Sniffer::capturePackets, (void *)"lo");
}

void* Sniffer::capturePackets(void *arg)
{
	int sockfd;
	struct sockaddr addr;
	struct ifreq ifr;
	socklen_t addrlen;
	char buffer[10000];
	ssize_t datalen;

	sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
	if(sockfd < 0)
	{
		perror("socket");
		pthread_exit(NULL);
	}

	memset(&ifr, 0, sizeof(ifr));
	strncpy(ifr.ifr_name, (char *)arg, sizeof(ifr.ifr_name));
	if(setsockopt(sockfd, SOL_SOCKET, SO_BINDTODEVICE, &ifr, sizeof(ifr)) < 0)
	{
		perror("setsockopt");
		pthread_exit(NULL);
	}

	while(1)
	{
		addrlen = sizeof(addr);
		datalen = recvfrom(sockfd, buffer, 10000, 0, &addr, &addrlen);
		printf("received %d bytes\n", datalen);

		if(datalen > 0)
		{
			PacketList::addPacket(buffer, datalen);
		}
	}

	pthread_exit(NULL);
}
