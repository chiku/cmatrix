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

ifdef COVERAGE
CFLAGS += -O2
CXXFLAGS += -fprofile-arcs -ftest-coverage
LDFLAGS += -lgcov
endif

export CC
export CXX
export AR
export CFLAGS
export CXXFLAGS
export LDFLAGS

all: clean compile test demo

compile:
	@cd matrix && make

test:
	@cd test && make

demo:
	@cd demo && make

clean:
	rm -rf bin/*
	@cd matrix && make clean
	@cd test && make clean
	@cd demo && make clean

.PHONY: all compile test demo clean
