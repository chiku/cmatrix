# Written by     : Chirantan Mitra

INCLUDE_FILES += -I.
INCLUDE_FILES += -I../src

CPPFILES = $(shell ls */*_test.cpp *_test.cpp)
CPPFILES_UNCONVERTED = $(shell ls */*_test_unconverted.cpp)

all: compile run

compile: test_runner.o compile_unconverted
	$(CXX) -c $(CXXFLAGS) $(INCLUDE_FILES) $(CPPFILES)
	$(CXX) -o matrix_test *_test.o test_runner.o ../bin/libcmatrix.a -lstdc++ -ldl

compile_unconverted: test_suite_unconverted.o
	$(CXX) -c $(CXXFLAGS) $(INCLUDE_FILES) $(CPPFILES_UNCONVERTED)
	$(CXX) -o matrix_test_unconverted *_test_unconverted.o test_suite_unconverted.o ../bin/libcmatrix.a -lstdc++ -lcppunit -ldl

run:
	mv matrix_test ../bin/matrix_test
	mv matrix_test_unconverted ../bin/matrix_unconverted_test
	@cd ../bin && ./matrix_test && ./matrix_unconverted_test

test_runner.o:
	$(CXX) $(CXXFLAGS) -c test_runner.cpp

test_suite_unconverted.o:
	$(CXX) $(CXXFLAGS) -c test_suite_unconverted.cpp

clean:
	rm -f *.o *.a *_test *_demo

.PHONY: all run compile clean

