# Written by     : Chirantan Mitra

CC = gcc
AR = ar
CFLAGS += -O2
CXXFLAGS += -O2

INCLUDE_FILES += -I.
INCLUDE_FILES += -I../src

all: compile run

compile:
	$(CXX) $(CXXFLAGS) -c $(INCLUDE_FILES) png_demo.cpp `freetype-config --cflags`
	$(CXX) $(CXXFLAGS) -o png_demo png_demo.o ../bin/libpngwriter.a -lfreetype -lpng -lz

run:
	mv png_demo ../bin/png_demo
	@cd ../bin && ./png_demo

clean:
	rm -f *.o *.a *_test *_demo

.PHONY: all clean

