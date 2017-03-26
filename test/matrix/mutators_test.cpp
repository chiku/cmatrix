// Written by     : Chirantan Mitra

#include <igloo/igloo_alt.h>
#include <matrix.h>

using namespace igloo;

namespace cmatrix
{

Describe(cmatrix_mutators)
{
	Describe(When_adding_an_element_inside_boundary)
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

		It(does_not_mutate_the_size)
		{
			Assert::That(matrix.rows(), Equals(2));
			Assert::That(matrix.columns(), Equals(2));
		}

		It(stores_the_specified_value_at_the_specified_location)
		{
			Assert::That(matrix(0, 1), Equals(-4.0));
		}

		It(does_not_modify_other_existing_values)
		{
			Assert::That(matrix(0, 0), Equals(1.0));
			Assert::That(matrix(1, 0), Equals(3.0));
			Assert::That(matrix(1, 1), Equals(4.0));
		}
	};

	Describe(When_adding_an_element_outside_row_boundary)
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

		It(increases_the_boundary_to_include_the_element)
		{
			Assert::That(matrix.rows(), Equals(4));
			Assert::That(matrix.columns(), Equals(2));
		}

		It(stores_the_specified_value_at_the_specified_location)
		{
			Assert::That(matrix(3, 0), Equals(4.0));
		}

		It(does_not_modify_existing_values)
		{
			Assert::That(matrix(0, 0), Equals(1.0));
			Assert::That(matrix(0, 1), Equals(2.0));
			Assert::That(matrix(1, 0), Equals(3.0));
			Assert::That(matrix(1, 1), Equals(4.0));
		}
	};

	Describe(When_adding_an_element_outside_column_boundary)
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

		It(increases_the_boundary_to_include_the_element)
		{
			Assert::That(matrix.rows(), Equals(2));
			Assert::That(matrix.columns(), Equals(5));
		}

		It(stores_the_specified_value_at_the_specified_location)
		{
			Assert::That(matrix(0, 4), Equals(-4.0));
		}

		It(does_not_modify_existing_values)
		{
			Assert::That(matrix(0, 0), Equals(1.0));
			Assert::That(matrix(0, 1), Equals(2.0));
			Assert::That(matrix(1, 0), Equals(3.0));
			Assert::That(matrix(1, 1), Equals(4.0));
		}
	};

	Describe(When_adding_an_element_outside_row_and_column_boundary)
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

		It(increases_the_boundary_to_include_the_element)
		{
			Assert::That(matrix.rows(), Equals(3));
			Assert::That(matrix.columns(), Equals(6));
		}

		It(stores_the_specified_value_at_the_specified_location)
		{
			Assert::That(matrix(2, 5), Equals(-11.5));
		}

		It(does_not_modify_existing_values)
		{
			Assert::That(matrix(0, 0), Equals(1.0));
			Assert::That(matrix(0, 1), Equals(2.0));
			Assert::That(matrix(1, 0), Equals(3.0));
			Assert::That(matrix(1, 1), Equals(4.0));
		}
	};

	Describe(When_adding_an_element_to_an_zero_sized_matrix)
	{
		It(increases_the_boundary_to_include_the_element)
		{
			Matrix<double> matrix;
			matrix.mutateToInclude(4.0, 0, 0);

			Assert::That(matrix.rows(), Equals(1));
			Assert::That(matrix.columns(), Equals(1));
		}

		It(stores_the_specified_value_at_the_specified_location)
		{
			Matrix<double> matrix;
			matrix.mutateToInclude(4.0, 0, 0);

			Assert::That(matrix(0, 0), Equals(4.0));
		}
	};

	Describe(When_adding_an_element_at_negative_boundary)
	{
		It(throws_an_exception)
		{
			Matrix<double> matrix(2, 2);
            std::string expectedMessage = "Invalid attempt to add element at negative row (-2) or column (2) to matrix [2, 2]";
            AssertThrows(Exception::InvalidSizeReset, matrix.mutateToInclude(0.0, -2, 2));
            Assert::That(LastException<Exception::InvalidSizeReset>().what(), Equals(expectedMessage));
		}
	};
};

} // namespace cmatrix
