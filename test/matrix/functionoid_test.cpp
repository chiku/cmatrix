// Written by     : Chirantan Mitra

#include "../doctest.h"

#include <matrix.h>

namespace cmatrix
{

class FunctionoidWithOneParameter
{
    public:
        double operator() (double x)
        {
            return x + 1.0;
        }
};

class FunctionoidWithTwoParameters
{
    public:
        double operator() (double x, double y)
        {
            return x + y;
        }
};

SCENARIO("cmatrix::Matrix<double> map") {
    GIVEN("matrix") {
        WHEN("mapped") {
            Matrix<double> matrix;
            matrix.setSize(2, 2);
            matrix(0, 0) = 1.0; matrix(0, 1) = 2.0;
            matrix(1, 0) = 3.0; matrix(1, 1) = 4.0;
            Matrix<double> result = matrix.map(new FunctionoidWithOneParameter);

            THEN("applied the mapping function to all elements of the matrix") {
                Matrix<double> expectedMatrix;
                expectedMatrix.setSize(2, 2);
                expectedMatrix(0, 0) = 2.0; expectedMatrix(0, 1) = 3.0;
                expectedMatrix(1, 0) = 4.0; expectedMatrix(1, 1) = 5.0;
                CHECK(result == expectedMatrix);
            }

            THEN("it does not mutate the original matrix") {
                Matrix<double> sameMatrix;
                sameMatrix.setSize(2, 2);
                sameMatrix(0, 0) = 1.0; sameMatrix(0, 1) = 2.0;
                sameMatrix(1, 0) = 3.0; sameMatrix(1, 1) = 4.0;
                CHECK(matrix == sameMatrix);
            }
        }
    }
}

SCENARIO("cmatrix::Matrix<double> fillByPosition") {
    GIVEN("matrix") {
        WHEN("filled by position") {
            Matrix<double> matrix;
            matrix.setSize(2, 2);
            Matrix<double> result = matrix.fillByPosition(new FunctionoidWithTwoParameters);

            Matrix<double> expectedMatrix;
            expectedMatrix.setSize(2, 2);
            expectedMatrix(0, 0) = 0.0; expectedMatrix(0, 1) = 1.0;
            expectedMatrix(1, 0) = 1.0; expectedMatrix(1, 1) = 2.0;

            THEN("it fills all elements of the matrix") {
                CHECK(result == expectedMatrix);                
            }

            THEN("it mutates the original matrix") {
                CHECK(matrix == expectedMatrix);
            }
        }

        WHEN("filled by position with shifted") {
            Matrix<double> matrix;
            matrix.setSize(3, 3);
            Matrix<double> result = matrix.fillByPosition(new FunctionoidWithTwoParameters, 1, 1);

            Matrix<double> expectedMatrix;
            expectedMatrix.setSize(3, 3);
            expectedMatrix(0, 0) = -2.0; expectedMatrix(0, 1) = -1.0; expectedMatrix(0, 2) = 0.0;
            expectedMatrix(1, 0) = -1.0; expectedMatrix(1, 1) =  0.0; expectedMatrix(1, 2) = 1.0;
            expectedMatrix(2, 0) =  0.0; expectedMatrix(2, 1) =  1.0; expectedMatrix(2, 2) = 2.0;

            THEN("it filles all elements of the matrix") {
                CHECK(result == expectedMatrix);
            }

            THEN("it mutates the original matrix") {
                CHECK(matrix == expectedMatrix);
            }
        }

        WHEN("filled by position with shift and scale") {
            Matrix<double> matrix;
            matrix.setSize(3, 3);
            Matrix<double> result = matrix.fillByPosition(new FunctionoidWithTwoParameters, 1, 1, 2.0, -3.0);

            Matrix<double> expectedMatrix;
            expectedMatrix.setSize(3, 3);
            expectedMatrix(0, 0) = 1.0; expectedMatrix(0, 1) = -2.0; expectedMatrix(0, 2) =  -5.0;
            expectedMatrix(1, 0) = 3.0; expectedMatrix(1, 1) =  0.0; expectedMatrix(1, 2) =  -3.0;
            expectedMatrix(2, 0) = 5.0; expectedMatrix(2, 1) =  2.0; expectedMatrix(2, 2) =  -1.0;

            THEN("it filles all elements of the matrix") {
                CHECK(result == expectedMatrix);
            }

            THEN("it mutates the original matrix") {
                CHECK(matrix == expectedMatrix);
            }
        }
    }
}

} // namespace cmatrix
