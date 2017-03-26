// Written by     : Chirantan Mitra

#include <igloo/igloo_alt.h>
#include <matrix.h>

using namespace igloo;

namespace cmatrix
{

Describe(cmatrix_properties)
{
    It(is_square_when_number_of_rows_and_columns_are_equal)
    {
        Matrix<double> firstMatrix(1, 1);
        Matrix<double> secondMatrix(3, 3);

        Assert::That(firstMatrix.isSquare(), IsTrue());
        Assert::That(secondMatrix.isSquare(), IsTrue());
    }

    It(is_not_square_when_number_of_rows_and_columns_are_unequal)
    {
        Matrix<double> firstMatrix(1, 2);
        Matrix<double> secondMatrix(3, 2);

        Assert::That(firstMatrix.isSquare(), IsFalse());
        Assert::That(secondMatrix.isSquare(), IsFalse());
    }

    Describe(When_square)
    {
        It(is_unit_if_all_diagonal_elements_are_one_and_others_are_zero)
        {
            Matrix<double> firstMatrix(1, 1);
            Matrix<double> secondMatrix(2, 2);

            firstMatrix(0, 0) = 1.0;
            secondMatrix(0, 0) = 1.0;    secondMatrix(0, 1) = 0.0;
            secondMatrix(1, 0) = 0.0;    secondMatrix(1, 1) = 1.0;

            Assert::That(firstMatrix.isUnit(), IsTrue());
            Assert::That(secondMatrix.isUnit(), IsTrue());
        }

        It(is_not_unit_if_some_diagonal_elements_are_not_one)
        {
            Matrix<double> firstMatrix(1, 1);
            Matrix<double> secondMatrix(2, 2);

            firstMatrix(0, 0) = -1.0;
            secondMatrix(0, 0) = 1.0;    secondMatrix(0, 1) = 0.0;
            secondMatrix(1, 0) = 0.0;    secondMatrix(1, 1) = -1.0;

            Assert::That(firstMatrix.isUnit(), IsFalse());
            Assert::That(secondMatrix.isUnit(), IsFalse());
        }

        It(is_not_unit_if_some_non_diagonal_elements_are_not_zero)
        {
            Matrix<double> firstMatrix(1, 1);
            Matrix<double> secondMatrix(2, 2);

            firstMatrix(0, 0) = -1.0;
            secondMatrix(0, 0) = 1.0;    secondMatrix(0, 1) = 1.0;
            secondMatrix(1, 0) = 0.0;    secondMatrix(1, 1) = 1.0;

            Assert::That(firstMatrix.isUnit(), IsFalse());
            Assert::That(secondMatrix.isUnit(), IsFalse());
        }
    };

    Describe(When_not_square)
    {
        It(is_not_unit)
        {
            Matrix<double> matrix(1, 2);

            matrix(0, 0) = 1.0;    matrix(0, 1) = 0.0;

            Assert::That(matrix.isUnit(), IsFalse());
        }
    };

    It(is_zero_if_all_elements_are_zero)
    {
        Matrix<double> matrix(1, 2);

        matrix(0, 0) = 0.0;    matrix(0, 1) = 0.0;

        Assert::That(matrix.isZero(), IsTrue());
    }

    It(is_not_zero_if_one_element_is_not_zero)
    {
        Matrix<double> matrix(1, 2);

        matrix(0, 0) = 0.0;    matrix(0, 1) = 1.0;

        Assert::That(matrix.isZero(), IsFalse());
    }
};

} // namespace cmatrix
