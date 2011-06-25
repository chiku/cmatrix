# Written by     : Chirantan Mitra

CC = g++
AR = ar
CFLAGS += -O2
CXXFLAGS += -O2

INCLUDE_FILES += -I.
INCLUDE_FILES += -I../src

CXXFLAGS += -I$(INCLUDE_FILES)

CPPFILES := $(wildcard *.cpp)
DEMOFILES := $(CPPFILES:%.cpp=%)

all: compile run

compile: $(DEMOFILES)

run:
	mkdir -p ../bin/demo/
	mv *_demo ../bin/demo/
	./launch

png_demo:
	$(CXX) $(CXXFLAGS) `freetype-config --cflags` -o png_demo png_demo.cpp ../bin/libpngwriter.a -lfreetype -lpng -lz

clean:
	rm -rf *.o *.a *.png

.PHONY: all clean compile run

