// Written by     : Chirantan Mitra

#include <matrix_test.h>

void MatrixTest::aUnitaryMatrixGivesBackTheSameUnitaryMatrixOnInversion()
{
    Matrix<double> unitaryMatrix(2, 2);
    unitaryMatrix(0, 0) = 1.0; unitaryMatrix(0, 1) = 0.0;
    unitaryMatrix(1, 0) = 0.0; unitaryMatrix(1, 1) = 1.0;

    Matrix<double> invertedMatrix = unitaryMatrix.invert();

    CPPUNIT_ASSERT (invertedMatrix.rows() == 2);
    CPPUNIT_ASSERT (invertedMatrix.columns() == 2);

    CPPUNIT_ASSERT (invertedMatrix(0, 0) == 1); CPPUNIT_ASSERT (invertedMatrix(0, 1) == 0);
    CPPUNIT_ASSERT (invertedMatrix(1, 0) == 0); CPPUNIT_ASSERT (invertedMatrix(1, 1) == 1);
}

void MatrixTest::aMatrixGivesBackAUnitaryMatrixOnInversionAfterMultiplingWithItsInverse()
{
    Matrix<double> matrix(3, 3);

    matrix(0, 0) = 1.0; matrix(0, 1) = 3.0; matrix(0, 2) = 3.0;
    matrix(1, 0) = 1.0; matrix(1, 1) = 4.0; matrix(1, 2) = 3.0;
    matrix(2, 0) = 1.0; matrix(2, 1) = 3.0; matrix(2, 2) = 4.0; 

    Matrix<double> invertedMatrix = matrix.invert();

    CPPUNIT_ASSERT ((matrix * invertedMatrix).isUnit());
}

void MatrixTest::aMatrixDoesNotMutateOnInversion()
{
    Matrix<double> matrix(2, 2);

    matrix(0, 0) = 1.0; matrix(0, 1) = 3.0;
    matrix(1, 0) = 1.0; matrix(1, 1) = 4.0;

    Matrix<double> invertedMatrix = matrix.invert();

    CPPUNIT_ASSERT (matrix != invertedMatrix);
}

void MatrixTest::aMatrixWithOneElementHasAnInverse()
{
    Matrix<double> matrix(1, 1);
    matrix(0, 0) = -1.0;

    Matrix<double> expectedInvertedMatrix(1, 1);
    expectedInvertedMatrix(0, 0) = -1.0;

    CPPUNIT_ASSERT (matrix.invert() == expectedInvertedMatrix);
}

void MatrixTest::aThrowsExceptionWhenInvertingANonSquareMatrix()
{
    Matrix<double> nonSquareMatrix(2, 3);

    std::string expectedMessage = "Cannot invert a non-square matrix [2, 3]";
    CPPUNIT_ASSERT_THROW_WITH_MESSAGE (nonSquareMatrix.invert(),
                                       Exception::InversionNotPossible,
                                       expectedMessage);
}

void MatrixTest::aThrowsExceptionWhenInvertingASingularMatrix()
{
    Matrix<double> singularMatrix(2, 2);
    singularMatrix(0, 0) = 1.0; singularMatrix(0, 1) = 0.0;
    singularMatrix(1, 0) = 0.0; singularMatrix(1, 1) = 0.0;

    std::string expectedMessage = "Cannot invert a singular matrix";
    CPPUNIT_ASSERT_THROW_WITH_MESSAGE (singularMatrix.invert(),
                                       Exception::InversionNotPossible,
                                       expectedMessage);
}
