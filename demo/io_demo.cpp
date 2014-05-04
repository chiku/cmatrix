// Written by     : Chirantan Mitra

#include <cmath>

#include "matrix.h"

class testFunctionoid
{
public:
    double operator() (double x, double y)
    {
        return (sin(x * y) + 1.0) / 2.0;
	}
};

int main()
{
    int size = 5;
    cmatrix::Matrix<double> matrix(size, size);
    matrix.fillByPosition(new testFunctionoid, size/2, size/2, 1.0/size, 1.0/size);
    std::cout << matrix << std::endl;
}
