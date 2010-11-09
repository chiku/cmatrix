// File           : matrix_io_demo.cpp
// Written by     : Chirantan Mitra
// Created        : 28/03/2009
// Last modified  : 29/03/2009

#include <matrix_implementation.cpp>
#include <matrix_io.cpp>

class testFunctionoid {
    public:
        double operator() (double x, double y) { 
            return (sin(x * y) + 1.0) / 2.0;
        }
};


class testRedScale {
    public:
        double operator() (double x, double y) { 
            return (sin(x + y) + 1.0) / 2.0;
        }
};

class testBlueScale {
    public:
        double operator() (double x, double y) { 
            return (sin(x * y) + 1.0) / 2.0;
        }
};

class testGreenScale {
    public:
        double operator() (double x, double y) { 
            return (sin(x - y) + 1.0) / 2.0;
        }
};

using namespace CMatrix;

int main()
{
    int size = 1001;
    Matrix<double> first300x300Matrix(size, size);
    Matrix<double> second300x300Matrix = first300x300Matrix.fillByPosition(new testFunctionoid, size/2, size/2, 1.0/size, 1.0/size);

    second300x300Matrix.pngize("test1.png", 0.3, 0.1, 0.4);
    second300x300Matrix.pngize("test2.png", (new testRedScale), (new testBlueScale), (new testGreenScale));    
}

