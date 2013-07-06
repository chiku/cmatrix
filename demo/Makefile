# Written by     : Chirantan Mitra

CC = g++
AR = ar
CFLAGS += -O2
CXXFLAGS += -O2

INCLUDE_FILES += -I.
INCLUDE_FILES += -I../matrix

CXXFLAGS += -I$(INCLUDE_FILES)

CPPFILES := $(wildcard *.cpp)
DEMOFILES := $(CPPFILES:%.cpp=%)

all: compile run

compile: $(DEMOFILES)

run:
	mkdir -p ../bin/demo/
	mv *_demo ../bin/demo/
	./launch

io_demo:
	$(CXX) $(CXXFLAGS) -o io_demo io_demo.cpp

clean:
	rm -rf *.o *.a

.PHONY: all clean compile run
