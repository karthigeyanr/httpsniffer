

SOURCES=src/*.cpp
INCLUDES=-I./include
CFLAGS=-D__LITTLE_ENDIAN_BITFIELD
EXE=sniffer


all:
	$(CXX) $(INCLUDES) $(CFLAGS) -o $(EXE) $(SOURCES)

clean:
	rm -f $(EXE)
