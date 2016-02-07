
#include <iostream>
#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "sniffer.hpp"
#include "PacketList.hpp"

using namespace std;

int main(int argc, char *argv[])
{
	Sniffer snfr;

	snfr.startCapturing();
	while(1)
	{
		cout<<"Packet Count : "<<PacketList::packetList.size()<<endl;
		sleep(1);
	}

	return 0;
}
