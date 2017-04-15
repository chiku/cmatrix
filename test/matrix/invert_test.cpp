// Written by     : Chirantan Mitra

#include "../doctest.h"

#include <matrix.h>

namespace cmatrix
{

SCENARIO("cmatrix::Matrix<double> inversion") {
    GIVEN("unitary matrix") {
        Matrix<double> unitaryMatrix;
        unitaryMatrix.setSize(2, 2);
        unitaryMatrix(0, 0) = 1.0; unitaryMatrix(0, 1) = 0.0;
        unitaryMatrix(1, 0) = 0.0; unitaryMatrix(1, 1) = 1.0;

        WHEN("inverted") {
            Matrix<double> invertedMatrix;
            invertedMatrix = unitaryMatrix.invert();

            THEN("the result has the same number of rows as the original matrix") {
                CHECK(invertedMatrix.rows() == 2);
            }

            THEN("the result has the same number of columns as the original matrix") {
                CHECK(invertedMatrix.columns() == 2);
            }

            THEN("it equal the unitary matrix") {
                CHECK(invertedMatrix(0, 0) == 1.0); CHECK(invertedMatrix(0, 1) == 0.0);
                CHECK(invertedMatrix(1, 0) == 0.0); CHECK(invertedMatrix(1, 1) == 1.0);
            }
        }
    }

    GIVEN("3x3 matrix") {
        Matrix<double> matrix;
        matrix.setSize(3, 3);
        matrix(0, 0) = 1.0; matrix(0, 1) = 3.0; matrix(0, 2) = 3.0;
        matrix(1, 0) = 1.0; matrix(1, 1) = 4.0; matrix(1, 2) = 3.0;
        matrix(2, 0) = 1.0; matrix(2, 1) = 3.0; matrix(2, 2) = 4.0;

        WHEN("inverted") {
            Matrix<double> invertedMatrix;
            invertedMatrix = matrix.invert();

            THEN("the result after multiplication with itself is a unitary matrix") {
                CHECK((matrix * invertedMatrix).isUnit());
            }

            THEN("the original matrix is not mutated") {
                CHECK(matrix != invertedMatrix);
            }
        }
    }

    GIVEN("1x1 matrix") {
        Matrix<double> matrix(1, 1);
        matrix(0, 0) = -1.0;

        WHEN("inverted") {
            Matrix<double> expectedInvertedMatrix(1, 1);
            expectedInvertedMatrix(0, 0) = -1.0;

            THEN("it finds the inverse") {
                CHECK(matrix.invert() == expectedInvertedMatrix);
            }
        }
    }

    GIVEN("2x3 matrix") {
        Matrix<double> nonSquareMatrix(2, 3);

        WHEN("inverted") {
            THEN("as exception is thrown") {
                std::string expectedMessage = "Cannot invert a non-square matrix [2, 3]";
                // AssertThrows(Exception::InversionNotPossible, nonSquareMatrix.invert());
                // Assert::That(LastException<Exception::InversionNotPossible>().what(), Equals(expectedMessage));
            }
        }        
    }

    GIVEN("a singular matrix") {
        Matrix<double> singularMatrix(2, 2);
        singularMatrix(0, 0) = 1.0; singularMatrix(0, 1) = 0.0;
        singularMatrix(1, 0) = 0.0; singularMatrix(1, 1) = 0.0;

        WHEN("inverted") {
            THEN("an exception is thrown") {
                std::string expectedMessage = "Cannot invert a singular matrix";
                // AssertThrows(Exception::InversionNotPossible, singularMatrix.invert());
                // Assert::That(LastException<Exception::InversionNotPossible>().what(), Equals(expectedMessage));
            }        
        }
    }
}

} // namespace cmatrix
