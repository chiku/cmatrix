# Written by     : Chirantan Mitra

CC = gcc
CXX = g++
AR = ar
CFLAGS += -O2
CXXFLAGS += -O2

INCLUDE_FILES += .
CPPFILES = $(shell ls size/*.cpp)

all: prepare vendor compile

compile: libcmatrix.a

libcmatrix.a:
	$(CXX) -c $(CXXFLAGS) -I $(INCLUDE_FILES) $(CPPFILES) -o ../bin/obj/cmatrix.o
	$(AR) rcs ../bin/libcmatrix.a ../bin/obj/cmatrix.o

vendor:
	@cd vendor && make

prepare:
	mkdir -p ../bin/obj

clean:
	rm -f *.o *.a
	@cd vendor && make clean

.PHONY: all prepare compile clean vendor

