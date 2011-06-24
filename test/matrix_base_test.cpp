// Written by     : Chirantan Mitra

#include <matrix_test.h>

CPPUNIT_TEST_SUITE_REGISTRATION (MatrixTest);

void MatrixTest::setUp()
{
}

void MatrixTest::tearDown()
{
}


void MatrixTest::matrixOfSize2x3Has2Rows(void)
{
    Matrix<double> twoByThreeMatrix(2, 3);
    CPPUNIT_ASSERT_EQUAL (2, twoByThreeMatrix.rows());
}

void MatrixTest::matrixOfSize2x3Has3Columns(void)
{
    Matrix<double> twoByThreeMatrix(2, 3);
    CPPUNIT_ASSERT_EQUAL (3, twoByThreeMatrix.columns());
}

void MatrixTest::matrixOfSize2x3Has6Elements(void)
{
    Matrix<double> twoByThreeMatrix(2, 3);
    CPPUNIT_ASSERT_EQUAL (6, twoByThreeMatrix.elements());
}

void MatrixTest::matrixOfSize1x1CanStoreValueProperly(void)
{
    Matrix<double> oneByOneDoubleMatrix(1, 1);
    oneByOneDoubleMatrix(0, 0) = 10.0;
    CPPUNIT_ASSERT_EQUAL (10.0, oneByOneDoubleMatrix(0, 0));

    Matrix<int> oneByOneIntMatrix(1, 1);
    oneByOneIntMatrix(0, 0) = 10;
    CPPUNIT_ASSERT_EQUAL (10, oneByOneIntMatrix(0, 0));
}

void MatrixTest::matrixOfSize2x3CanStoreValueProperly(void)
{
    Matrix<double> twoByThreeMatrix(2, 3);
    twoByThreeMatrix(0, 0) = -2;
    twoByThreeMatrix(0, 1) = -1;
    twoByThreeMatrix(0, 2) =  0;
    twoByThreeMatrix(1, 0) =  1;
    twoByThreeMatrix(1, 1) =  2;
    twoByThreeMatrix(1, 2) =  3;
    CPPUNIT_ASSERT_EQUAL (-2.0, twoByThreeMatrix(0, 0));
    CPPUNIT_ASSERT_EQUAL (-1.0, twoByThreeMatrix(0, 1));
    CPPUNIT_ASSERT_EQUAL ( 0.0, twoByThreeMatrix(0, 2));
    CPPUNIT_ASSERT_EQUAL ( 1.0, twoByThreeMatrix(1, 0));
    CPPUNIT_ASSERT_EQUAL ( 2.0, twoByThreeMatrix(1, 1));
    CPPUNIT_ASSERT_EQUAL ( 3.0, twoByThreeMatrix(1, 2));
}

void MatrixTest::matrixSizeCanBeSpecifiedAfterCreation(void)
{
    Matrix<double> oneByOneMatrix;
    oneByOneMatrix.setSize(1, 1);
    oneByOneMatrix(0, 0) = 1.0;
    CPPUNIT_ASSERT_EQUAL (1, oneByOneMatrix.rows());
    CPPUNIT_ASSERT_EQUAL (1, oneByOneMatrix.columns());

    CPPUNIT_ASSERT_EQUAL (1.0, oneByOneMatrix(0, 0));
}


void MatrixTest::attemptToAccessOutsizeRowBoundsThrowsException(void)
{
    Matrix<double> oneByTwoMatrix(1, 2);
    CPPUNIT_ASSERT_THROW (oneByTwoMatrix(1, 1), MatrixException::AccessOutOfBound);
}

void MatrixTest::attemptToAssignOutsizeRowBoundsThrowsException(void)
{
    Matrix<double> oneByTwoMatrix(1, 2);
    CPPUNIT_ASSERT_THROW ((oneByTwoMatrix(1, 1) = 5), MatrixException::AccessOutOfBound);
}

void MatrixTest::attemptToAccessOutsizeBoundsThrowsExceptionWithProperMessage(void)
{
    Matrix<double> oneByTwoMatrix(1, 2);
    std::string expectedMessage = "Attempt to access out of bound. (1, 1) lies outside [1, 2]";
    CPPUNIT_ASSERT_THROW_WITH_MESSAGE ( oneByTwoMatrix(1, 1),
                                        MatrixException::AccessOutOfBound,
                                        expectedMessage );
}

