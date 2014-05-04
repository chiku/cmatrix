// Written by     : Chirantan Mitra

#include <igloo/igloo_alt.h>
#include <matrix.h>

using namespace igloo;

namespace cmatrix
{

Describe(cmatrix_populators)
{
	Describe(When_filling)
	{
		It(populates_all_the_cells_with_the_given_value)
		{
			Matrix<double> matrix(2, 1);

			matrix.fillWith(-1.5);
			Assert::That(matrix(0, 0), Equals(-1.5));
			Assert::That(matrix(1, 0), Equals(-1.5));
		}

		It(does_not_change_the_matrix_size)
		{
			Matrix<double> matrix(2, 1);

			matrix.fillWith(-1.5);
			Assert::That(matrix.rows(), Equals(2));
			Assert::That(matrix.columns(), Equals(1));
		}
	};

	Describe(When_filling_with_zeroes)
	{
		It(populates_all_the_cells_with_the_zero)
		{
			Matrix<double> matrix(2, 1);

			matrix.fillWithZeros();
			Assert::That(matrix(0, 0), Equals(0));
			Assert::That(matrix(1, 0), Equals(0));
		}

		It(does_not_change_the_matrix_size)
		{
			Matrix<double> matrix(2, 1);

			matrix.fillWithZeros();
			Assert::That(matrix.rows(), Equals(2));
			Assert::That(matrix.columns(), Equals(1));
		}
	};
};

} // namespace cmatrix
