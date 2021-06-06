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

SOURCE_FILES = $(find src -name *.h  -o -name *.cpp)
TEST_OBJ_FILES = $(shell ls test/*_test.cpp test/*/*_test.cpp | sed 's/.cpp/.o/g')
DEMO_OBJ_FILES = $(shell ls demo/*_demo.cpp | sed 's/.cpp/.o/g')

prefix=/usr/local

all: test demo

compile:

test: build/bin/test/matrix_test
	./build/bin/test/matrix_test

demo: build/bin/demo/io_demo
	./build/bin/demo/io_demo

install: $(SOURCE_FILES)
	install -d 511 ${prefix}/include/cmatrix/impl/matrix/io
	install -d 511 ${prefix}/include/cmatrix/storage_engine
	for file in $$(find src -name *.h  -o -name *.cpp | sed "s/src\///") ; do \
		install -c -m 644 src/$$file $$(dirname ${prefix}/include/cmatrix/$$file) ;\
	done

build/bin/test/matrix_test: $(TEST_OBJ_FILES) test/test_runner.o
	mkdir -pv $(@D)
	$(CXX) $^ $(LDFLAGS) -o $@

build/bin/demo/io_demo: demo/io_demo.o
	mkdir -pv $(@D)
	$(CXX) $^ $(LDFLAGS) -o $@

test/%.o: test/%.cpp $(SOURCE_FILES)
	$(CXX) $(CXXFLAGS) $(INCLUDE_FILES) -c $< -o $@

demo/%.o: demo/%.cpp $(SOURCE_FILES)
	$(CXX) $(CXXFLAGS) $(INCLUDE_FILES) -c $< -o $@

coverage: CXXFLAGS += --coverage
coverage: LDFLAGS += --coverage
coverage: clean test generate.coverage.report

generate.coverage.report:
	$(LCOV) --capture --directory test --output-file coverage.info
	$(LCOV) --extract coverage.info "$(PWD)/src/*" -o coverage.filtered.info
	$(GENHTML) coverage.filtered.info --output-directory coverage

clean:
	rm -rf build/
	rm -rf $(TEST_OBJ_FILES) $(DEMO_OBJ_FILES) test/test_runner.o test/*_test demo/*_demo *.info coverage
	find . -name "*.gcda" -delete
	find . -name "*.gcno" -delete

.PHONY: all compile test demo install clean coverage generate.coverage.report
