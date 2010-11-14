// Written by     : Chirantan Mitra

#include <matrix_test.h>

void MatrixTest::matrixWithEqualNumberOfRowsAndColumnsIsSquare(void)
{
    SolidMatrix<double> firstMatrix(1, 1);
    SolidMatrix<double> secondMatrix(3, 3);

    CPPUNIT_ASSERT ( firstMatrix.isSquare() == true );
    CPPUNIT_ASSERT ( secondMatrix.isSquare() == true );
}

void MatrixTest::matrixWithUnequalNumberOfRowsAndColumnsIsNotSquare(void)
{
    SolidMatrix<double> firstMatrix(1, 2);
    SolidMatrix<double> secondMatrix(3, 2);

    CPPUNIT_ASSERT ( firstMatrix.isSquare() == false );
    CPPUNIT_ASSERT ( secondMatrix.isSquare() == false );
}

void MatrixTest::squareMatrixWithAllDiagonalElementsAsOneAndOthersAsZeroIsUnit()
{
    SolidMatrix<double> firstMatrix(1, 1);
    SolidMatrix<double> secondMatrix(2, 2);

    firstMatrix(0, 0) = 1.0;
    secondMatrix(0, 0) = 1.0;    secondMatrix(0, 1) = 0.0;
    secondMatrix(1, 0) = 0.0;    secondMatrix(1, 1) = 1.0;

    CPPUNIT_ASSERT ( firstMatrix.isUnit() == true );
    CPPUNIT_ASSERT ( secondMatrix.isUnit() == true );
}

void MatrixTest::squareMatrixWithNotAllDiagonalElementsAsOneOthersAsZeroIsNotUnit()
{
    SolidMatrix<double> firstMatrix(1, 1);
    SolidMatrix<double> secondMatrix(2, 2);

    firstMatrix(0, 0) = -1.0;
    secondMatrix(0, 0) = 1.0;    secondMatrix(0, 1) = 0.0;
    secondMatrix(1, 0) = 0.0;    secondMatrix(1, 1) = -1.0;

    CPPUNIT_ASSERT ( firstMatrix.isUnit() == false );
    CPPUNIT_ASSERT ( secondMatrix.isUnit() == false );
}

void MatrixTest::squareMatrixWithAllDiagonalElementsAsOneOthersAsNotZeroIsNotUnit()
{
    SolidMatrix<double> firstMatrix(1, 1);
    SolidMatrix<double> secondMatrix(2, 2);

    firstMatrix(0, 0) = -1.0;
    secondMatrix(0, 0) = 1.0;    secondMatrix(0, 1) = 1.0;
    secondMatrix(1, 0) = 0.0;    secondMatrix(1, 1) = 1.0;

    CPPUNIT_ASSERT ( firstMatrix.isUnit() == false );
    CPPUNIT_ASSERT ( secondMatrix.isUnit() == false );
}

void MatrixTest::nonSquareMatrixIsNotUnit()
{
    SolidMatrix<double> matrix(1, 2);

    matrix(0, 0) = 1.0;    matrix(0, 1) = 0.0;

    CPPUNIT_ASSERT ( matrix.isUnit() == false );
}

void MatrixTest::matrixWithAllElementsAsZeroIsZero()
{
    SolidMatrix<double> matrix(1, 2);

    matrix(0, 0) = 0.0;    matrix(0, 1) = 0.0;

    CPPUNIT_ASSERT ( matrix.isZero() == true );
}

void MatrixTest::matrixWithOneNonZeroElementIsNotZero()
{
    SolidMatrix<double> matrix(1, 2);

    matrix(0, 0) = 0.0;    matrix(0, 1) = 1.0;

    CPPUNIT_ASSERT ( matrix.isZero() == false );
}

