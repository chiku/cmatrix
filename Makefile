# Written by     : Chirantan Mitra

CC ?= gcc
CXX ?= g++
AR ?= ar
LCOV ?= lcov
GENHTML ?= genhtml

CFLAGS += -O2
CXXFLAGS += -O2

INCLUDE_FILES += -I.
INCLUDE_FILES += -Isrc
TEST_INCLUDE_FILES += -Itests/vendor

TEST_OBJ_FILES = $(shell ls tests/*_test.cpp tests/*/*_test.cpp | sed 's/.cpp/.o/g')
DEMO_OBJ_FILES = $(shell ls demo/*_demo.cpp | sed 's/.cpp/.o/g')

all: test demo

test: tests/matrix_test
	./tests/matrix_test

demo: demo/io_demo
	./demo/io_demo

tests/matrix_test: ${TEST_OBJ_FILES} tests/test_runner.o
	$(CXX) $^ $(LDFLAGS) -o $@

demo/io_demo: demo/io_demo.o
	$(CXX) $^ $(LDFLAGS) -o $@

tests/%.o: tests/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE_FILES) $(TEST_INCLUDE_FILES) -c $< -o $@

demo/%.o: demo/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE_FILES) -c $< -o $@

coverage: CXXFLAGS += --coverage
coverage: LDFLAGS += --coverage
coverage: clean test generate.coverage.report

generate.coverage.report:
	${LCOV} --capture --directory tests --output-file coverage.info
	${LCOV} --extract coverage.info "${PWD}/src/*" -o coverage.filtered.info
	${GENHTML} coverage.filtered.info --output-directory coverage

clean:
	rm -rf ${TEST_OBJ_FILES} ${DEMO_OBJ_FILES} tests/test_runner.o tests/*_test demo/*_demo *.info coverage
	find . -name "*.gcda" -delete
	find . -name "*.gcno" -delete

.PHONY: all test demo clean coverage generate.coverage.report
