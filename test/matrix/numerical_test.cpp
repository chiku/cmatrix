// Written by     : Chirantan Mitra

#include <igloo/igloo_alt.h>
#include <matrix.h>

using namespace igloo;
using namespace CMatrix;

Describe(CMatrix_numerical)
{
    Describe(When_adding)
    {
        It(two_2x2_matrices_has_a_resultant_with_each_position_the_sum_of_the_two_matrices)
        {
            Matrix<double> firstTwoByTwoMatrix(2, 2);
            Matrix<double> secondTwoByTwoMatrix(2, 2);
            Matrix<double> expectedSum(2, 2);

            firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) = -1.0; expectedSum(0, 0) = 0.0;
            firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) =  2.0; expectedSum(0, 1) = 4.0;
            firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = -3.0; expectedSum(1, 0) = 0.0;
            firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) =  4.0; expectedSum(1, 1) = 8.0;

            Assert::That(firstTwoByTwoMatrix + secondTwoByTwoMatrix, Equals(expectedSum));
        }

        It(three_2x2_matrices_has_a_resultant_with_each_position_the_sum_of_the_three_matrices)
        {
            Matrix<double> firstTwoByTwoMatrix(2, 2);
            Matrix<double> secondTwoByTwoMatrix(2, 2);
            Matrix<double> thirdTwoByTwoMatrix(2, 2);
            Matrix<double> expectedSum(2, 2);

            firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) = -1.0; thirdTwoByTwoMatrix(0, 0) = -1.0; expectedSum(0, 0) = -1.0;
            firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) =  2.0; thirdTwoByTwoMatrix(0, 1) =  2.0; expectedSum(0, 1) =  6.0;
            firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = -3.0; thirdTwoByTwoMatrix(1, 0) =  3.0; expectedSum(1, 0) =  3.0;
            firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) =  4.0; thirdTwoByTwoMatrix(1, 1) =  4.0; expectedSum(1, 1) = 12.0;

            Assert::That(firstTwoByTwoMatrix + secondTwoByTwoMatrix + thirdTwoByTwoMatrix, Equals(expectedSum));
        }

        It(two_1x2_and_2x1_matrices_throws_an_exception)
        {
            Matrix<double> oneByTwoMatrix(1, 2);
            Matrix<double> twoByOneMatrix(2, 1);

            std::string expectedMessage = "Cannot add [1, 2] and [2, 1]";
            AssertThrows(Exception::IncompatibleAddition, oneByTwoMatrix + twoByOneMatrix);
            Assert::That(LastException<Exception::IncompatibleAddition>().what(), Equals(expectedMessage));
        }

        It(two_matrix_of_matrices_has_a_resultant_with_each_position_the_sum_of_the_component_matrices)
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

            Assert::That(firstMatrixOfMatrices + secondMatrixOfMatrices, Equals(expectedSum));
        }
    };

    Describe(When_subtracting)
    {
        It(two_2x2_matrices_has_a_resultant_with_each_position_the_difference_of_the_second_from_the_first)
        {
            Matrix<double> firstTwoByTwoMatrix(2, 2);
            Matrix<double> secondTwoByTwoMatrix(2, 2);
            Matrix<double> expectedDifference(2, 2);

            firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) = -1.0; expectedDifference(0, 0) = 2.0;
            firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) =  2.0; expectedDifference(0, 1) = 0.0;
            firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = -3.0; expectedDifference(1, 0) = 6.0;
            firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) =  4.0; expectedDifference(1, 1) = 0.0;

            Assert::That(firstTwoByTwoMatrix - secondTwoByTwoMatrix, Equals(expectedDifference));
        }

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
        Matrix<double> firstTwoByTwoMatrix;
        Matrix<double> secondTwoByTwoMatrix;
        Matrix<double> expectedSum;

        void SetUp()
        {
            firstTwoByTwoMatrix.setSize(2, 2);
            secondTwoByTwoMatrix.setSize(2, 2);
            expectedSum.setSize(2, 2);

            firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) = -1.0; expectedSum(0, 0) = 0.0;
            firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) =  2.0; expectedSum(0, 1) = 4.0;
            firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = -3.0; expectedSum(1, 0) = 0.0;
            firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) =  4.0; expectedSum(1, 1) = 8.0;
        }

        It(two_2x2_matrices_has_a_resultant_with_each_position_the_sum_of_the_two_matrices)
        {
            Assert::That(firstTwoByTwoMatrix += secondTwoByTwoMatrix, Equals(expectedSum));
        }

        It(mutates_the_first_matrix)
        {
            firstTwoByTwoMatrix += secondTwoByTwoMatrix;
            Assert::That(firstTwoByTwoMatrix, Equals(expectedSum));
        }

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
        Matrix<double> firstTwoByTwoMatrix;
        Matrix<double> secondTwoByTwoMatrix;
        Matrix<double> expectedDifference;

        void SetUp()
        {
            firstTwoByTwoMatrix.setSize(2, 2);
            secondTwoByTwoMatrix.setSize(2, 2);
            expectedDifference.setSize(2, 2);

            firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) = -1.0; expectedDifference(0, 0) = 2.0;
            firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) =  2.0; expectedDifference(0, 1) = 0.0;
            firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = -3.0; expectedDifference(1, 0) = 6.0;
            firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) =  4.0; expectedDifference(1, 1) = 0.0;
        }

        It(two_2x2_matrices_has_a_resultant_with_each_position_the_difference_of_the_second_from_the_first)
        {
            Assert::That(firstTwoByTwoMatrix -= secondTwoByTwoMatrix, Equals(expectedDifference));
        }

        It(mutates_the_first_matrix)
        {
            firstTwoByTwoMatrix -= secondTwoByTwoMatrix;
            Assert::That(firstTwoByTwoMatrix, Equals(expectedDifference));
        }

        It(a_2x1_matrix_from_a_1x2_matrix_throws_an_exception)
        {
            Matrix<double> oneByTwoMatrix(1, 2);
            Matrix<double> twoByOneMatrix(2, 1);

            std::string expectedMessage = "Cannot subtract [2, 1] from [1, 2]";
            AssertThrows(Exception::IncompatibleSubtraction, oneByTwoMatrix -= twoByOneMatrix);
            Assert::That(LastException<Exception::IncompatibleSubtraction>().what(), Equals(expectedMessage));
        }
    };

    Describe(When_unary_adding)
    {
        It(returns_a_matrix_whose_each_element_is_same_as_the_original)
        {
            Matrix<double> firstTwoByTwoMatrix(2, 2);
            Matrix<double> secondTwoByTwoMatrix(2, 2);

            firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) = 1.0;
            firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) = 2.0;
            firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = 3.0;
            firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) = 4.0;

            Assert::That(+firstTwoByTwoMatrix, Equals(secondTwoByTwoMatrix));
        }
    };

    Describe(When_unary_subtracting)
    {
        It(returns_a_matrix_whose_each_element_is_the_additive_inverse_of_the_original)
        {
            Matrix<double> firstTwoByTwoMatrix(2, 2);
            Matrix<double> secondTwoByTwoMatrix(2, 2);

            firstTwoByTwoMatrix(0, 0) =  1.0; secondTwoByTwoMatrix(0, 0) = -1.0;
            firstTwoByTwoMatrix(0, 1) =  2.0; secondTwoByTwoMatrix(0, 1) = -2.0;
            firstTwoByTwoMatrix(1, 0) = -3.0; secondTwoByTwoMatrix(1, 0) =  3.0;
            firstTwoByTwoMatrix(1, 1) =  4.0; secondTwoByTwoMatrix(1, 1) = -4.0;

            Assert::That(-firstTwoByTwoMatrix, Equals(secondTwoByTwoMatrix));
        }
    };

    Describe(When_multipling)
    {
        It(two_2x2_matrices_have_a_resultant_with_each_position_the_sum_of_vector_multiplication_of_the_two)
        {
            Matrix<double> firstTwoByTwoMatrix(2, 2);
            Matrix<double> secondTwoByTwoMatrix(2, 2);
            Matrix<double> expectedProduct(2, 2);

            firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) = -1.0; expectedProduct(0, 0) = -7.0;
            firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) =  2.0; expectedProduct(0, 1) = 10.0;
            firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = -3.0; expectedProduct(1, 0) = -15.0;
            firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) =  4.0; expectedProduct(1, 1) = 22.0;

            Assert::That(firstTwoByTwoMatrix * secondTwoByTwoMatrix, Equals(expectedProduct));
        }

        It(a_1x2_and_a_2x1_matrix_have_a_resultant_with_each_position_the_sum_of_vector_multiplication_of_the_two)
        {
            Matrix<double> oneByTwoMatrix(1, 2);
            Matrix<double> twoByOneMatrix(2, 1);
            Matrix<double> expectedProduct(1, 1);

            oneByTwoMatrix(0, 0) = 1.0; oneByTwoMatrix(0, 1) = -1.0;
            twoByOneMatrix(0, 0) = 2.0; twoByOneMatrix(1, 0) =  2.0;
            expectedProduct(0, 0) = 0.0;

            Assert::That(oneByTwoMatrix * twoByOneMatrix, Equals(expectedProduct));
        }

        It(a_1x2_matrix_with_a_1x1_matrix_throws_exception)
        {
            Matrix<double> oneByTwoMatrix(1, 2);
            Matrix<double> oneByOneMatrix(1, 1);

            std::string expectedMessage = "Cannot multiply [1, 2] with [1, 1]";
            AssertThrows(Exception::IncompatibleMultiplication, oneByTwoMatrix * oneByOneMatrix);
            Assert::That(LastException<Exception::IncompatibleMultiplication>().what(), Equals(expectedMessage));
        }
    };

    Describe(When_scaling)
    {
        Matrix<double> matrix;
        Matrix<double> result;

        void SetUp()
        {
            matrix.setSize(2, 1);
            matrix(0, 0) = -5.0;
            matrix(1, 0) = 4.0;

            result = matrix.scale(0.5);
        }

        It(has_same_size)
        {
            Assert::That(result.rows(), Equals(2));
            Assert::That(result.columns(), Equals(1));
        }

        It(multiplies_each_term_with_the_factor)
        {
            Assert::That(result(0, 0), Equals(-2.5));
            Assert::That(result(1, 0), Equals(2.0));
        }

        It(does_not_mutate_the_original_matrix)
        {
            Assert::That(matrix.rows(), Equals(2));
            Assert::That(matrix.columns(), Equals(1));

            Assert::That(matrix(0, 0), Equals(-5.0));
            Assert::That(matrix(1, 0), Equals(4.0));
        }
    };
};
