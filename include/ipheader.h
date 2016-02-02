
#ifndef IPHEADER_H
#define IPHEADER_H

typedef struct ipheader
{
#if defined(__LITTLE_ENDIAN_BITFIELD)
	uint8_t hlen:4;
	uint8_t version:4;
#elif defined(__BIG_ENDIAN_BITFIELD)
	uint8_t version:4;
	uint8_t hlen:4;
#else
#error "Byte Order Error"
#endif
	uint8_t tos;
	uint16_t totlen;
	uint16_t id;
#if defined(__LITTLE_ENDIAN_BITFIELD)
	uint16_t fragoff:13;
	uint8_t fragflag:3;
#elif defined(__BIG_ENDIAN_BITFIELD)
	uint8_t fragflag:3;
	uint16_t fragoff:13;
#else
#error "Byte Order Error"
#endif
	uint8_t ttl;
	uint8_t prot;
	uint16_t checksum;
	uint32_t srcaddr;
	uint32_t destaddr;
}__attribute__((packed))ipheader_t;



#endif
