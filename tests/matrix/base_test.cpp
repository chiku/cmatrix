// Written by     : Chirantan Mitra

#include <igloo/igloo_alt.h>
#include <matrix.h>

using namespace igloo;

namespace CMatrix
{

Describe(CMatrix_base)
{
    Describe(when_of_size_2x3_for_double)
    {
        It(has_2_rows)
        {
            Matrix<double> twoByThreeMatrix(2, 3);
            Assert::That(twoByThreeMatrix.rows(), Equals(2L));
        }

        It(has_3_columns)
        {
            Matrix<double> twoByThreeMatrix(2, 3);
            Assert::That(twoByThreeMatrix.columns(), Equals(3));
        }

        It(has_a_total_of_6_elements)
        {
            Matrix<double> twoByThreeMatrix(2, 3);
            Assert::That(twoByThreeMatrix.elements(), Equals(6));
        }

        It(stores_retrievable_values_at_all_6_locations)
        {
            Matrix<double> twoByThreeMatrix(2, 3);
            twoByThreeMatrix(0, 0) = -2;
            twoByThreeMatrix(0, 1) = -1;
            twoByThreeMatrix(0, 2) =  0;
            twoByThreeMatrix(1, 0) =  1;
            twoByThreeMatrix(1, 1) =  2;
            twoByThreeMatrix(1, 2) =  3;
            Assert::That(twoByThreeMatrix(0, 0), Equals(-2.0));
            Assert::That(twoByThreeMatrix(0, 1), Equals(-1.0));
            Assert::That(twoByThreeMatrix(0, 2), Equals( 0.0));
            Assert::That(twoByThreeMatrix(1, 0), Equals(1.0));
            Assert::That(twoByThreeMatrix(1, 1), Equals(2.0));
            Assert::That(twoByThreeMatrix(1, 2), Equals(3.0));
        }
    };

    Describe(When_of_size_1x1)
    {
        It(stores_retrievable_integer_values)
        {
            Matrix<int> oneByOneIntMatrix(1, 1);
            oneByOneIntMatrix(0, 0) = 10;
            Assert::That(oneByOneIntMatrix(0, 0), Equals(10));
        }

        It(stores_retrievable_double_values)
        {
            Matrix<double> oneByOneDoubleMatrix(1, 1);
            oneByOneDoubleMatrix(0, 0) = 10.0;
            Assert::That(oneByOneDoubleMatrix(0, 0), Equals(10.0));
        }
    };

    Describe(When_setting_size_1x1_after_creation)
    {
        Matrix<double> oneByOneMatrix;

        void SetUp()
        {
            oneByOneMatrix.setSize(1, 1);
        }

        It(has_1_row)
        {
            Assert::That(oneByOneMatrix.rows(), Equals(1L));
        }

        It(has_1_column)
        {
            Assert::That(oneByOneMatrix.columns(), Equals(1L));
        }

        It(stores_retrievable_value)
        {
            oneByOneMatrix(0, 0) = 1.0;
            Assert::That(oneByOneMatrix(0, 0), Equals(1.0));
        }
    };

    Describe(When_accessing_outside_row_bounds)
    {
        It(throws_an_exception)
        {
            Matrix<double> oneByTwoMatrix(1, 2);
            std::string expectedMessage = "Invalid attempt to access (1, 1) which lies outside bounds [1, 2]";
            AssertThrows(Exception::AccessOutOfBound, oneByTwoMatrix(1, 1));
            Assert::That(LastException<Exception::AccessOutOfBound>().what(), Equals(expectedMessage));
        }
    };

    Describe(When_assigning_outside_row_bounds)
    {
        It(throws_an_exception)
        {
            Matrix<double> oneByTwoMatrix(1, 2);
            std::string expectedMessage = "Invalid attempt to access (1, 1) which lies outside bounds [1, 2]";
            AssertThrows(Exception::AccessOutOfBound, oneByTwoMatrix(1, 1) = 5);
            Assert::That(LastException<Exception::AccessOutOfBound>().what(), Equals(expectedMessage));
        }
    };

    Describe(When_accessing_outside_column_bounds)
    {
        It(throws_an_exception)
        {
            Matrix<double> oneByTwoMatrix(1, 2);
            std::string expectedMessage = "Invalid attempt to access (0, 2) which lies outside bounds [1, 2]";
            AssertThrows(Exception::AccessOutOfBound, oneByTwoMatrix(0, 2));
            Assert::That(LastException<Exception::AccessOutOfBound>().what(), Equals(expectedMessage));
        }
    };

    Describe(When_assigning_outside_column_bounds)
    {
        It(throws_an_exception)
        {
            Matrix<double> oneByTwoMatrix(1, 2);
            std::string expectedMessage = "Invalid attempt to access (0, 2) which lies outside bounds [1, 2]";
            AssertThrows(Exception::AccessOutOfBound, oneByTwoMatrix(0, 2) = 5);
            Assert::That(LastException<Exception::AccessOutOfBound>().what(), Equals(expectedMessage));
        }
    };

    Describe(When_copied_by_equals_operator)
    {
        Matrix<double> firstTwoByTwoMatrix;

        void SetUp()
        {
            firstTwoByTwoMatrix.setSize(2, 2);
            firstTwoByTwoMatrix(0, 0) = 1.0;
            firstTwoByTwoMatrix(0, 1) = 2.0;
            firstTwoByTwoMatrix(1, 0) = 3.0;
            firstTwoByTwoMatrix(1, 1) = 4.0;
        }

        It(equals_the_original_matrix)
        {
            Matrix<double> secondTwoByTwoMatrix;
            secondTwoByTwoMatrix = firstTwoByTwoMatrix;
            Assert::That(firstTwoByTwoMatrix, Equals(secondTwoByTwoMatrix));
        }

        It(does_not_equal_the_original_matrix_after_copied_matrix_is_changed)
        {
            Matrix<double> secondTwoByTwoMatrix;
            secondTwoByTwoMatrix = firstTwoByTwoMatrix;
            secondTwoByTwoMatrix(1, 1) = -4.0;
            Assert::That(firstTwoByTwoMatrix, !Equals(secondTwoByTwoMatrix));
        }

        It(is_unaffected_by_changes_to_copied_matrix)
        {
            Matrix<double> secondTwoByTwoMatrix;
            secondTwoByTwoMatrix = firstTwoByTwoMatrix;
            secondTwoByTwoMatrix(1, 1) = -4.0;
            Assert::That(firstTwoByTwoMatrix(1, 1), Equals(4.0));
        }
    };

    Describe(When_copied_by_copy_constructor)
    {
        Matrix<double> firstTwoByTwoMatrix;

        void SetUp()
        {
            firstTwoByTwoMatrix.setSize(2, 2);
            firstTwoByTwoMatrix(0, 0) = 1.0;
            firstTwoByTwoMatrix(0, 1) = 2.0;
            firstTwoByTwoMatrix(1, 0) = 3.0;
            firstTwoByTwoMatrix(1, 1) = 4.0;
        }

        It(equals_the_original_matrix)
        {
            Matrix<double> secondTwoByTwoMatrix = firstTwoByTwoMatrix;
            Assert::That(firstTwoByTwoMatrix, Equals(secondTwoByTwoMatrix));
        }

        It(does_not_equal_the_original_matrix_after_copied_matrix_is_changed)
        {
            Matrix<double> secondTwoByTwoMatrix = firstTwoByTwoMatrix;
            secondTwoByTwoMatrix(1, 1) = -4.0;
            Assert::That(firstTwoByTwoMatrix, !Equals(secondTwoByTwoMatrix));
        }

        It(is_unaffected_by_changes_to_copied_matrix)
        {
            Matrix<double> secondTwoByTwoMatrix = firstTwoByTwoMatrix;
            secondTwoByTwoMatrix(1, 1) = -4.0;
            Assert::That(firstTwoByTwoMatrix(1, 1), Equals(4.0));
        }
    };

    Describe(When_rows_is_negative_during_creation)
    {
        It(throws_an_exception)
        {
            std::string expectedMessage = "Invalid attempt to set rows to -1 and columns to 0";
            AssertThrows(Exception::InvalidSizeSet, Matrix<double> bad0x0Matrix(-1, 0));
            Assert::That(LastException<Exception::InvalidSizeSet>().what(), Equals(expectedMessage));
        }
    };

    Describe(When_columns_is_negative_during_creation)
    {
        It(throws_an_exception)
        {
            std::string expectedMessage = "Invalid attempt to set rows to 0 and columns to -1";
            AssertThrows(Exception::InvalidSizeSet, Matrix<double> bad0x0Matrix(0, -1));
            Assert::That(LastException<Exception::InvalidSizeSet>().what(), Equals(expectedMessage));
        }
    };

    Describe(When_rows_is_negative_while_resizing_after_creation)
    {
        It(throws_an_exception)
        {
            std::string expectedMessage = "Invalid attempt to set rows to -1 and columns to 0";
            AssertThrows(Exception::InvalidSizeSet, Matrix<double> bad0x0Matrix(-1, 0));
            Assert::That(LastException<Exception::InvalidSizeSet>().what(), Equals(expectedMessage));
        }
    };

    Describe(When_columns_is_negative_while_resizing_after_creation)
    {
        It(throws_an_exception)
        {
            Matrix<double> bad0x0Matrix;
            std::string expectedMessage = "Invalid attempt to set rows to 1 and columns to -1";
            AssertThrows(Exception::InvalidSizeSet, bad0x0Matrix.setSize(1, -1));
            Assert::That(LastException<Exception::InvalidSizeSet>().what(), Equals(expectedMessage));
        }
    };

    Describe(When_resetting_rows_to_different_row_from_original_size)
    {
        It(throws_an_exception)
        {
            Matrix<double> a1x1Matrix(1, 1);
            std::string expectedMessage = "Invalid attempt to reset rows to 2 and columns to 2 from [1, 1]";
            AssertThrows(Exception::InvalidSizeReset, a1x1Matrix.setSize(2, 2));
            Assert::That(LastException<Exception::InvalidSizeReset>().what(), Equals(expectedMessage));
        }
    };

    Describe(When_resetting_columns_to_different_column_from_original_size)
    {
        It(throws_an_exception)
        {
            Matrix<double> a1x1Matrix(1, 1);
            std::string expectedMessage = "Invalid attempt to reset rows to 2 and columns to 0 from [1, 1]";
            AssertThrows(Exception::InvalidSizeReset, a1x1Matrix.setSize(2, 0));
            Assert::That(LastException<Exception::InvalidSizeReset>().what(), Equals(expectedMessage));
        }
    };

    Describe(When_resetting_size_to_same_as_original)
    {
        It(the_size_remains_same)
        {
            Matrix<double> a1x1Matrix(1, 1);
            a1x1Matrix.setSize(1, 1);
            Assert::That(a1x1Matrix.rows(), Equals(1));
            Assert::That(a1x1Matrix.columns(), Equals(1));
        }
    };

    Describe(Matrix_of_matrices)
    {
        It(has_retrievable_values)
        {
            Matrix<double> firstMatrix(1, 1);
            Matrix<double> secondMatrix(1, 1);
            Matrix<Matrix <double> > matrixOfMatrices(1, 2);

            firstMatrix(0, 0) = 1.0;
            secondMatrix(0, 0) = 2.0;
            matrixOfMatrices(0, 0) = firstMatrix;
            matrixOfMatrices(0, 1) = secondMatrix;

            Assert::That(matrixOfMatrices(0, 0)(0, 0), Equals(1.0));
            Assert::That(matrixOfMatrices(0, 1)(0, 0), Equals(2.0));
        }
    };
};

} // namespace CMatrix
