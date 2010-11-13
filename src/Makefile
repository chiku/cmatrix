# Written by     : Chirantan Mitra
# Created        : 29/03/2009

CC = gcc
CXX = g++
AR = ar
CFLAGS += -O2
CXXFLAGS += -O2

INCLUDE_FILES += .

all: libcmatrix.a vendor

libcmatrix.a:
	$(CXX) -c $(CXXFLAGS) -I $(INCLUDE_FILES) matrix_implementation.cpp -o cmatrix.o
	$(AR) rcs libcmatrix.a cmatrix.o
	cp libcmatrix.a ../bin

vendor:
	@cd vendor && make

clean:
	rm -f *.o *.a
	@cd vendor && make clean

.PHONY: all clean vendor

