// Written by     : Chirantan Mitra

#include "../doctest.h"

#include <matrix.h>

namespace cmatrix
{

SCENARIO("cmatrix::Matrix<double> addition") {
    GIVEN("matrices") {
        WHEN("adding two matrices 2x2 matrices") {
            THEN("the elements of the resulting matrix are the sum of the corresponding elements of the two matrices") {
                Matrix<double> firstTwoByTwoMatrix(2, 2);
                Matrix<double> secondTwoByTwoMatrix(2, 2);
                Matrix<double> expectedSum(2, 2);

                firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) = -1.0; expectedSum(0, 0) = 0.0;
                firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) =  2.0; expectedSum(0, 1) = 4.0;
                firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = -3.0; expectedSum(1, 0) = 0.0;
                firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) =  4.0; expectedSum(1, 1) = 8.0;

                CHECK((firstTwoByTwoMatrix + secondTwoByTwoMatrix) == expectedSum);
            }
        }

        WHEN("adding three matrices 2x2 matrices") {
            THEN("the elements of the resulting are the sum of the corresponding elements of the three matrices") {
                Matrix<double> firstTwoByTwoMatrix(2, 2);
                Matrix<double> secondTwoByTwoMatrix(2, 2);
                Matrix<double> thirdTwoByTwoMatrix(2, 2);
                Matrix<double> expectedSum(2, 2);

                firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) = -1.0; thirdTwoByTwoMatrix(0, 0) = -1.0; expectedSum(0, 0) = -1.0;
                firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) =  2.0; thirdTwoByTwoMatrix(0, 1) =  2.0; expectedSum(0, 1) =  6.0;
                firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = -3.0; thirdTwoByTwoMatrix(1, 0) =  3.0; expectedSum(1, 0) =  3.0;
                firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) =  4.0; thirdTwoByTwoMatrix(1, 1) =  4.0; expectedSum(1, 1) = 12.0;

                CHECK((firstTwoByTwoMatrix + secondTwoByTwoMatrix + thirdTwoByTwoMatrix) == expectedSum);
            }
        }

        WHEN("adding 1x2 and 2x1 matrices") {
            THEN("an an exception is thrown") {
                Matrix<double> oneByTwoMatrix(1, 2);
                Matrix<double> twoByOneMatrix(2, 1);
                CHECK_THROWS_WITH_AS(oneByTwoMatrix + twoByOneMatrix, "Cannot add [1, 2] and [2, 1]", Exception::IncompatibleAddition);
            }
        }

        WHEN("adding two 2x2 matrices by short hand") {
            Matrix<double> firstTwoByTwoMatrix;
            Matrix<double> secondTwoByTwoMatrix;
            Matrix<double> expectedSum;

            firstTwoByTwoMatrix.setSize(2, 2);
            secondTwoByTwoMatrix.setSize(2, 2);
            expectedSum.setSize(2, 2);

            firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) = -1.0; expectedSum(0, 0) = 0.0;
            firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) =  2.0; expectedSum(0, 1) = 4.0;
            firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = -3.0; expectedSum(1, 0) = 0.0;
            firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) =  4.0; expectedSum(1, 1) = 8.0;

            THEN("the elements of the resulting matrix are the sum of the corresponding elements of the two matrices") {
                CHECK((firstTwoByTwoMatrix += secondTwoByTwoMatrix) == expectedSum);
            }

            THEN("the first matrix is mautated to equal the resulting matrix") {
                firstTwoByTwoMatrix += secondTwoByTwoMatrix;
                CHECK(firstTwoByTwoMatrix == expectedSum);
            }
        }


        WHEN("adding 1x2 and 2x1 matrices by short hand") {
            THEN("an exception is thrown") {
                Matrix<double> oneByTwoMatrix(1, 2);
                Matrix<double> twoByOneMatrix(2, 1);
                CHECK_THROWS_WITH_AS(oneByTwoMatrix += twoByOneMatrix, "Cannot add [1, 2] and [2, 1]", Exception::IncompatibleAddition);
            }
        }
    }

    GIVEN("matrix") {
        WHEN("unary adding") {
            THEN("the resulting matrix equal the original matrix") {
                Matrix<double> firstTwoByTwoMatrix(2, 2);
                Matrix<double> secondTwoByTwoMatrix(2, 2);

                firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) = 1.0;
                firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) = 2.0;
                firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = 3.0;
                firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) = 4.0;

                CHECK((+firstTwoByTwoMatrix)  == secondTwoByTwoMatrix);
            }
        }
    }
}

