// Written by     : Chirantan Mitra

#include <matrix.h>
#include <cmath>

class testFunctionoid
{
    public:
        double operator() (double x, double y)
        {
            return (sin(x * y) + 1.0) / 2.0;
        }
};


using namespace CMatrix;

int main()
{
    int size = 5;
    Matrix<double> matrix(size, size);
    matrix = matrix.fillByPosition(new testFunctionoid, size/2, size/2, 1.0/size, 1.0/size);
    std::cout << matrix;
}

