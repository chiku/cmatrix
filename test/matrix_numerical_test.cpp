// Written by     : Chirantan Mitra

#include <matrix_test.h>

void MatrixTest::two2x2MatricesCanBeProperlyAdded(void)
{
    Matrix<double> firstTwoByTwoMatrix(2, 2);
    Matrix<double> secondTwoByTwoMatrix(2, 2);
    Matrix<double> expectedSum(2, 2);

    firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) = -1.0; expectedSum(0, 0) = 0.0; 
    firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) =  2.0; expectedSum(0, 1) = 4.0;
    firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = -3.0; expectedSum(1, 0) = 0.0;
    firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) =  4.0; expectedSum(1, 1) = 8.0;

    CPPUNIT_ASSERT ((firstTwoByTwoMatrix + secondTwoByTwoMatrix) == expectedSum);
}

void MatrixTest::three2x2MatricesCanBeProperlyAdded(void)
{
    Matrix<double> firstTwoByTwoMatrix(2, 2);
    Matrix<double> secondTwoByTwoMatrix(2, 2);
    Matrix<double> thirdTwoByTwoMatrix(2, 2);
    Matrix<double> expectedSum(2, 2);

    firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) = -1.0; thirdTwoByTwoMatrix(0, 0) = -1.0; expectedSum(0, 0) = -1.0; 
    firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) =  2.0; thirdTwoByTwoMatrix(0, 1) =  2.0; expectedSum(0, 1) =  6.0;
    firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = -3.0; thirdTwoByTwoMatrix(1, 0) =  3.0; expectedSum(1, 0) =  3.0;
    firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) =  4.0; thirdTwoByTwoMatrix(1, 1) =  4.0; expectedSum(1, 1) = 12.0;

    CPPUNIT_ASSERT ((firstTwoByTwoMatrix + secondTwoByTwoMatrix + thirdTwoByTwoMatrix) == expectedSum);
}

void MatrixTest::two1x2And2x1MatricesWhenAddedThrowException(void)
{
    Matrix<double> oneByTwoMatrix(1, 2);
    Matrix<double> twoByOneMatrix(2, 1);

    CPPUNIT_ASSERT_THROW (oneByTwoMatrix + twoByOneMatrix, Exception::IncompatibleAddition);
}


void MatrixTest::two2x2MatricesCanBeProperlySubtracted(void)
{
    Matrix<double> firstTwoByTwoMatrix(2, 2);
    Matrix<double> secondTwoByTwoMatrix(2, 2);
    Matrix<double> expectedDifference(2, 2);

    firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) = -1.0; expectedDifference(0, 0) = 2.0;
    firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) =  2.0; expectedDifference(0, 1) = 0.0;
    firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = -3.0; expectedDifference(1, 0) = 6.0;
    firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) =  4.0; expectedDifference(1, 1) = 0.0;

    CPPUNIT_ASSERT ((firstTwoByTwoMatrix - secondTwoByTwoMatrix) == expectedDifference);
}

void MatrixTest::two1x2And1x1MatricesWhenSubtractedThrowException(void)
{
    Matrix<double> oneByTwoMatrix(1, 2);
    Matrix<double> oneByOneMatrix(1, 1);

    CPPUNIT_ASSERT_THROW (oneByTwoMatrix - oneByOneMatrix, Exception::IncompatibleSubtraction);
}


void MatrixTest::two2x2MatricesCanBeProperlyAddedByShortHand(void)
{
    Matrix<double> firstTwoByTwoMatrix(2, 2);
    Matrix<double> secondTwoByTwoMatrix(2, 2);
    Matrix<double> expectedSum(2, 2);

    firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) = -1.0; expectedSum(0, 0) = 0.0;
    firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) =  2.0; expectedSum(0, 1) = 4.0;
    firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = -3.0; expectedSum(1, 0) = 0.0;
    firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) =  4.0; expectedSum(1, 1) = 8.0;

    CPPUNIT_ASSERT ((firstTwoByTwoMatrix += secondTwoByTwoMatrix) == expectedSum);
    CPPUNIT_ASSERT (firstTwoByTwoMatrix == expectedSum);
}

void MatrixTest::two1x2And2x1MatricesWhenAddedByShortHandThrowException(void)
{
    Matrix<double> oneByTwoMatrix(1, 2);
    Matrix<double> twoByOneMatrix(2, 1);

    CPPUNIT_ASSERT_THROW (oneByTwoMatrix += twoByOneMatrix, Exception::IncompatibleAddition);
}


