# Written by     : Chirantan Mitra

INCLUDE_FILES += -I.
INCLUDE_FILES += -I../src

CPPFILES = $(shell ls */*_test.cpp *_test.cpp)

all: compile run

compile: test_runner.o
	$(CXX) -c $(CXXFLAGS) $(INCLUDE_FILES) $(CPPFILES)
	$(CXX) -o matrix_test *_test.o test_runner.o ../bin/libcmatrix.a -lstdc++ -ldl

run:
	mv matrix_test ../bin/matrix_test
	@cd ../bin && ./matrix_test

test_runner.o:
	$(CXX) $(CXXFLAGS) -c test_runner.cpp

test_suite_unconverted.o:
	$(CXX) $(CXXFLAGS) -c test_suite_unconverted.cpp

clean:
	rm -f *.o *.a *_test *_demo

.PHONY: all run compile clean
