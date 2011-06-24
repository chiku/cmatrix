// Written by     : Chirantan Mitra

#include <matrix_test.h>

void MatrixTest::matrixWithEqualNumberOfRowsAndColumnsIsSquare(void)
{
    Matrix<double> firstMatrix(1, 1);
    Matrix<double> secondMatrix(3, 3);

    CPPUNIT_ASSERT ( firstMatrix.isSquare() );
    CPPUNIT_ASSERT ( secondMatrix.isSquare() );
}

void MatrixTest::matrixWithUnequalNumberOfRowsAndColumnsIsNotSquare(void)
{
    Matrix<double> firstMatrix(1, 2);
    Matrix<double> secondMatrix(3, 2);

    CPPUNIT_ASSERT ( !firstMatrix.isSquare() );
    CPPUNIT_ASSERT ( !secondMatrix.isSquare() );
}

void MatrixTest::squareMatrixWithAllDiagonalElementsAsOneAndOthersAsZeroIsUnit()
{
    Matrix<double> firstMatrix(1, 1);
    Matrix<double> secondMatrix(2, 2);

    firstMatrix(0, 0) = 1.0;
    secondMatrix(0, 0) = 1.0;    secondMatrix(0, 1) = 0.0;
    secondMatrix(1, 0) = 0.0;    secondMatrix(1, 1) = 1.0;

    CPPUNIT_ASSERT ( firstMatrix.isUnit() );
    CPPUNIT_ASSERT ( secondMatrix.isUnit() );
}

void MatrixTest::squareMatrixWithNotAllDiagonalElementsAsOneOthersAsZeroIsNotUnit()
{
    Matrix<double> firstMatrix(1, 1);
    Matrix<double> secondMatrix(2, 2);

    firstMatrix(0, 0) = -1.0;
    secondMatrix(0, 0) = 1.0;    secondMatrix(0, 1) = 0.0;
    secondMatrix(1, 0) = 0.0;    secondMatrix(1, 1) = -1.0;

    CPPUNIT_ASSERT ( !firstMatrix.isUnit() );
    CPPUNIT_ASSERT ( !secondMatrix.isUnit() );
}

void MatrixTest::squareMatrixWithAllDiagonalElementsAsOneOthersAsNotZeroIsNotUnit()
{
    Matrix<double> firstMatrix(1, 1);
    Matrix<double> secondMatrix(2, 2);

    firstMatrix(0, 0) = -1.0;
    secondMatrix(0, 0) = 1.0;    secondMatrix(0, 1) = 1.0;
    secondMatrix(1, 0) = 0.0;    secondMatrix(1, 1) = 1.0;

    CPPUNIT_ASSERT ( !firstMatrix.isUnit() );
    CPPUNIT_ASSERT ( !secondMatrix.isUnit() );
}

void MatrixTest::nonSquareMatrixIsNotUnit()
{
    Matrix<double> matrix(1, 2);

    matrix(0, 0) = 1.0;    matrix(0, 1) = 0.0;

    CPPUNIT_ASSERT ( !matrix.isUnit() );
}

void MatrixTest::matrixWithAllElementsAsZeroIsZero()
{
    Matrix<double> matrix(1, 2);

    matrix(0, 0) = 0.0;    matrix(0, 1) = 0.0;

    CPPUNIT_ASSERT ( matrix.isZero() );
}

void MatrixTest::matrixWithOneNonZeroElementIsNotZero()
{
    Matrix<double> matrix(1, 2);

    matrix(0, 0) = 0.0;    matrix(0, 1) = 1.0;

    CPPUNIT_ASSERT ( !matrix.isZero() );
}

