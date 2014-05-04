// Written by     : Chirantan Mitra

#include <igloo/igloo_alt.h>
#include <matrix.h>

using namespace igloo;

namespace CMatrix
{

Describe(CMatrix_equality_with_tolerance)
{
    Describe(Does_not_equal_matrix)
    {
        It(with_different_row_count)
        {
            Matrix<double> oneByTwoMatrix(1, 2);
            Matrix<double> twoByTwoMatrix(2, 2);

            Assert::That(oneByTwoMatrix.equalWithTolerance(twoByTwoMatrix, 0.1), IsFalse());
        }

        It(with_different_column_count)
        {
            Matrix<double> oneByTwoMatrix(1, 2);
            Matrix<double> oneByThreeMatrix(1, 3);

            Assert::That(oneByTwoMatrix.equalWithTolerance(oneByThreeMatrix, 0.1), IsFalse());
        }

        It(with_an_element_outside_tolerance_limit)
        {
            Matrix<double> firstTwoByTwoMatrix(2, 2);
            Matrix<double> secondTwoByTwoMatrix(2, 2);

            firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) =  1.0;
            firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) =  2.0;
            firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = -3.0;
            firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) =  4.0;

            Assert::That(firstTwoByTwoMatrix.equalWithTolerance(secondTwoByTwoMatrix, 0.1), IsFalse());
        }
    };

    Describe(Equals_another_matrix)
    {
        It(with_same_row_count_and_column_count_and_same_elements_in_same_position)
        {
            Matrix<double> firstTwoByTwoMatrix(2, 2);
            Matrix<double> secondTwoByTwoMatrix(2, 2);

            firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) = 1.0;
            firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) = 2.0;
            firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = 3.0;
            firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) = 4.0;

            Assert::That(firstTwoByTwoMatrix.equalWithTolerance(secondTwoByTwoMatrix, 0.1), IsTrue());
        }

        It(with_same_row_count_and_column_count_and_elements_different_inside_tolerance_limits)
        {
            Matrix<double> firstTwoByTwoMatrix(2, 2);
            Matrix<double> secondTwoByTwoMatrix(2, 2);

            firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) = 1.0;
            firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) = 1.95;
            firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = 3.05;
            firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) = 4.0;

            Assert::That(firstTwoByTwoMatrix.equalWithTolerance(secondTwoByTwoMatrix, 0.1), IsTrue());
        }
    };
};

} // namespace CMatrix
