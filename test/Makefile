# File           : Makefile
# Written by     : Chirantan Mitra
# Created        : 29/03/2009
# Last modified  : 29/03/2009

CC = gcc
AR = ar
CFLAGS += -O2
CXXFLAGS += -O2

INCLUDE_FILES += -I.
INCLUDE_FILES += -I../src

CPPFILES = $(shell ls matrix_*_test.cpp)

run.all: run.test run.demo

all: clean matrix_test matrix_demo

run.test: matrix_test
	./matrix_test

run.demo: matrix_demo
	./matrix_io_demo

matrix_test: clean test_suite.o
	$(CXX) -c $(CXXFLAGS) $(INCLUDE_FILES) $(CPPFILES)
	$(CXX) -o matrix_test matrix_*_test.o test_suite.o -lstdc++ -lcppunit -ldl

test_suite.o:
	$(CXX) $(CXXFLAGS) -c test_suite.cpp

matrix_demo: clean matrix_io_demo

matrix_io_demo:
	$(CXX) $(CXXFLAGS) -c $(INCLUDE_FILES) matrix_io_demo.cpp  `freetype-config --cflags`
	$(CXX) $(CXXFLAGS) -o matrix_io_demo matrix_io_demo.o ../src/libcmatrix.a -lpngwriter -lfreetype -lpng -lz


clean:
	rm -f *.o *.a *_test *_demo *.png

.PHONY: all clean

