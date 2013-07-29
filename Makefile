# Written by     : Chirantan Mitra

ifndef CC
CC = gcc
endif

ifndef CXX
CXX = g++
endif

ifndef ar
AR = ar
endif

ifndef lcov
LCOV = lcov
endif

ifndef genhtml
GENHTML = genhtml
endif

CFLAGS += -O2
CXXFLAGS += -O2

export CC
export CXX
export AR
export CFLAGS
export CXXFLAGS
export LDFLAGS

all: clean compile test demo

compile:
	@cd matrix && make

test: compile
	@cd test && make

demo: compile
	@cd demo && make

clean:
	rm -rf bin/*
	@cd matrix && make clean
	@cd test && make clean
	@cd demo && make clean

coverage: CXXFLAGS += --coverage
coverage: LDFLAGS += --coverage
coverage: compile test generate.coverage.report

generate.coverage.report:
	$LCOV --capture --directory test --output-file coverage.info
	$GENHTML coverage.info --output-directory coverage

.PHONY: all compile test demo clean coverage set.coverage generate.coverage.report
