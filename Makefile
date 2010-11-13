# Written by     : Chirantan Mitra

CC = gcc
AR=ar
CFLAGS += -O2
CXXFLAGS += -O2


all: clean sources tests

sources:
	@cd src && make

tests:
	@cd test && make

clean:
	rm -f bin/*
	@cd src && make clean
	@cd test && make clean

install: all
	mkdir -p bin

.PHONY: all clean install

