# Written by     : Chirantan Mitra

ifndef CC
CC = gcc
endif

ifndef CXX
CXX = g++
endif

ifndef AR
AR = ar
endif

ifndef LCOV
LCOV = lcov
endif

ifndef GENHTML
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
	rm -rf bin/* coverage *.info
	@cd matrix && make clean
	@cd test && make clean
	@cd demo && make clean

coverage: CXXFLAGS += --coverage
coverage: LDFLAGS += --coverage
coverage: compile test generate.coverage.report

generate.coverage.report:
	${LCOV} --capture --directory test --output-file coverage.info
	${LCOV} --extract coverage.info "${PWD}/matrix/*" -o coverage.filtered.info
	${GENHTML} coverage.filtered.info --output-directory coverage

.PHONY: all compile test demo clean coverage generate.coverage.report
