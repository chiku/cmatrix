// Written by     : Chirantan Mitra

#include <igloo/igloo_alt.h>
#include <matrix.h>

using namespace igloo;
using namespace CMatrix;

Describe(When_Inverting_A_Unitary_Matrix)
{
    Matrix<double> unitaryMatrix;
    Matrix<double> invertedMatrix;

    void SetUp()
    {
        unitaryMatrix.setSize(2, 2);
        unitaryMatrix(0, 0) = 1.0; unitaryMatrix(0, 1) = 0.0;
        unitaryMatrix(1, 0) = 0.0; unitaryMatrix(1, 1) = 1.0;

        invertedMatrix = unitaryMatrix.invert();
    }

    It(HasSameNumberOfRows)
    {
        Assert::That(invertedMatrix.rows(), Equals(2));
    }

    It(HasSameNumberOfColumns)
    {
        Assert::That(invertedMatrix.columns(), Equals(2));
    }

    It(IsTheUnitaryMatrix)
    {
        Assert::That(invertedMatrix(0, 0), Equals(1)); Assert::That(invertedMatrix(0, 1), Equals(0));
        Assert::That(invertedMatrix(1, 0), Equals(0)); Assert::That(invertedMatrix(1, 1), Equals(1));
    }
};

Describe(When_Inverting_A_Matrix)
{
    Matrix<double> matrix;
    Matrix<double> invertedMatrix;

    void SetUp()
    {
        matrix.setSize(3, 3);
        matrix(0, 0) = 1.0; matrix(0, 1) = 3.0; matrix(0, 2) = 3.0;
        matrix(1, 0) = 1.0; matrix(1, 1) = 4.0; matrix(1, 2) = 3.0;
        matrix(2, 0) = 1.0; matrix(2, 1) = 3.0; matrix(2, 2) = 4.0; 

        invertedMatrix = matrix.invert();
    }

    It(GivesTheUnitaryMatrixOnMultiplyingTheResultWithItself)
    {
        Assert::That((matrix * invertedMatrix).isUnit(), IsTrue());
    }

    It(DoesNotMutateTheOriginalMatrix)
    {
        Assert::That(matrix == invertedMatrix, IsFalse());
    }
};

Describe(When_Inverting_A_Matrix_With_Size_One)
{
    It(FindsItsInverse)
    {
        Matrix<double> matrix(1, 1);
        matrix(0, 0) = -1.0;
        Matrix<double> expectedInvertedMatrix(1, 1);
        expectedInvertedMatrix(0, 0) = -1.0;

        Assert::That(matrix.invert(), Equals(expectedInvertedMatrix));
    }
};

Describe(When_Inverting_A_Non_Square_Matrix)
{
    It(ThrowsException)
    {
        Matrix<double> nonSquareMatrix(2, 3);

        std::string expectedMessage = "Cannot invert a non-square matrix [2, 3]";
        AssertThrows(Exception::InversionNotPossible, nonSquareMatrix.invert());
        Assert::That(LastException<Exception::InversionNotPossible>().what(), Equals(expectedMessage));
    }
};

Describe(When_Inverting_A_Singular_Matrix)
{
    It(ThrowsException)
    {
        Matrix<double> singularMatrix(2, 2);
        singularMatrix(0, 0) = 1.0; singularMatrix(0, 1) = 0.0;
        singularMatrix(1, 0) = 0.0; singularMatrix(1, 1) = 0.0;

        std::string expectedMessage = "Cannot invert a singular matrix";
        AssertThrows(Exception::InversionNotPossible, singularMatrix.invert());
        Assert::That(LastException<Exception::InversionNotPossible>().what(), Equals(expectedMessage));
    }
};