void MatrixTest::two2x2MatricesCanBeProperlySubtractedByShortHand(void)
{
    Matrix<double> firstTwoByTwoMatrix(2, 2);
    Matrix<double> secondTwoByTwoMatrix(2, 2);
    Matrix<double> expectedDifference(2, 2);

    firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) = -1.0; expectedDifference(0, 0) = 2.0; 
    firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) =  2.0; expectedDifference(0, 1) = 0.0;
    firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = -3.0; expectedDifference(1, 0) = 6.0;
    firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) =  4.0; expectedDifference(1, 1) = 0.0;

    CPPUNIT_ASSERT ((firstTwoByTwoMatrix -= secondTwoByTwoMatrix) == expectedDifference);
    CPPUNIT_ASSERT (firstTwoByTwoMatrix == expectedDifference);
}

void MatrixTest::two1x2And2x1MatricesWhenSubtractedByShortHandThrowException(void)
{
    Matrix<double> oneByTwoMatrix(1, 2);
    Matrix<double> twoByOneMatrix(2, 1);

    CPPUNIT_ASSERT_THROW (oneByTwoMatrix -= twoByOneMatrix, Exception::IncompatibleSubtraction);
}

void MatrixTest::a2x2MatricesReturnsItselfOnUnaryAddition(void)
{
    Matrix<double> firstTwoByTwoMatrix(2, 2);
    Matrix<double> secondTwoByTwoMatrix(2, 2);

    firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) = 1.0;
    firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) = 2.0;
    firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = 3.0;
    firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) = 4.0;

    CPPUNIT_ASSERT ((+firstTwoByTwoMatrix) == secondTwoByTwoMatrix);
}

void MatrixTest::a2x2MatricesReturnsAdditiveInverseOnUnarySubtraction(void)
{
    Matrix<double> firstTwoByTwoMatrix(2, 2);
    Matrix<double> secondTwoByTwoMatrix(2, 2);

    firstTwoByTwoMatrix(0, 0) =  1.0; secondTwoByTwoMatrix(0, 0) = -1.0;
    firstTwoByTwoMatrix(0, 1) =  2.0; secondTwoByTwoMatrix(0, 1) = -2.0;
    firstTwoByTwoMatrix(1, 0) = -3.0; secondTwoByTwoMatrix(1, 0) =  3.0;
    firstTwoByTwoMatrix(1, 1) =  4.0; secondTwoByTwoMatrix(1, 1) = -4.0;

    CPPUNIT_ASSERT ((-firstTwoByTwoMatrix) == secondTwoByTwoMatrix);
}


void MatrixTest::two2x2MatricesCanBeProperlyMultiplied(void)
{
    Matrix<double> firstTwoByTwoMatrix(2, 2);
    Matrix<double> secondTwoByTwoMatrix(2, 2);
    Matrix<double> expectedProduct(2, 2);

    firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) = -1.0; expectedProduct(0, 0) = -7.0;
    firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) =  2.0; expectedProduct(0, 1) = 10.0;
    firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = -3.0; expectedProduct(1, 0) = -15.0;
    firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) =  4.0; expectedProduct(1, 1) = 22.0;

    CPPUNIT_ASSERT ((firstTwoByTwoMatrix * secondTwoByTwoMatrix) == expectedProduct);
}

void MatrixTest::one1x2AndOne2x1MatricesCanBeProperlyMultiplied(void)
{
    Matrix<double> oneByTwoMatrix(1, 2);
    Matrix<double> twoByOneMatrix(2, 1);
    Matrix<double> expectedProduct(1, 1);

    oneByTwoMatrix(0, 0) = 1.0; oneByTwoMatrix(0, 1) = -1.0;
    twoByOneMatrix(0, 0) = 2.0; twoByOneMatrix(1, 0) =  2.0;
    expectedProduct(0, 0) = 0.0;

    CPPUNIT_ASSERT ((oneByTwoMatrix * twoByOneMatrix) == expectedProduct);
}

void MatrixTest::two1x2And1x1MatricesWhenMultipliedThrowException(void)
{    
    Matrix<double> oneByTwoMatrix(1, 2);
    Matrix<double> oneByOneMatrix(1, 1);
    
    CPPUNIT_ASSERT_THROW ((oneByTwoMatrix * oneByOneMatrix), Exception::IncompatibleMultiplication);
}

void MatrixTest::twoMatrixOfMatricesCanBeProperlyAdded(void)
{
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

    CPPUNIT_ASSERT ((firstMatrixOfMatrices + secondMatrixOfMatrices) == expectedSum);
}

