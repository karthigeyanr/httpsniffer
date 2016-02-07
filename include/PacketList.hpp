
#ifndef PACKETLIST_HPP
#define PACKETLIST_HPP

#include <iostream>
#include <vector>
#include "Packet.hpp"

using namespace std;

class PacketList
{
	public:
		static vector<Packet> packetList;

		PacketList();
		static int addPacket(void *data, int len);

};


#endif
