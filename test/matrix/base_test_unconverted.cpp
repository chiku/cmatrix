// Written by     : Chirantan Mitra

#include <matrix_test.h>

CPPUNIT_TEST_SUITE_REGISTRATION (MatrixTest);

void MatrixTest::setUp()
{
}

void MatrixTest::tearDown()
{
}


void MatrixTest::attemptToAccessOutsizeRowBoundsThrowsException(void)
{
    Matrix<double> oneByTwoMatrix(1, 2);
    std::string expectedMessage = "Invalid attempt to access (1, 1) which lies outside bounds [1, 2]";
    CPPUNIT_ASSERT_THROW_WITH_MESSAGE ( oneByTwoMatrix(1, 1),
                                        Exception::AccessOutOfBound,
                                        expectedMessage );
}

void MatrixTest::attemptToAssignOutsizeRowBoundsThrowsException(void)
{
    Matrix<double> oneByTwoMatrix(1, 2);
    std::string expectedMessage = "Invalid attempt to access (1, 1) which lies outside bounds [1, 2]";
    CPPUNIT_ASSERT_THROW_WITH_MESSAGE ( (oneByTwoMatrix(1, 1) = 5),
                                        Exception::AccessOutOfBound,
                                        expectedMessage );
}

void MatrixTest::attemptToAccessOutsizeColumnBoundsThrowsException(void)
{
    Matrix<double> oneByTwoMatrix(1, 2);
    std::string expectedMessage = "Invalid attempt to access (0, 2) which lies outside bounds [1, 2]";
    CPPUNIT_ASSERT_THROW_WITH_MESSAGE ( oneByTwoMatrix(0, 2),
                                        Exception::AccessOutOfBound,
                                        expectedMessage );
}

void MatrixTest::attemptToAssignOutsizeColumnBoundsThrowsException(void)
{
    Matrix<double> oneByTwoMatrix(1, 2);
    std::string expectedMessage = "Invalid attempt to access (0, 2) which lies outside bounds [1, 2]";
    CPPUNIT_ASSERT_THROW_WITH_MESSAGE ( (oneByTwoMatrix(0, 2) = 5),
                                        Exception::AccessOutOfBound,
                                        expectedMessage );
}


void MatrixTest::matrixSizeNotSetAsNaturalNumbersDuringCreationThrowsException(void)
{
    std::string expectedMessage = "Invalid attempt to set rows to 0 and columns to 0";
    CPPUNIT_ASSERT_THROW_WITH_MESSAGE ( Matrix<double> firstBad0x0Matrix(0, 0),
                                        Exception::InvalidSizeSet,
                                        expectedMessage);
}

void MatrixTest::matrixSizeNotSetAsNaturalNumbersWhenSettingSizeAftferCreationThrowsException(void)
{
    Matrix<double> secondBad0x0Matrix;
    std::string expectedMessage = "Invalid attempt to set rows to 1 and columns to 0";
    CPPUNIT_ASSERT_THROW_WITH_MESSAGE ( secondBad0x0Matrix.setSize(1, 0),
                                        Exception::InvalidSizeSet,
                                        expectedMessage);
}

void MatrixTest::matrixSizeOnResettingAfterOnceSetThrowsException(void)
{
    Matrix<double> first1x1Matrix(1, 1);
    CPPUNIT_ASSERT_THROW_WITH_MESSAGE ( first1x1Matrix.setSize(2, 2),
                                        Exception::InvalidSizeReset,
                                        "Invalid attempt to reset rows to 2 and columns to 2 from [1, 1]");

    Matrix<double> second1x1Matrix(1, 1);
    CPPUNIT_ASSERT_THROW_WITH_MESSAGE ( second1x1Matrix.setSize(2, 0),
                                        Exception::InvalidSizeReset,
                                        "Invalid attempt to reset rows to 2 and columns to 0 from [1, 1]");
}


void MatrixTest::matrixSizeOnResettingToSameSizeAfterOnceSetDoesNotThrowException(void)
{
    Matrix<double> first1x1Matrix(1, 1);
    CPPUNIT_ASSERT_NO_THROW (first1x1Matrix.setSize(1, 1));
}
