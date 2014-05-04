# Written by     : Chirantan Mitra

CC ?= gcc
CXX ?= g++
AR ?= ar
LCOV ?= lcov
GENHTML ?= genhtml

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
	@cd src && make

test: compile
	@cd tests && make

demo: compile
	@cd demo && make

clean:
	rm -rf bin/* coverage *.info
	@cd src && make clean
	@cd tests && make clean
	@cd demo && make clean

coverage: CXXFLAGS += --coverage
coverage: LDFLAGS += --coverage
coverage: compile test generate.coverage.report

generate.coverage.report:
	${LCOV} --capture --directory tests --output-file coverage.info
	${LCOV} --extract coverage.info "${PWD}/src/*" -o coverage.filtered.info
	${GENHTML} coverage.filtered.info --output-directory coverage

.PHONY: all compile test demo clean coverage generate.coverage.report
