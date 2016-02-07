

SOURCES=src/*.cpp
INCLUDES=-I./include
CFLAGS=-D__LITTLE_ENDIAN_BITFIELD
EXE=sniffer
LIBS=-lpthread


all:
	$(CXX) $(INCLUDES) $(CFLAGS) -o $(EXE) $(SOURCES) $(LIBS)

clean:
	rm -f $(EXE)
