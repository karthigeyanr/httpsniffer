

SOURCES=src/*.c
INCLUDES=-I./include
CFLAGS=-D__LITTLE_ENDIAN_BITFIELD
EXE=sniffer


all:
	$(CC) $(INCLUDES) $(CFLAGS) -o $(EXE) $(SOURCES)

clean:
	rm -f $(EXE)