SCENARIO("cmatrix::Matrix<double> subtraction") {
    GIVEN("matrices") {
        WHEN("subtracting one 2x2 matrix from another 2x2 matrix") {
            THEN("all elements of resultant matrix is the difference of difference of corresponding element of the first and second matrix") {
                Matrix<double> firstTwoByTwoMatrix(2, 2);
                Matrix<double> secondTwoByTwoMatrix(2, 2);
                Matrix<double> expectedDifference(2, 2);

                firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) = -1.0; expectedDifference(0, 0) = 2.0;
                firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) =  2.0; expectedDifference(0, 1) = 0.0;
                firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = -3.0; expectedDifference(1, 0) = 6.0;
                firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) =  4.0; expectedDifference(1, 1) = 0.0;

                CHECK((firstTwoByTwoMatrix - secondTwoByTwoMatrix) == expectedDifference);
            }
        }

        WHEN("subtracting one 1x1 matrix from another 1x2 matrix") {
            THEN("an exception is thrown") {
                Matrix<double> oneByTwoMatrix(1, 2);
                Matrix<double> oneByOneMatrix(1, 1);
                std::string expectedMessage = "Cannot subtract [1, 1] from [1, 2]";
                CHECK_THROWS_WITH_AS(oneByTwoMatrix - oneByOneMatrix, "Cannot subtract [1, 1] from [1, 2]", Exception::IncompatibleSubtraction);
            }
        }

        WHEN("subtracting one 2x2 matrix from another 2x2 matrix by short hand") {
            Matrix<double> firstTwoByTwoMatrix;
            Matrix<double> secondTwoByTwoMatrix;
            Matrix<double> expectedDifference;

            firstTwoByTwoMatrix.setSize(2, 2);
            secondTwoByTwoMatrix.setSize(2, 2);
            expectedDifference.setSize(2, 2);

            firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) = -1.0; expectedDifference(0, 0) = 2.0;
            firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) =  2.0; expectedDifference(0, 1) = 0.0;
            firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = -3.0; expectedDifference(1, 0) = 6.0;
            firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) =  4.0; expectedDifference(1, 1) = 0.0;

            THEN("all elements of resultant matrix is the difference of difference of corresponding element of the first and second matrix") {
                CHECK((firstTwoByTwoMatrix -= secondTwoByTwoMatrix) == expectedDifference);
            }

            THEN("the first matrix is mautated to equal the resulting matrix") {
                firstTwoByTwoMatrix -= secondTwoByTwoMatrix;
                CHECK(firstTwoByTwoMatrix == expectedDifference);
            }
        }

        WHEN("subtracting one 2x1 matrix from another 1x2 matrix by short hand") {
            THEN("an exception is thrown") {
                Matrix<double> oneByTwoMatrix(1, 2);
                Matrix<double> twoByOneMatrix(2, 1);
                CHECK_THROWS_WITH_AS(oneByTwoMatrix -= twoByOneMatrix, "Cannot subtract [2, 1] from [1, 2]", Exception::IncompatibleSubtraction);
            }
        }
    }

    GIVEN("matrix") {
        WHEN("unary subtracting") {
            THEN("the each element of the resulting matrix is the additive inverse of the original matrix") {
                Matrix<double> firstTwoByTwoMatrix(2, 2);
                Matrix<double> secondTwoByTwoMatrix(2, 2);

                firstTwoByTwoMatrix(0, 0) =  1.0; secondTwoByTwoMatrix(0, 0) = -1.0;
                firstTwoByTwoMatrix(0, 1) =  2.0; secondTwoByTwoMatrix(0, 1) = -2.0;
                firstTwoByTwoMatrix(1, 0) = -3.0; secondTwoByTwoMatrix(1, 0) =  3.0;
                firstTwoByTwoMatrix(1, 1) =  4.0; secondTwoByTwoMatrix(1, 1) = -4.0;

                CHECK((-firstTwoByTwoMatrix) == secondTwoByTwoMatrix);
            }
        }
    }
}

