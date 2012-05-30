# Written by     : Chirantan Mitra

ifndef CC
CC = gcc
endif

ifndef CXX
CXX = g++
endif

ifndef ar
AR = ar
endif

CFLAGS += -O2

CXXFLAGS += -O2

export CC
export CXX
export AR
export CFLAGS
export CXXFLAGS

all: clean compile test demo

compile:
	@cd src && make

test:
	@cd test && make

demo:
	@cd demo && make

clean:
	rm -rf bin/*
	@cd src && make clean
	@cd test && make clean
	@cd demo && make clean

.PHONY: all compile test demo clean
