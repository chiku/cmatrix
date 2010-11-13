// File           : matrix_properties_test.cpp
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

