// Written by     : Chirantan Mitra

#include "../doctest.h"

#include <matrix.h>

namespace cmatrix
{

SCENARIO("cmatrix::Matrix<double> equality with tolerance") {
    GIVEN("matrix of doubles") {
        WHEN("compared with a matrix with different number of rows") {
            Matrix<double> oneByTwoMatrix(1, 2);
            Matrix<double> twoByTwoMatrix(2, 2);

            THEN("the matrices are unequal") {
                CHECK_FALSE(oneByTwoMatrix.equalWithTolerance(twoByTwoMatrix, 0.1));
            }
        }

        WHEN("compared with a matrix with different number of columns") {
            Matrix<double> oneByTwoMatrix(1, 2);
            Matrix<double> oneByThreeMatrix(1, 3);

            THEN("the matrices are unequal") {
                CHECK_FALSE(oneByTwoMatrix.equalWithTolerance(oneByThreeMatrix, 0.1));
            }
        }

        WHEN("compared with a matrix with same number of rows and columns and one element outside tolerance") {
            Matrix<double> firstTwoByTwoMatrix(2, 2);
            Matrix<double> secondTwoByTwoMatrix(2, 2);

            firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) =  1.0;
            firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) =  2.0;
            firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = -3.0;
            firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) =  4.0;

            THEN("the matrices are unequal") {
                CHECK_FALSE(firstTwoByTwoMatrix.equalWithTolerance(secondTwoByTwoMatrix, 0.1));
            }
        }

        WHEN("compared with a matrix with same number of rows and columns and all elements in same position equal") {
            Matrix<double> firstTwoByTwoMatrix(2, 2);
            Matrix<double> secondTwoByTwoMatrix(2, 2);

            firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) = 1.0;
            firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) = 2.0;
            firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = 3.0;
            firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) = 4.0;

            THEN("the matrices are equal") {
                CHECK(firstTwoByTwoMatrix.equalWithTolerance(secondTwoByTwoMatrix, 0.1));
            }
        }

        WHEN("compared with a matrix with same number of rows and columns and all elements different within given tolerance") {
            Matrix<double> firstTwoByTwoMatrix(2, 2);
            Matrix<double> secondTwoByTwoMatrix(2, 2);

            firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) = 1.0;
            firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) = 1.95;
            firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = 3.05;
            firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) = 4.0;

            THEN("the matrices are equal") {
                CHECK(firstTwoByTwoMatrix.equalWithTolerance(secondTwoByTwoMatrix, 0.1));
            }
        }
    }
}

} // namespace cmatrix
