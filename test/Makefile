# Written by     : Chirantan Mitra

INCLUDE_FILES += -I.
INCLUDE_FILES += -I../src

# CPPFILES = $(shell ls */*_test.cpp *_test.cpp)
CPPFILES = size_test.cpp test_runner.cpp
CPPFILES_UNCONVERTED = matrix/base_test.cpp matrix/functionoid_test.cpp  matrix/numerical_test.cpp  matrix/properties_test.cpp

all: compile run

compile: test_suite.o
	$(CXX) -o matrix_test $(CXXFLAGS) $(INCLUDE_FILES) $(CPPFILES) ../bin/libcmatrix.a
	$(CXX) -c $(CXXFLAGS) $(INCLUDE_FILES) $(CPPFILES_UNCONVERTED)
	$(CXX) -o matrix_test_unconverted *_test.o test_suite.o ../bin/libcmatrix.a -lstdc++ -lcppunit -ldl

run:
	mv matrix_test ../bin/matrix_test
	mv matrix_test_unconverted ../bin/matrix_unconverted_test
	@cd ../bin && ./matrix_test && ./matrix_unconverted_test

test_suite.o:
	$(CXX) $(CXXFLAGS) -c test_suite.cpp

clean:
	rm -f *.o *.a *_test *_demo

.PHONY: all run compile clean

