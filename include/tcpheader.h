
#ifndef TCPHEADER_H
#define TCPHEADER_H

typedef struct tcpheader
{
	uint16_t srcport;
	uint16_t destport;
	uint32_t seqno;
	uint32_t ackno;
#if defined(__LITTLE_ENDIAN_BITFIELD)
	uint8_t ns:1;
	uint8_t resv:3;
	uint8_t doff:4;
	uint8_t fin:1;
	uint8_t syn:1;
	uint8_t rst:1;
	uint8_t psh:1;
	uint8_t ack:1;
	uint8_t urg:1;
	uint8_t ece:1;
	uint8_t cwr:1;
#elif defined(__BIG_ENDIAN_BITFIELD)
	uint8_t doff:4;
	uint8_t resv:3;
	uint8_t ns:1;
	uint8_t cwr:1;
	uint8_t ece:1;
	uint8_t urg:1;
	uint8_t ack:1;
	uint8_t psh:1;
	uint8_t rst:1;
	uint8_t syn:1;
	uint8_t fin:1;
#else
#error "Byte Order Error"
#endif
	uint16_t window;
	uint16_t checksum;
	uint16_t urgptr;
}__attribute__((packed))tcpheader_t;


#endif
