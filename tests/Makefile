# Written by     : Chirantan Mitra

INCLUDE_FILES += -I.
INCLUDE_FILES += -I../src
INCLUDE_FILES += -Ivendor

CPPFILES = $(shell ls */*_test.cpp *_test.cpp)

all: compile run

compile: test_runner.o
	$(CXX) -c $(CXXFLAGS) $(INCLUDE_FILES) $(CPPFILES)
	$(CXX) -o matrix_test *_test.o test_runner.o -lstdc++ $(LDFLAGS) -ldl

run:
	mv matrix_test ../build/matrix_test
	@cd ../build && ./matrix_test

test_runner.o:
	$(CXX) $(CXXFLAGS) $(INCLUDE_FILES) -c test_runner.cpp

clean:
	rm -f *.o *.a *_test *_demo *.gcda *.gcno

.PHONY: all run compile clean
