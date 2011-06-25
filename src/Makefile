# Written by     : Chirantan Mitra

CC = gcc
CXX = g++
AR = ar
CFLAGS += -O2
CXXFLAGS += -O2

INCLUDE_FILES += .

all: vendor

vendor:
	@cd vendor && make

clean:
	rm -f *.o *.a
	@cd vendor && make clean

.PHONY: all clean vendor