SCENARIO("cmatrix::Matrix<double> multiplication") {
    GIVEN("matrices") {
        WHEN("multipling two 2x2 matrices") {
            THEN("all elements of the resulting matrix equals the sum of vector multiplication of the two matrices") {
                Matrix<double> firstTwoByTwoMatrix(2, 2);
                Matrix<double> secondTwoByTwoMatrix(2, 2);
                Matrix<double> expectedProduct(2, 2);

                firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) = -1.0; expectedProduct(0, 0) = -7.0;
                firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) =  2.0; expectedProduct(0, 1) = 10.0;
                firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = -3.0; expectedProduct(1, 0) = -15.0;
                firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) =  4.0; expectedProduct(1, 1) = 22.0;

                CHECK((firstTwoByTwoMatrix * secondTwoByTwoMatrix)  == expectedProduct);
            }
        }

        WHEN("multipling a 1x2 and a 2x1 matrices") {
            THEN("all elements of the resulting matrix equals the sum of vector multiplication of the two matrices") {
                Matrix<double> oneByTwoMatrix(1, 2);
                Matrix<double> twoByOneMatrix(2, 1);
                Matrix<double> expectedProduct(1, 1);

                oneByTwoMatrix(0, 0) = 1.0; oneByTwoMatrix(0, 1) = -1.0;
                twoByOneMatrix(0, 0) = 2.0; twoByOneMatrix(1, 0) =  2.0;
                expectedProduct(0, 0) = 0.0;

                CHECK((oneByTwoMatrix * twoByOneMatrix) == expectedProduct);
            }
        }

        WHEN("multipling a 1x2 and a 1x1 matrices") {
            THEN("an exception is thrown") {
                Matrix<double> oneByTwoMatrix(1, 2);
                Matrix<double> oneByOneMatrix(1, 1);
                CHECK_THROWS_WITH_AS(oneByTwoMatrix * oneByOneMatrix, "Cannot multiply [1, 2] with [1, 1]", Exception::IncompatibleMultiplication);
            }
        }
    }
}

SCENARIO("cmatrix::Matrix<double> scale") {
    GIVEN("matrix") {
        WHEN("scaling") {
            Matrix<double> matrix;
            Matrix<double> result;

            matrix.setSize(2, 1);
            matrix(0, 0) = -5.0;
            matrix(1, 0) = 4.0;

            result = matrix.scale(0.5);

            THEN("the resultant has the same size as the original matrix") {
                CHECK(result.rows() == 2);
                CHECK(result.columns() == 1);
            }

            THEN("all element of the resulting matrix equal the corresponding element of the original matrix multiplied by the scale factor") {
                CHECK(result(0, 0) == -2.5);
                CHECK(result(1, 0) == 2.0);
            }

            THEN("the original matrix is not mutated") {
                CHECK(matrix.rows() == 2);
                CHECK(matrix.columns() == 1);

                CHECK(matrix(0, 0) == -5.0);
                CHECK(matrix(1, 0) == 4.0);
            }
        }
    }
}

SCENARIO("cmatrix::Matrix<cmatrix::Double<double>> numerical") {
    GIVEN("matrices") {
        WHEN("adding two matrix of matrices") {
            THEN("the elements of the resulting matrix is the matrix sum the corresponding elements of the two matrices") {
                Matrix<Matrix <double> > firstMatrixOfMatrices(1, 2);
                Matrix<Matrix <double> > secondMatrixOfMatrices(1, 2);
                Matrix<Matrix <double> > expectedSum(1, 2);

                Matrix<double> firstMatrix0x0(1, 1);    Matrix<double> firstMatrix0x1(2, 1);
                Matrix<double> secondMatrix0x0(1, 1);   Matrix<double> secondMatrix0x1(2, 1);
                Matrix<double> expectedSum0x0(1, 1);    Matrix<double> expectedSum0x1(2, 1);

                firstMatrix0x0(0, 0) =  1.0; secondMatrix0x0(0, 0) =  2.0; expectedSum0x0(0, 0) =  3.0;
                firstMatrix0x1(0, 0) =  1.0; secondMatrix0x1(0, 0) = -2.0; expectedSum0x1(0, 0) = -1.0;
                firstMatrix0x1(1, 0) = -1.0; secondMatrix0x1(1, 0) =  2.0; expectedSum0x1(1, 0) =  1.0;

                firstMatrixOfMatrices(0, 0) = firstMatrix0x0; secondMatrixOfMatrices(0, 0) = secondMatrix0x0; expectedSum(0, 0) = expectedSum0x0;
                firstMatrixOfMatrices(0, 1) = firstMatrix0x1; secondMatrixOfMatrices(0, 1) = secondMatrix0x1; expectedSum(0, 1) = expectedSum0x1;

                CHECK((firstMatrixOfMatrices + secondMatrixOfMatrices)  == expectedSum);
            }
        }
    }
}


} // namespace cmatrix
