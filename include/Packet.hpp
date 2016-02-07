
#ifndef PACKET_HPP
#define PACKET_HPP

#include <iostream>
#include <vector>
#include "ProtStack.hpp"

using namespace std;

class Packet
{
	private:

	public:
		vector<ProtStack> stack;
		void *data;
		int len;
		bool stackIdentified;
		Packet();

};

#endif
