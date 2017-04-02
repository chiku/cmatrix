// Written by     : Chirantan Mitra

#include "../doctest.h"

#include <matrix.h>

namespace cmatrix
{

SCENARIO("cmatrix::Matrix<double> accessor") {
    GIVEN("matrix") {
        WHEN("created with size 2x3") {
            Matrix<double> twoByThreeMatrix(2, 3);

            THEN("it has 2 rows") {
                CHECK(twoByThreeMatrix.rows() == 2);
            }

            THEN("it has 3 columns") {
                CHECK(twoByThreeMatrix.columns() == 3);
            }

            THEN("it has 6 elements") {
                CHECK(twoByThreeMatrix.elements() == 6);
            }

            THEN("all elements are assignable and retrivable by row and column position") {
                twoByThreeMatrix(0, 0) = -2;
                twoByThreeMatrix(0, 1) = -1;
                twoByThreeMatrix(0, 2) =  0;
                twoByThreeMatrix(1, 0) =  1;
                twoByThreeMatrix(1, 1) =  2;
                twoByThreeMatrix(1, 2) =  3;

                CHECK(twoByThreeMatrix(0, 0) == -2.0);
                CHECK(twoByThreeMatrix(0, 1) == -1.0);
                CHECK(twoByThreeMatrix(0, 2) ==  0.0);
                CHECK(twoByThreeMatrix(1, 0) == 1.0);
                CHECK(twoByThreeMatrix(1, 1) == 2.0);
                CHECK(twoByThreeMatrix(1, 2) == 3.0);
            }
        }

        WHEN("rows is negative during creation") {
            THEN("it throws an exception") {
                std::string expectedMessage = "Invalid attempt to set rows to -1 and columns to 0";
                // AssertThrows(Exception::InvalidSizeSet, Matrix<double> bad0x0Matrix(-1, 0));
                // CHECK(LastException<Exception::InvalidSizeSet>().what() == expectedMessage);
            }
        }

        WHEN("columns is negative during creation") {
            THEN("it throws an exception") {
                std::string expectedMessage = "Invalid attempt to set rows to 0 and columns to -1";
                // AssertThrows(Exception::InvalidSizeSet, Matrix<double> bad0x0Matrix(0, -1));
                // CHECK(LastException<Exception::InvalidSizeSet>().what() == expectedMessage);
            }
        }

        WHEN("created with size 1x1") {
            Matrix<double> oneByOneDoubleMatrix(1, 1);

            THEN("its element is assignable and retrivable by row and column position") {
                oneByOneDoubleMatrix(0, 0) = 10.0;
                CHECK(oneByOneDoubleMatrix(0, 0) == 10.0);
            }
        }

        WHEN("setting a size 1x1 after creation") {
            Matrix<double> oneByOneMatrix;
            oneByOneMatrix.setSize(1, 1);

            THEN("is has 1 row") {
                CHECK(oneByOneMatrix.rows() == 1);
            }

            THEN("is has 1 column") {
                CHECK(oneByOneMatrix.columns() == 1);
            }

            THEN("its element is assignable and retrivable by row and column position") {
                oneByOneMatrix(0, 0) = 1.0;
                CHECK(oneByOneMatrix(0, 0) == 1.0);
            }
        }

        WHEN("rows is negative while resizing after creation") {
            THEN("it throws an exception") {
                std::string expectedMessage = "Invalid attempt to set rows to -1 and columns to 0";
                // AssertThrows(Exception::InvalidSizeSet, Matrix<double> bad0x0Matrix(-1, 0));
                // CHECK(LastException<Exception::InvalidSizeSet>().what() == expectedMessage);
            }
        }

        WHEN("columns is negative while resizing after creation") {
            THEN("it throws an exception") {
                Matrix<double> bad0x0Matrix;
                std::string expectedMessage = "Invalid attempt to set rows to 1 and columns to -1";
                // AssertThrows(Exception::InvalidSizeSet, bad0x0Matrix.setSize(1, -1));
                // CHECK(LastException<Exception::InvalidSizeSet>().what() == expectedMessage);
            }
        }

        WHEN("resetting size to same as original") {
            THEN("the size doesn't change") {
                Matrix<double> a1x1Matrix(1, 1);
                a1x1Matrix.setSize(1, 1);
                CHECK(a1x1Matrix.rows() == 1);
                CHECK(a1x1Matrix.columns() == 1);
            }
        }

        WHEN("resetting rows to different row from original size") {
            THEN("it throws an exception") {
                Matrix<double> a1x1Matrix(1, 1);
                std::string expectedMessage = "Invalid attempt to reset rows to 2 and columns to 2 from [1, 1]";
                // AssertThrows(Exception::InvalidSizeReset, a1x1Matrix.setSize(2, 2));
                // CHECK(LastException<Exception::InvalidSizeReset>().what() == expectedMessage);
            }
        }

        WHEN("resetting columns to different column from original size") {
            THEN("it throws an exception") {
                Matrix<double> a1x1Matrix(1, 1);
                std::string expectedMessage = "Invalid attempt to reset rows to 2 and columns to 0 from [1, 1]";
                // AssertThrows(Exception::InvalidSizeReset, a1x1Matrix.setSize(2, 0));
                // CHECK(LastException<Exception::InvalidSizeReset>().what() == expectedMessage);
            }
        }

        WHEN("accessing outside row bounds") {
            THEN("an exception is thrown") {
                Matrix<double> oneByTwoMatrix(1, 2);
                std::string expectedMessage = "Invalid attempt to access (1, 1) which lies outside bounds [1, 2]";
                // AssertThrows(Exception::AccessOutOfBound, oneByTwoMatrix(1, 1));
                // CHECK(LastException<Exception::AccessOutOfBound>().what() == expectedMessage);
            }
        }

        WHEN("assigning outside row bounds") {
            THEN("an exception is thrown") {
                Matrix<double> oneByTwoMatrix(1, 2);
                std::string expectedMessage = "Invalid attempt to access (1, 1) which lies outside bounds [1, 2]";
                // AssertThrows(Exception::AccessOutOfBound, oneByTwoMatrix(1, 1) = 5);
                // CHECK(LastException<Exception::AccessOutOfBound>().what() == expectedMessage);
            }
        }

        WHEN("accessing outside column bounds") {
            THEN("an exception is thrown") {
                Matrix<double> oneByTwoMatrix(1, 2);
                std::string expectedMessage = "Invalid attempt to access (0, 2) which lies outside bounds [1, 2]";
                // AssertThrows(Exception::AccessOutOfBound, oneByTwoMatrix(0, 2));
                // CHECK(LastException<Exception::AccessOutOfBound>().what() == expectedMessage);
            }
        }

        WHEN("assigning outside column bounds") {
            THEN("an exception is thrown") {
                Matrix<double> oneByTwoMatrix(1, 2);
                std::string expectedMessage = "Invalid attempt to access (0, 2) which lies outside bounds [1, 2]";
                // AssertThrows(Exception::AccessOutOfBound, oneByTwoMatrix(0, 2) = 5);
                // CHECK(LastException<Exception::AccessOutOfBound>().what() == expectedMessage);
            }
        }
    }
}

SCENARIO("cmatrix::Matrix<double> == operator") {
    GIVEN("matrix") {
        WHEN("copied by equals operator") {
            Matrix<double> firstTwoByTwoMatrix;

            firstTwoByTwoMatrix.setSize(2, 2);
            firstTwoByTwoMatrix(0, 0) = 1.0;
            firstTwoByTwoMatrix(0, 1) = 2.0;
            firstTwoByTwoMatrix(1, 0) = 3.0;
            firstTwoByTwoMatrix(1, 1) = 4.0;

            Matrix<double> secondTwoByTwoMatrix;
            secondTwoByTwoMatrix = firstTwoByTwoMatrix;

            THEN("it equals the original matrix") {
                CHECK(firstTwoByTwoMatrix == secondTwoByTwoMatrix);
            }

            THEN("it does not equal the original matrix after copied matrix is changed") {
                secondTwoByTwoMatrix(1, 1) = -4.0;
                CHECK(firstTwoByTwoMatrix != secondTwoByTwoMatrix);
            }

            THEN("it is unaffected by changes to copied matrix") {
                secondTwoByTwoMatrix(1, 1) = -4.0;
                CHECK(firstTwoByTwoMatrix(1, 1) == 4.0);
            }
        }
    }
}

SCENARIO("cmatrix::Matrix<double> copy constructor") {
    GIVEN("matrix") {
        WHEN("copied by equals operator") {
            Matrix<double> firstTwoByTwoMatrix;

            firstTwoByTwoMatrix.setSize(2, 2);
            firstTwoByTwoMatrix(0, 0) = 1.0;
            firstTwoByTwoMatrix(0, 1) = 2.0;
            firstTwoByTwoMatrix(1, 0) = 3.0;
            firstTwoByTwoMatrix(1, 1) = 4.0;

            Matrix<double> secondTwoByTwoMatrix = firstTwoByTwoMatrix;

            THEN("it equals the original matrix") {
                CHECK(firstTwoByTwoMatrix == secondTwoByTwoMatrix);
            }

            THEN("it does not equal the original matrix after copied matrix is changed") {
                secondTwoByTwoMatrix(1, 1) = -4.0;
                CHECK(firstTwoByTwoMatrix != secondTwoByTwoMatrix);
            }

            THEN("it is unaffected by changes to copied matrix") {
                secondTwoByTwoMatrix(1, 1) = -4.0;
                CHECK(firstTwoByTwoMatrix(1, 1) == 4.0);
            }
        }
    }
}

SCENARIO("cmatrix::Matrix<int> accessor") {
    GIVEN("matrix") {
        WHEN("created with size 1x1") {
            Matrix<int> oneByOneIntMatrix(1, 1);

            THEN("its element is assignable and retrivable by row and column position") {
                oneByOneIntMatrix(0, 0) = 10;
                CHECK(oneByOneIntMatrix(0, 0) == 10);
            }
        }
    }
}

SCENARIO("cmatrix::Matrix<cmatrix::Matrix<double>> accessor") {
    GIVEN("matrix of matrices") {
        WHEN("created with size 1x2") {
            THEN("its elements are assignable and retrivable by row and column position") {
                Matrix<double> firstMatrix(1, 1);
                Matrix<double> secondMatrix(1, 1);
                Matrix<Matrix <double> > matrixOfMatrices(1, 2);

                firstMatrix(0, 0) = 1.0;
                secondMatrix(0, 0) = 2.0;
                matrixOfMatrices(0, 0) = firstMatrix;
                matrixOfMatrices(0, 1) = secondMatrix;

                CHECK(matrixOfMatrices(0, 0)(0, 0) == 1.0);
                CHECK(matrixOfMatrices(0, 1)(0, 0) == 2.0);
            }
        }
    }
}

} // namespace cmatrix
