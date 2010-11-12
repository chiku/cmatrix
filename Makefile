# File           : Makefile
# Written by     : Chirantan Mitra
# Created        : 29/03/2009

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
	rm -f lib/*
	@cd src && make clean
	@cd test && make clean

install: all
	mkdir -p lib
	cp src/*.a lib/

.PHONY: all clean install

