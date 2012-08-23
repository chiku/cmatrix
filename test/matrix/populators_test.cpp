// Written by     : Chirantan Mitra

#include <igloo/igloo_alt.h>
#include <matrix.h>

using namespace igloo;
using namespace CMatrix;

Describe(CMatrix_Populators)
{
	Describe(When_Filling)
	{
		It(PopulatesAllTheCellsWithTheGivenValue)
		{
			Matrix<double> matrix(2, 1);

			matrix.fillWith(-1.5);
			Assert::That(matrix(0, 0), Equals(-1.5));
			Assert::That(matrix(1, 0), Equals(-1.5));
		}

		It(DoesNotChangeTheMatrixSize)
		{
			Matrix<double> matrix(2, 1);

			matrix.fillWith(-1.5);
			Assert::That(matrix.rows(), Equals(2));
			Assert::That(matrix.columns(), Equals(1));
		}
	};

	Describe(When_Filling_With_Zeroes)
	{
		It(PopulatesAllTheCellsWithTheZero)
		{
			Matrix<double> matrix(2, 1);

			matrix.fillWithZeros();
			Assert::That(matrix(0, 0), Equals(0));
			Assert::That(matrix(1, 0), Equals(0));
		}

		It(DoesNotChangeTheMatrixSize)
		{
			Matrix<double> matrix(2, 1);

			matrix.fillWithZeros();
			Assert::That(matrix.rows(), Equals(2));
			Assert::That(matrix.columns(), Equals(1));
		}
	};
};
