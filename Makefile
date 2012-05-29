# Written by     : Chirantan Mitra

CC = gcc
CXX = g++
AR=ar
CFLAGS += -O2
CXXFLAGS += -O2


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

