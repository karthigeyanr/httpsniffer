
#include <stdlib.h>
#include <string.h>
#include "PacketList.hpp"

vector<Packet> PacketList::packetList;

PacketList::PacketList()
{
}

int PacketList::addPacket(void *data, int len)
{
	Packet packet;
	packet.data = malloc(len);
	memmove(packet.data, data, len);
	packet.len = len;
	PacketList::packetList.push_back(packet);
}
