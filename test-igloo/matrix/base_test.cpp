// Written by     : Chirantan Mitra

#include <igloo/igloo_alt.h>
#include <matrix.h>

using namespace igloo;

namespace cmatrix
{

Describe(cmatrix_base)
{
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
};

} // namespace cmatrix
