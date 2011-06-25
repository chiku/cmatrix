# Written by     : Chirantan Mitra

CC = gcc
AR = ar
CFLAGS += -O2
CXXFLAGS += -O2

INCLUDE_FILES += -I.
INCLUDE_FILES += -I../src

CPPFILES = $(shell ls -R *_demo.cpp)

all: compile run

compile:
	$(CXX) $(CXXFLAGS) -c $(INCLUDE_FILES) $(CPPFILES) `freetype-config --cflags`
	$(CXX) $(CXXFLAGS) -o demo *_demo.o ../bin/libpngwriter.a -lfreetype -lpng -lz

run:
	mv demo ../bin/demo
	@cd ../bin && ./demo

clean:
	rm -f *.o *.a *test *demo

.PHONY: all clean

