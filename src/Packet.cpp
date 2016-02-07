
#include "Packet.hpp"

Packet::Packet()
{
	data = NULL;
	len = 0;
	stackIdentified = false;
	stack.clear();
}
