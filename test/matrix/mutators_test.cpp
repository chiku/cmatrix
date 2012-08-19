// Written by     : Chirantan Mitra

#include <igloo/igloo_alt.h>
#include <matrix.h>

using namespace igloo;
using namespace CMatrix;

Describe(CMatrix_Mutators)
{
	Describe(When_Adding_An_Element_Inside_Boundary)
	{
		Matrix<double> matrix;

		void SetUp()
		{
			matrix.setSize(2, 2);
			matrix(0, 0) = 1.0;
			matrix(0, 1) = 2.0;
			matrix(1, 0) = 3.0;
			matrix(1, 1) = 4.0;

			matrix.mutateToInclude(-4.0, 0, 1);
		}

		It(DoesNotMutateTheBoundary)
		{
			Assert::That(matrix.rows(), Equals(2));
			Assert::That(matrix.columns(), Equals(2));
		}

		It(StoresTheSpecifiedValueAtTheSpecifiedLocation)
		{
			Assert::That(matrix(0, 1), Equals(-4.0));
		}

		It(DoesNotModifyOtherExistingValues)
		{
			Assert::That(matrix(0, 0), Equals(1.0));
			Assert::That(matrix(1, 0), Equals(3.0));
			Assert::That(matrix(1, 1), Equals(4.0));
		}
	};

	Describe(When_Adding_An_Element_Outside_Row_Boundary)
	{
		Matrix<double> matrix;

		void SetUp()
		{
			matrix.setSize(2, 2);
			matrix(0, 0) = 1.0;
			matrix(0, 1) = 2.0;
			matrix(1, 0) = 3.0;
			matrix(1, 1) = 4.0;

			matrix.mutateToInclude(4.0, 3, 0);
		}

		It(IncreasesTheBoundaryToIncludeTheElement)
		{
			Assert::That(matrix.rows(), Equals(4));
			Assert::That(matrix.columns(), Equals(2));
		}

		It(StoresTheSpecifiedValueAtTheSpecifiedLocation)
		{
			Assert::That(matrix(3, 0), Equals(4.0));
		}

		It(DoesNotModifyExistingValues)
		{
			Assert::That(matrix(0, 0), Equals(1.0));
			Assert::That(matrix(0, 1), Equals(2.0));
			Assert::That(matrix(1, 0), Equals(3.0));
			Assert::That(matrix(1, 1), Equals(4.0));
		}
	};

	Describe(When_Adding_An_Element_Outside_Column_Boundary)
	{
		Matrix<double> matrix;

		void SetUp()
		{
			matrix.setSize(2, 2);
			matrix(0, 0) = 1.0;
			matrix(0, 1) = 2.0;
			matrix(1, 0) = 3.0;
			matrix(1, 1) = 4.0;

			matrix.mutateToInclude(-4.0, 0, 4);
		}

		It(IncreasesTheBoundaryToIncludeTheElement)
		{
			Assert::That(matrix.rows(), Equals(2));
			Assert::That(matrix.columns(), Equals(5));
		}

		It(StoresTheSpecifiedValueAtTheSpecifiedLocation)
		{
			Assert::That(matrix(0, 4), Equals(-4.0));
		}

		It(DoesNotModifyExistingValues)
		{
			Assert::That(matrix(0, 0), Equals(1.0));
			Assert::That(matrix(0, 1), Equals(2.0));
			Assert::That(matrix(1, 0), Equals(3.0));
			Assert::That(matrix(1, 1), Equals(4.0));
		}
	};

	Describe(When_Adding_An_Element_Outside_Row_And_Column_Boundary)
	{
		Matrix<double> matrix;

		void SetUp()
		{
			matrix.setSize(2, 2);
			matrix(0, 0) = 1.0;
			matrix(0, 1) = 2.0;
			matrix(1, 0) = 3.0;
			matrix(1, 1) = 4.0;

			matrix.mutateToInclude(-11.5, 2, 5);
		}

		It(IncreasesTheBoundaryToIncludeTheElement)
		{
			Assert::That(matrix.rows(), Equals(3));
			Assert::That(matrix.columns(), Equals(6));
		}

		It(StoresTheSpecifiedValueAtTheSpecifiedLocation)
		{
			Assert::That(matrix(2, 5), Equals(-11.5));
		}

		It(DoesNotModifyExistingValues)
		{
			Assert::That(matrix(0, 0), Equals(1.0));
			Assert::That(matrix(0, 1), Equals(2.0));
			Assert::That(matrix(1, 0), Equals(3.0));
			Assert::That(matrix(1, 1), Equals(4.0));
		}
	};

	Describe(When_Adding_An_Element_At_The_End_Of_A_Matrix_With_One_Column)
	{
		Matrix<double> matrix;

		void SetUp()
		{
			matrix.setSize(2, 1);
			matrix(0, 0) = 1.0;
			matrix(1, 0) = 2.0;

			matrix.mutateToInclude(4.0, 2, 0);
		}

		It(IncreasesTheBoundaryToIncludeTheElement)
		{
			Assert::That(matrix.rows(), Equals(3));
			Assert::That(matrix.columns(), Equals(1));
		}

		It(StoresTheSpecifiedValueAtTheSpecifiedLocation)
		{
			Assert::That(matrix(2, 0), Equals(4.0));
		}

		It(DoesNotModifyExistingValues)
		{
			Assert::That(matrix(0, 0), Equals(1.0));
			Assert::That(matrix(1, 0), Equals(2.0));
		}
	};

	Describe(When_Adding_An_Element_At_The_End_Of_A_Matrix_With_One_Row)
	{
		Matrix<double> matrix;

		void SetUp()
		{
			matrix.setSize(1, 2);
			matrix(0, 0) = 1.0;
			matrix(0, 1) = 2.0;

			matrix.mutateToInclude(4.0, 0, 2);
		}

		It(IncreasesTheBoundaryToIncludeTheElement)
		{
			Assert::That(matrix.rows(), Equals(1));
			Assert::That(matrix.columns(), Equals(3));
		}

		It(StoresTheSpecifiedValueAtTheSpecifiedLocation)
		{
			Assert::That(matrix(0, 2), Equals(4.0));
		}

		It(DoesNotModifyExistingValues)
		{
			Assert::That(matrix(0, 0), Equals(1.0));
			Assert::That(matrix(0, 1), Equals(2.0));
		}
	};

	Describe(When_Adding_An_Element_At_Negative_Boundary)
	{
		It(ThrowsAnException)
		{
			Matrix<double> matrix(2, 2);
            std::string expectedMessage = "Invalid attempt to add element at negative row (-2) or column (2) to matrix [2, 2]";
            AssertThrows(Exception::InvalidSizeReset, matrix.mutateToInclude(0.0, -2, 2));
            Assert::That(LastException<Exception::InvalidSizeReset>().what(), Equals(expectedMessage));
		}
	};
};