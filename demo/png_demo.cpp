// Written by     : Chirantan Mitra

#define WITH_PNG

#include <matrix.h>

class testFunctionoid
{
    public:
        double operator() (double x, double y)
        {
            return (sin(x * y) + 1.0) / 2.0;
        }
};

class testRedScale
{
    public:
        double operator() (double x, double y)
        {
            return (3.0 * sin(x + y) + 1.0) / 2.0;
        }
};

class testBlueScale
{
    public:
        double operator() (double x, double y)
        {
            return (3.0 * sin(x * y) + 1.0) / 2.0;
        }
};

class testGreenScale
{
    public:
        double operator() (double x, double y)
        {
            return (3.0 * sin(x - y) + 1.0) / 2.0;
        }
};

using namespace CMatrix;

int main()
{
    int size = 301;
    Matrix<double> firstMatrix(size, size);
    Matrix<double> secondMatrix = firstMatrix.fillByPosition(new testFunctionoid, size/2, size/2, 1.0/size, 1.0/size);

    secondMatrix.pngize("test1.png", 0.3, 0.1, 0.4);
    secondMatrix.pngize("test2.png", (new testRedScale), (new testBlueScale), (new testGreenScale));
}
