
#ifndef SNIFFER_HPP
#define SNIFFER_HPP

#include <iostream>
#include <pthread.h>

using namespace std;

class Sniffer
{
	private:
		pthread_t tid;
		pthread_mutex_t mutex;
		pthread_cond_t cond;

	public:
		Sniffer();
		int startCapturing();
		static void* capturePackets(void *arg);
};

#endif
