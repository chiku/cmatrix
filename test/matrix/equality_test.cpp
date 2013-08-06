// Written by     : Chirantan Mitra

#include <igloo/igloo_alt.h>
#include <matrix.h>

using namespace igloo;
using namespace CMatrix;

Describe(CMatrix_equality)
{
    Describe(Does_not_equal_matrix)
    {
        It(with_different_row_count)
        {
            Matrix<double> oneByTwoMatrix(1, 2);
            Matrix<double> twoByTwoMatrix(2, 2);

            Assert::That(oneByTwoMatrix == twoByTwoMatrix, IsFalse());
            Assert::That(oneByTwoMatrix != twoByTwoMatrix, IsTrue());
        }

        It(with_different_column_count)
        {
            Matrix<double> oneByTwoMatrix(1, 2);
            Matrix<double> oneByThreeMatrix(1, 3);

            Assert::That(oneByTwoMatrix == oneByThreeMatrix, IsFalse());
            Assert::That(oneByTwoMatrix != oneByThreeMatrix, IsTrue());
        }

        It(with_a_different_element)
        {
            Matrix<double> firstTwoByTwoMatrix(2, 2);
            Matrix<double> secondTwoByTwoMatrix(2, 2);

            firstTwoByTwoMatrix(0, 0) = 1.0; secondTwoByTwoMatrix(0, 0) =  1.0;
            firstTwoByTwoMatrix(0, 1) = 2.0; secondTwoByTwoMatrix(0, 1) =  2.0;
            firstTwoByTwoMatrix(1, 0) = 3.0; secondTwoByTwoMatrix(1, 0) = -3.0;
            firstTwoByTwoMatrix(1, 1) = 4.0; secondTwoByTwoMatrix(1, 1) =  4.0;

            Assert::That(firstTwoByTwoMatrix == secondTwoByTwoMatrix, IsFalse());
            Assert::That(firstTwoByTwoMatrix != secondTwoByTwoMatrix, IsTrue());
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

            Assert::That(firstTwoByTwoMatrix == secondTwoByTwoMatrix, IsTrue());
            Assert::That(firstTwoByTwoMatrix != secondTwoByTwoMatrix, IsFalse());
        }
    };

    Describe(Matrix_Of_Matrices)
    {
        It(equals_another_matrix_of_matrices_when_all_component_matrices_are_equal)
        {
            Matrix<Matrix <double> > firstMatrix(1, 2);
            Matrix<Matrix <double> > secondMatrix(1, 2);

            Matrix<double> firstMatrix0x0(1, 1);    Matrix<double> firstMatrix0x1(2, 1);
            Matrix<double> secondMatrix0x0(1, 1);   Matrix<double> secondMatrix0x1(2, 1);

            firstMatrix0x0(0, 0) =  1.0; secondMatrix0x0(0, 0) =  1.0;
            firstMatrix0x1(0, 0) =  3.0; secondMatrix0x1(0, 0) =  3.0;
            firstMatrix0x1(1, 0) = -1.0; secondMatrix0x1(1, 0) = -1.0;

            firstMatrix(0, 0) = firstMatrix0x0; secondMatrix(0, 0) = secondMatrix0x0;
            firstMatrix(0, 1) = firstMatrix0x1; secondMatrix(0, 1) = secondMatrix0x1;

            Assert::That(firstMatrix == secondMatrix), IsTrue();
        }

        It(does_not_equal_another_matrix_of_matrices_when_one_component_matrix_is_not_equal)
        {
            Matrix<Matrix <double> > firstMatrix(1, 2);
            Matrix<Matrix <double> > secondMatrix(1, 2);

            Matrix<double> firstMatrix0x0(1, 1);    Matrix<double> firstMatrix0x1(2, 1);
            Matrix<double> secondMatrix0x0(1, 1);   Matrix<double> secondMatrix0x1(2, 1);

            firstMatrix0x0(0, 0) =  1.0; secondMatrix0x0(0, 0) =  1.0;
            firstMatrix0x1(0, 0) =  3.0; secondMatrix0x1(0, 0) =  3.0;
            firstMatrix0x1(1, 0) = -1.0; secondMatrix0x1(1, 0) =  1.0;

            firstMatrix(0, 0) = firstMatrix0x0; secondMatrix(0, 0) = secondMatrix0x0;
            firstMatrix(0, 1) = firstMatrix0x1; secondMatrix(0, 1) = secondMatrix0x1;

            Assert::That(firstMatrix != secondMatrix, IsTrue());
        }
    };
};
