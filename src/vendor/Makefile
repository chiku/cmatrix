# Written by     : Chirantan Mitra
# Created        : 23/11/2010

CC = gcc
CXX = g++
AR = ar
CFLAGS += -O2
CXXFLAGS += -O2

INCLUDE_FILES += .

all: libpngwriter.a

libpngwriter.a:
	@cd pngwriter && make
	cp pngwriter/libpngwriter.a ../../bin

clean:
	@cd pngwriter && make clean

.PHONY: all clean

