// Written by     : Chirantan Mitra

#include <igloo/igloo_alt.h>
#include <matrix.h>

using namespace igloo;

namespace cmatrix
{

Describe(When_inverting_a_unitary_matrix)
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

    It(has_same_number_of_rows)
    {
        Assert::That(invertedMatrix.rows(), Equals(2));
    }

    It(has_same_number_of_columns)
    {
        Assert::That(invertedMatrix.columns(), Equals(2));
    }

    It(is_the_unitary_matrix)
    {
        Assert::That(invertedMatrix(0, 0), Equals(1)); Assert::That(invertedMatrix(0, 1), Equals(0));
        Assert::That(invertedMatrix(1, 0), Equals(0)); Assert::That(invertedMatrix(1, 1), Equals(1));
    }
};

Describe(When_inverting_a_matrix)
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

    It(gives_the_unitary_matrix_on_multiplying_the_result_with_itself)
    {
        Assert::That((matrix * invertedMatrix).isUnit(), IsTrue());
    }

    It(does_not_mutate_the_original_matrix)
    {
        Assert::That(matrix == invertedMatrix, IsFalse());
    }
};

Describe(When_inverting_a_matrix_with_size_1x1)
{
    It(finds_its_inverse)
    {
        Matrix<double> matrix(1, 1);
        matrix(0, 0) = -1.0;
        Matrix<double> expectedInvertedMatrix(1, 1);
        expectedInvertedMatrix(0, 0) = -1.0;

        Assert::That(matrix.invert(), Equals(expectedInvertedMatrix));
    }
};

Describe(When_inverting_a_non_square_matrix)
{
    It(throws_an_exception)
    {
        Matrix<double> nonSquareMatrix(2, 3);

        std::string expectedMessage = "Cannot invert a non-square matrix [2, 3]";
        AssertThrows(Exception::InversionNotPossible, nonSquareMatrix.invert());
        Assert::That(LastException<Exception::InversionNotPossible>().what(), Equals(expectedMessage));
    }
};

Describe(When_inverting_a_singular_matrix)
{
    It(throws_an_exception)
    {
        Matrix<double> singularMatrix(2, 2);
        singularMatrix(0, 0) = 1.0; singularMatrix(0, 1) = 0.0;
        singularMatrix(1, 0) = 0.0; singularMatrix(1, 1) = 0.0;

        std::string expectedMessage = "Cannot invert a singular matrix";
        AssertThrows(Exception::InversionNotPossible, singularMatrix.invert());
        Assert::That(LastException<Exception::InversionNotPossible>().what(), Equals(expectedMessage));
    }
};

} // namespace cmatrix
