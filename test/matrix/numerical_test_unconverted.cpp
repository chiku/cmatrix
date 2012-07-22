// Written by     : Chirantan Mitra

#include <matrix_test.h>

void MatrixTest::two1x2And2x1MatricesWhenAddedThrowException(void)
{
    Matrix<double> oneByTwoMatrix(1, 2);
    Matrix<double> twoByOneMatrix(2, 1);

    std::string expectedMessage = "Cannot add [1, 2] and [2, 1]";
    CPPUNIT_ASSERT_THROW_WITH_MESSAGE ( oneByTwoMatrix + twoByOneMatrix,
                                        Exception::IncompatibleAddition,
                                        expectedMessage );
}


void MatrixTest::two1x2And1x1MatricesWhenSubtractedThrowException(void)
{
    Matrix<double> oneByTwoMatrix(1, 2);
    Matrix<double> oneByOneMatrix(1, 1);

    std::string expectedMessage = "Cannot subtract [1, 1] from [1, 2]";
    CPPUNIT_ASSERT_THROW_WITH_MESSAGE ( oneByTwoMatrix - oneByOneMatrix,
                                        Exception::IncompatibleSubtraction,
                                        expectedMessage );
}



void MatrixTest::two1x2And2x1MatricesWhenAddedByShortHandThrowException(void)
{
    Matrix<double> oneByTwoMatrix(1, 2);
    Matrix<double> twoByOneMatrix(2, 1);

    std::string expectedMessage = "Cannot add [1, 2] and [2, 1]";
    CPPUNIT_ASSERT_THROW_WITH_MESSAGE ( oneByTwoMatrix += twoByOneMatrix,
                                        Exception::IncompatibleAddition,
                                        expectedMessage );
}

void MatrixTest::two1x2And2x1MatricesWhenSubtractedByShortHandThrowException(void)
{
    Matrix<double> oneByTwoMatrix(1, 2);
    Matrix<double> twoByOneMatrix(2, 1);

    std::string expectedMessage = "Cannot subtract [2, 1] from [1, 2]";
    CPPUNIT_ASSERT_THROW_WITH_MESSAGE ( oneByTwoMatrix -= twoByOneMatrix,
                                        Exception::IncompatibleSubtraction,
                                        expectedMessage );
}

void MatrixTest::two1x2And1x1MatricesWhenMultipliedThrowException(void)
{    
    Matrix<double> oneByTwoMatrix(1, 2);
    Matrix<double> oneByOneMatrix(1, 1);

    std::string expectedMessage = "Cannot multiply [1, 2] with [1, 1]";
    CPPUNIT_ASSERT_THROW_WITH_MESSAGE ( oneByTwoMatrix * oneByOneMatrix,
                                        Exception::IncompatibleMultiplication,
                                        expectedMessage );
}
