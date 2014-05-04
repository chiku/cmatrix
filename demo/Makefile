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
	mkdir -p ../build/
	mv *_demo ../build/
	./launch

io_demo:
	$(CXX) $(CXXFLAGS) -o io_demo io_demo.cpp $(LDFLAGS)

clean:
	rm -rf *.o *.a *.gcda *.gcno

.PHONY: all clean compile run
