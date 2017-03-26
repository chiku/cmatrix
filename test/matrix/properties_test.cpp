// Written by     : Chirantan Mitra

#include "../doctest.h"

#include <matrix.h>

namespace cmatrix
{

SCENARIO("cmatrix::Matrix<double> properties") {
    GIVEN("matrix") {
        WHEN("number of rows and columns are equal") {
            THEN("it is a square matrix") {
                CHECK(Matrix<double>(1, 1).isSquare());
                CHECK(Matrix<double>(3, 3).isSquare());
            }
        }

        WHEN("number of rows and columns are not equal") {
            THEN("it is not a square matrix") {
                CHECK_FALSE(Matrix<double>(1, 2).isSquare());
                CHECK_FALSE(Matrix<double>(3, 2).isSquare());
            }
        }

        WHEN("all its elements are zero") {
            THEN("it is a zero matrix") {
                Matrix<double> matrix(1, 2);
                matrix(0, 0) = 0.0;    matrix(0, 1) = 0.0;
                CHECK(matrix.isZero());
            }
        }

        WHEN("all its elements are not zero") {
            THEN("it is not a zero matrix") {
                Matrix<double> matrix(1, 2);
                matrix(0, 0) = 0.0;    matrix(0, 1) = 1.0;
                CHECK_FALSE(matrix.isZero());
            }
        }
    }

    GIVEN("square matrix") {
        WHEN("all its diagonal elements are one and all other elements are zero") {
            THEN("it is a unit matrix") {
                Matrix<double> firstMatrix(1, 1);
                firstMatrix(0, 0) = 1.0;
                CHECK(firstMatrix.isUnit());

                Matrix<double> secondMatrix(2, 2);
                secondMatrix(0, 0) = 1.0;    secondMatrix(0, 1) = 0.0;
                secondMatrix(1, 0) = 0.0;    secondMatrix(1, 1) = 1.0;
                CHECK(secondMatrix.isUnit());                
            }
        }

        WHEN("all its diagonal elements are not one") {
            THEN("it is not a unit matrix") {
                Matrix<double> firstMatrix(1, 1);
                firstMatrix(0, 0) = -1.0;
                CHECK_FALSE(firstMatrix.isUnit());

                Matrix<double> secondMatrix(2, 2);
                secondMatrix(0, 0) = 1.0;    secondMatrix(0, 1) = 0.0;
                secondMatrix(1, 0) = 0.0;    secondMatrix(1, 1) = -1.0;
                CHECK_FALSE(secondMatrix.isUnit());                
            }
        }

        WHEN("not all non-diagonal elements are zero") {
            THEN("it is not a unit matrix") {
                Matrix<double> matrix(2, 2);
                matrix(0, 0) = 1.0;    matrix(0, 1) = 1.0;
                matrix(1, 0) = 0.0;    matrix(1, 1) = 1.0;
                CHECK_FALSE(matrix.isUnit());                
            }
        }
    }

    GIVEN("matrix") {
        WHEN("not square") {
            THEN("it is not a unit matrix") {
                Matrix<double> matrix(1, 2);
                matrix(0, 0) = 1.0;    matrix(0, 1) = 0.0;
                CHECK_FALSE(matrix.isUnit());
            }
        }
    }
}

} // namespace cmatrix
