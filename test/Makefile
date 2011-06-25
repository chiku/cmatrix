# Written by     : Chirantan Mitra

CC = gcc
AR = ar
CFLAGS += -O2
CXXFLAGS += -O2

INCLUDE_FILES += -I.
INCLUDE_FILES += -I../src

CPPFILES = $(shell ls */*_test.cpp *_test.cpp)

all: compile run

compile: test_suite.o
	$(CXX) -c $(CXXFLAGS) $(INCLUDE_FILES) $(CPPFILES)
	$(CXX) -o matrix_test *_test.o test_suite.o -lstdc++ -lcppunit -ldl

run:
	mv matrix_test ../bin/matrix_test
	@cd ../bin && ./matrix_test

test_suite.o:
	$(CXX) $(CXXFLAGS) -c test_suite.cpp

clean:
	rm -f *.o *.a *_test *_demo

.PHONY: all run compile clean

