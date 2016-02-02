
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <net/if.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/ip.h>

#include "protheaders.h"


int main(int argc, char *argv[])
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
		return -1;
	}

	memset(&ifr, 0, sizeof(ifr));
	strncpy(ifr.ifr_name, "lo", sizeof(ifr.ifr_name));
	if(setsockopt(sockfd, SOL_SOCKET, SO_BINDTODEVICE, &ifr, sizeof(ifr)) < 0)
	{
		perror("setsockopt");
		return -1;
	}

	while(1)
	{
		addrlen = sizeof(addr);
		datalen = recvfrom(sockfd, buffer, 10000, 0, &addr, &addrlen);
		printf("received %d bytes\n", datalen);
	}

	return 0;
}
