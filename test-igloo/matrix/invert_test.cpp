// Written by     : Chirantan Mitra

#include <igloo/igloo_alt.h>
#include <matrix.h>

using namespace igloo;

namespace cmatrix
{

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