void MatrixTest::attemptToAccessOutsizeColumnBoundsThrowsException(void)
{
    Matrix<double> oneByTwoMatrix(1, 2);
    CPPUNIT_ASSERT_THROW (oneByTwoMatrix(0, 2), MatrixException::AccessOutOfBound);
}

void MatrixTest::attemptToAssignOutsizeColumnBoundsThrowsException(void)
{
    Matrix<double> oneByTwoMatrix(1, 2);
    CPPUNIT_ASSERT_THROW ((oneByTwoMatrix(0, 2) = 5), MatrixException::AccessOutOfBound);
}

void MatrixTest::attemptToAssignOutsizeBoundsThrowsExceptionWithProperMessage(void)
{
    Matrix<double> oneByTwoMatrix(1, 2);
    std::string expectedMessage = "Attempt to access out of bound. (1, 1) lies outside [1, 2]";
    CPPUNIT_ASSERT_THROW_WITH_MESSAGE ( oneByTwoMatrix(1, 1) = 5,
                                        MatrixException::AccessOutOfBound,
                                        expectedMessage );
}

void MatrixTest::matrixCanBeProperlyAssignedUsingEqualsOperator(void)
{
    Matrix<double> firstTwoByTwoMatrix(2, 2);
    firstTwoByTwoMatrix(0, 0) = 1.0;
    firstTwoByTwoMatrix(0, 1) = 2.0;
    firstTwoByTwoMatrix(1, 0) = 3.0;
    firstTwoByTwoMatrix(1, 1) = 4.0;

    Matrix<double> secondTwoByTwoMatrix;
    secondTwoByTwoMatrix = firstTwoByTwoMatrix;
    CPPUNIT_ASSERT (firstTwoByTwoMatrix == secondTwoByTwoMatrix);

    secondTwoByTwoMatrix(1, 1) = -4.0;
    CPPUNIT_ASSERT (firstTwoByTwoMatrix != secondTwoByTwoMatrix);
}


void MatrixTest::matrixCanBeProperlyAssignedUsingCopyConstructor(void)
{
    Matrix<double> firstTwoByTwoMatrix(2, 2);
    firstTwoByTwoMatrix(0, 0) = 1.0;
    firstTwoByTwoMatrix(0, 1) = 2.0;
    firstTwoByTwoMatrix(1, 0) = 3.0;
    firstTwoByTwoMatrix(1, 1) = 4.0;

    Matrix<double> secondTwoByTwoMatrix = firstTwoByTwoMatrix;
    CPPUNIT_ASSERT (firstTwoByTwoMatrix == secondTwoByTwoMatrix);

    secondTwoByTwoMatrix(1, 1) = -4.0;
    CPPUNIT_ASSERT (firstTwoByTwoMatrix != secondTwoByTwoMatrix);
}

void MatrixTest::matrixSizeNotSetAsNaturalNumbersThrowsException(void)
{
    CPPUNIT_ASSERT_THROW (Matrix<double> firstBad0x0Matrix(0, 0), MatrixException::InvalidSizeSet);

    Matrix<double> secondBad0x0Matrix;
    CPPUNIT_ASSERT_THROW (secondBad0x0Matrix.setSize(1, 0), MatrixException::InvalidSizeSet);
}

void MatrixTest::matrixSizeOnResettingAfterOnceSetThrowsException(void)
{
    Matrix<double> first1x1Matrix(1, 1);
    CPPUNIT_ASSERT_THROW (first1x1Matrix.setSize(2, 2), MatrixException::SizeResetException);

    Matrix<double> second1x1Matrix(1, 1);
    CPPUNIT_ASSERT_THROW (second1x1Matrix.setSize(2, 0), MatrixException::SizeResetException);
}

void MatrixTest::matrixSizeOnResettingToSameSizeAfterOnceSetDoesNotThrowException(void)
{
    Matrix<double> first1x1Matrix(1, 1);
    CPPUNIT_ASSERT_NO_THROW (first1x1Matrix.setSize(1, 1));
}


void MatrixTest::matricesWithDifferentRowsAreUnequal(void)
{
    Matrix<double> oneByTwoMatrix(1, 2);
    Matrix<double> twoByTwoMatrix(2, 2);
    
    CPPUNIT_ASSERT (!(oneByTwoMatrix == twoByTwoMatrix));
    CPPUNIT_ASSERT (oneByTwoMatrix != twoByTwoMatrix);
}

