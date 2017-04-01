// Written by     : Chirantan Mitra

#include <igloo/igloo_alt.h>
#include <matrix.h>

using namespace igloo;

namespace cmatrix
{

Describe(cmatrix_numerical)
{
    Describe(When_adding)
    {
        It(two_1x2_and_2x1_matrices_throws_an_exception)
        {
            Matrix<double> oneByTwoMatrix(1, 2);
            Matrix<double> twoByOneMatrix(2, 1);

            std::string expectedMessage = "Cannot add [1, 2] and [2, 1]";
            AssertThrows(Exception::IncompatibleAddition, oneByTwoMatrix + twoByOneMatrix);
            Assert::That(LastException<Exception::IncompatibleAddition>().what(), Equals(expectedMessage));
        }
    };

    Describe(When_subtracting)
    {
        It(a_1x2_matrix_from_a_1x1_matrix_throws_an_exception)
        {
            Matrix<double> oneByTwoMatrix(1, 2);
            Matrix<double> oneByOneMatrix(1, 1);
            std::string expectedMessage = "Cannot subtract [1, 1] from [1, 2]";
            AssertThrows(Exception::IncompatibleSubtraction, oneByTwoMatrix - oneByOneMatrix);
            Assert::That(LastException<Exception::IncompatibleSubtraction>().what(), Equals(expectedMessage));
        }
    };

    Describe(When_adding_by_short_hand)
    {
        It(a_1x2_matrix_and_a_2x1_matrix_throws_exception)
        {
            Matrix<double> oneByTwoMatrix(1, 2);
            Matrix<double> twoByOneMatrix(2, 1);

            std::string expectedMessage = "Cannot add [1, 2] and [2, 1]";
            AssertThrows(Exception::IncompatibleAddition, oneByTwoMatrix += twoByOneMatrix);
            Assert::That(LastException<Exception::IncompatibleAddition>().what(), Equals(expectedMessage));
        }
    };

    Describe(When_subtracting_by_short_hand)
    {
        It(a_2x1_matrix_from_a_1x2_matrix_throws_an_exception)
        {
            Matrix<double> oneByTwoMatrix(1, 2);
            Matrix<double> twoByOneMatrix(2, 1);

            std::string expectedMessage = "Cannot subtract [2, 1] from [1, 2]";
            AssertThrows(Exception::IncompatibleSubtraction, oneByTwoMatrix -= twoByOneMatrix);
            Assert::That(LastException<Exception::IncompatibleSubtraction>().what(), Equals(expectedMessage));
        }
    };

    Describe(When_multipling)
    {
        It(a_1x2_matrix_with_a_1x1_matrix_throws_exception)
        {
            Matrix<double> oneByTwoMatrix(1, 2);
            Matrix<double> oneByOneMatrix(1, 1);

            std::string expectedMessage = "Cannot multiply [1, 2] with [1, 1]";
            AssertThrows(Exception::IncompatibleMultiplication, oneByTwoMatrix * oneByOneMatrix);
            Assert::That(LastException<Exception::IncompatibleMultiplication>().what(), Equals(expectedMessage));
        }
    };
};

} // namespace cmatrix
