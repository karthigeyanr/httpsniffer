
#ifndef ETHHDR_H
#define ETHHDR_H

#include <stdint.h>

#define MACADDR_LEN 6

typedef char MACADDR_T[MACADDR_LEN];

typedef struct ethheader
{
	MACADDR_T dest;
	MACADDR_T src;
	union
	{
		uint16_t type;
		uint16_t length;
	};
}__attribute__((packed))ethheader_t;

#endif