void MatrixTest::matricesWithDifferentColumnsAreUnequal(void)
{
    Matrix<double> oneByTwoMatrix(1, 2);
    Matrix<double> oneByThreeMatrix(1, 3);
    
    CPPUNIT_ASSERT (!(oneByTwoMatrix == oneByThreeMatrix));
    CPPUNIT_ASSERT (oneByTwoMatrix != oneByThreeMatrix);
}

void MatrixTest::matricesOfEqualSizeWithOneDifferentMemberAreUnequal(void)
{
    Matrix<double> firstTwoByTwoMatrix(2, 2);
    Matrix<double> secondTwoByTwoMatrix(2, 2);

    firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) =  1.0;
    firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) =  2.0;
    firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = -3.0;
    firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) =  4.0;
    
    CPPUNIT_ASSERT (!(firstTwoByTwoMatrix == secondTwoByTwoMatrix));
    CPPUNIT_ASSERT (firstTwoByTwoMatrix != secondTwoByTwoMatrix);
}

void MatrixTest::matricesOfEqualSizeWithSameMembersAreEqual(void)
{
    Matrix<double> firstTwoByTwoMatrix(2, 2);
    Matrix<double> secondTwoByTwoMatrix(2, 2);

    firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) = 1.0;
    firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) = 2.0;
    firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = 3.0;
    firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) = 4.0;
    
    CPPUNIT_ASSERT (firstTwoByTwoMatrix == secondTwoByTwoMatrix);
    CPPUNIT_ASSERT (!(firstTwoByTwoMatrix != secondTwoByTwoMatrix));
}

void MatrixTest::matrixOfMatricesCanBeCreated(void)
{
    Matrix<double> firstMatrix(1, 1);
    Matrix<double> secondMatrix(1, 1);
    Matrix<Matrix <double> > matrixOfMatrices(1, 2);

    firstMatrix(0, 0) = 1.0;
    secondMatrix(0, 0) = 2.0;
    matrixOfMatrices(0, 0) = firstMatrix;
    matrixOfMatrices(0, 1) = secondMatrix;

    CPPUNIT_ASSERT (matrixOfMatrices(0, 0)(0, 0) == 1.0);
    CPPUNIT_ASSERT (matrixOfMatrices(0, 1)(0, 0) == 2.0);
}

void MatrixTest::matricesOfMatricesWithEqualMatrixAreEqual(void)
{
    Matrix<Matrix <double> > firstMatrix(1, 2);
    Matrix<Matrix <double> > secondMatrix(1, 2);

    Matrix<double> firstMatrix0x0(1, 1);    Matrix<double> firstMatrix0x1(2, 1);
    Matrix<double> secondMatrix0x0(1, 1);   Matrix<double> secondMatrix0x1(2, 1);

    firstMatrix0x0(0, 0) =  1.0; secondMatrix0x0(0, 0) =  1.0;
    firstMatrix0x1(0, 0) =  3.0; secondMatrix0x1(0, 0) =  3.0;
    firstMatrix0x1(1, 0) = -1.0; secondMatrix0x1(1, 0) = -1.0;

    firstMatrix(0, 0) = firstMatrix0x0; secondMatrix(0, 0) = secondMatrix0x0;
    firstMatrix(0, 1) = firstMatrix0x1; secondMatrix(0, 1) = secondMatrix0x1;

    CPPUNIT_ASSERT (firstMatrix == secondMatrix);
}

void MatrixTest::matricesOfMatricesWithUnequalMatrixAreUnequal(void)
{
    Matrix<Matrix <double> > firstMatrix(1, 2);
    Matrix<Matrix <double> > secondMatrix(1, 2);

    Matrix<double> firstMatrix0x0(1, 1);    Matrix<double> firstMatrix0x1(2, 1);
    Matrix<double> secondMatrix0x0(1, 1);   Matrix<double> secondMatrix0x1(2, 1);

    firstMatrix0x0(0, 0) =  1.0; secondMatrix0x0(0, 0) =  1.0;
    firstMatrix0x1(0, 0) =  3.0; secondMatrix0x1(0, 0) =  3.0;
    firstMatrix0x1(1, 0) = -1.0; secondMatrix0x1(1, 0) =  1.0;

    firstMatrix(0, 0) = firstMatrix0x0; secondMatrix(0, 0) = secondMatrix0x0;
    firstMatrix(0, 1) = firstMatrix0x1; secondMatrix(0, 1) = secondMatrix0x1;

    CPPUNIT_ASSERT (firstMatrix != secondMatrix);
}

