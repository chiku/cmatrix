// Written by     : Chirantan Mitra

#include "../doctest.h"

#include <matrix.h>

namespace cmatrix
{

SCENARIO("cmatrix::Matrix<double> equality") {
    GIVEN("matrix of doubles") {
        WHEN("compared with a matrix with different number of rows") {
            Matrix<double> oneByTwoMatrix(1, 2);
            Matrix<double> twoByTwoMatrix(2, 2);

            THEN("the matrices are not equal") {
                CHECK_FALSE(oneByTwoMatrix.equal(twoByTwoMatrix));
                CHECK_FALSE(oneByTwoMatrix == twoByTwoMatrix);
            }

            THEN("the matrices are unequal") {
                CHECK(oneByTwoMatrix != twoByTwoMatrix);
            }
        }

        WHEN("compared with a matrix with different number of columns") {
            Matrix<double> oneByTwoMatrix(1, 2);
            Matrix<double> oneByThreeMatrix(1, 3);

            THEN("the matrices are not equal") {
                CHECK_FALSE(oneByTwoMatrix.equal(oneByThreeMatrix));
                CHECK_FALSE(oneByTwoMatrix == oneByThreeMatrix);
            }

            THEN("the matrices are unequal") {
                CHECK(oneByTwoMatrix != oneByThreeMatrix);
            }
        }

        WHEN("compared with a matrix with same number of rows and columns but one different element") {
            Matrix<double> firstTwoByTwoMatrix(2, 2);
            Matrix<double> secondTwoByTwoMatrix(2, 2);

            firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) =  1.0;
            firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) =  2.0;
            firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = -3.0;
            firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) =  4.0;

            THEN("the matrices are not equal") {
                CHECK_FALSE(firstTwoByTwoMatrix.equal(secondTwoByTwoMatrix));
                CHECK_FALSE(firstTwoByTwoMatrix == secondTwoByTwoMatrix);
            }

            THEN("the matrices are unequal") {
                CHECK(firstTwoByTwoMatrix != secondTwoByTwoMatrix);
            }
        }

        WHEN("compared with a matrix with same number of rows and columns and equal elements in same position") {
            Matrix<double> firstTwoByTwoMatrix(2, 2);
            Matrix<double> secondTwoByTwoMatrix(2, 2);

            firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) = 1.0;
            firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) = 2.0;
            firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = 3.0;
            firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) = 4.0;

            THEN("the matrices are equal") {
                CHECK(firstTwoByTwoMatrix.equal(secondTwoByTwoMatrix));
                CHECK(firstTwoByTwoMatrix == secondTwoByTwoMatrix);
            }

            THEN("the matrices are not unequal") {
                CHECK_FALSE(firstTwoByTwoMatrix != secondTwoByTwoMatrix);
            }
        }
    }
}

SCENARIO("cmatrix::Matrix<cmatrix::Matrix<double>> equality") {
    GIVEN("matrix of matrix of doubles") {
        WHEN("compared with a matrix of matrix of doubles with all component matrices equal") {
            Matrix<Matrix <double> > firstMatrix(1, 2);
            Matrix<Matrix <double> > secondMatrix(1, 2);

            Matrix<double> firstMatrix0x0(1, 1);    Matrix<double> firstMatrix0x1(2, 1);
            Matrix<double> secondMatrix0x0(1, 1);   Matrix<double> secondMatrix0x1(2, 1);

            firstMatrix0x0(0, 0) =  1.0; secondMatrix0x0(0, 0) =  1.0;
            firstMatrix0x1(0, 0) =  3.0; secondMatrix0x1(0, 0) =  3.0;
            firstMatrix0x1(1, 0) = -1.0; secondMatrix0x1(1, 0) = -1.0;

            firstMatrix(0, 0) = firstMatrix0x0; secondMatrix(0, 0) = secondMatrix0x0;
            firstMatrix(0, 1) = firstMatrix0x1; secondMatrix(0, 1) = secondMatrix0x1;

            THEN("the matrices are equal") {
                CHECK(firstMatrix == secondMatrix);
            }
        }

        WHEN("compared with a matrix of matrix of doubles with all component except one matrices equal and one is different") {
            Matrix<Matrix <double> > firstMatrix(1, 2);
            Matrix<Matrix <double> > secondMatrix(1, 2);

            Matrix<double> firstMatrix0x0(1, 1);    Matrix<double> firstMatrix0x1(2, 1);
            Matrix<double> secondMatrix0x0(1, 1);   Matrix<double> secondMatrix0x1(2, 1);

            firstMatrix0x0(0, 0) =  1.0; secondMatrix0x0(0, 0) =  1.0;
            firstMatrix0x1(0, 0) =  3.0; secondMatrix0x1(0, 0) =  3.0;
            firstMatrix0x1(1, 0) = -1.0; secondMatrix0x1(1, 0) =  1.0;

            firstMatrix(0, 0) = firstMatrix0x0; secondMatrix(0, 0) = secondMatrix0x0;
            firstMatrix(0, 1) = firstMatrix0x1; secondMatrix(0, 1) = secondMatrix0x1;

            THEN("the matrix are not equal") {
                CHECK(firstMatrix != secondMatrix);
            }
        }
    }
}

} // namespace cmatrix
