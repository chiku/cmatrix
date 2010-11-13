// Written by     : Chirantan Mitra
// Created        : 13/11/2010

#include <matrix_test.h>

void MatrixTest::matrixWithEqualNumberOfRowsAndColumnsIsSquare(void)
{
    Matrix<double> firstMatrix(1, 1);
    Matrix<double> secondMatrix(3, 3);

    CPPUNIT_ASSERT ( firstMatrix.isSquare() == true );
    CPPUNIT_ASSERT ( secondMatrix.isSquare() == true );
}

void MatrixTest::matrixWithUnequalNumberOfRowsAndColumnsIsNotSquare(void)
{
    Matrix<double> firstMatrix(1, 2);
    Matrix<double> secondMatrix(3, 2);

    CPPUNIT_ASSERT ( firstMatrix.isSquare() == false );
    CPPUNIT_ASSERT ( secondMatrix.isSquare() == false );
}

void MatrixTest::squareMatrixWithAllDiagonalElementsAsOneAndOthersAsZeroIsUnit()
{
    Matrix<double> firstMatrix(1, 1);
    Matrix<double> secondMatrix(2, 2);

    firstMatrix(0, 0) = 1.0;
    secondMatrix(0, 0) = 1.0;    secondMatrix(0, 1) = 0.0;
    secondMatrix(1, 0) = 0.0;    secondMatrix(1, 1) = 1.0;

    CPPUNIT_ASSERT ( firstMatrix.isUnit() == true );
    CPPUNIT_ASSERT ( secondMatrix.isUnit() == true );
}

void MatrixTest::squareMatrixWithNotAllDiagonalElementsAsOneOthersAsZeroIsNotUnit()
{
    Matrix<double> firstMatrix(1, 1);
    Matrix<double> secondMatrix(2, 2);

    firstMatrix(0, 0) = -1.0;
    secondMatrix(0, 0) = 1.0;    secondMatrix(0, 1) = 0.0;
    secondMatrix(1, 0) = 0.0;    secondMatrix(1, 1) = -1.0;

    CPPUNIT_ASSERT ( firstMatrix.isUnit() == false );
    CPPUNIT_ASSERT ( secondMatrix.isUnit() == false );
}

void MatrixTest::squareMatrixWithAllDiagonalElementsAsOneOthersAsNotZeroIsNotUnit()
{
    Matrix<double> firstMatrix(1, 1);
    Matrix<double> secondMatrix(2, 2);

    firstMatrix(0, 0) = -1.0;
    secondMatrix(0, 0) = 1.0;    secondMatrix(0, 1) = 1.0;
    secondMatrix(1, 0) = 0.0;    secondMatrix(1, 1) = 1.0;

    CPPUNIT_ASSERT ( firstMatrix.isUnit() == false );
    CPPUNIT_ASSERT ( secondMatrix.isUnit() == false );
}

void MatrixTest::nonSquareMatrixIsNotUnit()
{
    Matrix<double> matrix(1, 2);

    matrix(0, 0) = 1.0;    matrix(0, 1) = 0.0;

    CPPUNIT_ASSERT ( matrix.isUnit() == false );
}

void MatrixTest::matrixWithAllElementsAsZeroIsZero()
{
    Matrix<double> matrix(1, 2);

    matrix(0, 0) = 0.0;    matrix(0, 1) = 0.0;

    CPPUNIT_ASSERT ( matrix.isZero() == true );
}

void MatrixTest::matrixWithOneNonZeroElementIsNotZero()
{
    Matrix<double> matrix(1, 2);

    matrix(0, 0) = 0.0;    matrix(0, 1) = 1.0;

    CPPUNIT_ASSERT ( matrix.isZero() == false );
}

