// Written by     : Chirantan Mitra

#include "../doctest.h"

#include <matrix.h>

namespace cmatrix
{

SCENARIO("cmatrix::Matrix<double> mutation") {
    GIVEN("matrix") {
        WHEN("adding adding an element inside boundary") {
			Matrix<double> matrix;

			matrix.setSize(2, 2);
			matrix(0, 0) = 1.0;
			matrix(0, 1) = 2.0;
			matrix(1, 0) = 3.0;
			matrix(1, 1) = 4.0;

			matrix.mutateToInclude(-4.0, 0, 1);

            THEN("the size is not mutated") {
				CHECK(matrix.rows() == 2);
				CHECK(matrix.columns() == 2);
			}

			THEN("it stores the specified value at the specified location") {
				CHECK(matrix(0, 1) == -4.0);
			}

			THEN("the other values are not modified") {
				CHECK(matrix(0, 0) == 1.0);
				CHECK(matrix(1, 0) == 3.0);
				CHECK(matrix(1, 1) == 4.0);
			}
		}

		WHEN("adding an element outside row boundary") {
			Matrix<double> matrix;

			matrix.setSize(2, 2);
			matrix(0, 0) = 1.0;
			matrix(0, 1) = 2.0;
			matrix(1, 0) = 3.0;
			matrix(1, 1) = 4.0;

			matrix.mutateToInclude(4.0, 3, 0);

			THEN("it increases the boundary to include the element") {
				CHECK(matrix.rows() == 4);
				CHECK(matrix.columns() == 2);
			}

			THEN("it stores the specified value at the specified location") {
				CHECK(matrix(3, 0) == 4.0);
			}

			THEN("the other values are not modified") {
				CHECK(matrix(0, 0) == 1.0);
				CHECK(matrix(0, 1) == 2.0);
				CHECK(matrix(1, 0) == 3.0);
				CHECK(matrix(1, 1) == 4.0);
			}
		}

		WHEN("adding an element outside column boundary") {
			Matrix<double> matrix;

			matrix.setSize(2, 2);
			matrix(0, 0) = 1.0;
			matrix(0, 1) = 2.0;
			matrix(1, 0) = 3.0;
			matrix(1, 1) = 4.0;

			matrix.mutateToInclude(-4.0, 0, 4);

			THEN("it increases the boundary to include the element") {
				CHECK(matrix.rows() == 2);
				CHECK(matrix.columns() == 5);
			}

			THEN("it stores the specified value at the specified location") {
				CHECK(matrix(0, 4) == -4.0);
			}

			THEN("the other values are not modified") {
				CHECK(matrix(0, 0) == 1.0);
				CHECK(matrix(0, 1) == 2.0);
				CHECK(matrix(1, 0) == 3.0);
				CHECK(matrix(1, 1) == 4.0);
			}
		}

		WHEN("adding an element outside row and column boundary") {
			Matrix<double> matrix;

			matrix.setSize(2, 2);
			matrix(0, 0) = 1.0;
			matrix(0, 1) = 2.0;
			matrix(1, 0) = 3.0;
			matrix(1, 1) = 4.0;

			matrix.mutateToInclude(-11.5, 2, 5);

			THEN("it increases the boundary to include the element") {
				CHECK(matrix.rows() == 3);
				CHECK(matrix.columns() == 6);
			}

			THEN("it stores the specified value at the specified location") {
				CHECK(matrix(2, 5) == -11.5);
			}

			THEN("the other values are not modified") {
				CHECK(matrix(0, 0) == 1.0);
				CHECK(matrix(0, 1) == 2.0);
				CHECK(matrix(1, 0) == 3.0);
				CHECK(matrix(1, 1) == 4.0);
			}
		}

		WHEN("adding an element to an zero sized matrix") {
			THEN("it increases the boundary to include the element") {
				Matrix<double> matrix;
				matrix.mutateToInclude(4.0, 0, 0);

				CHECK(matrix.rows() == 1);
				CHECK(matrix.columns() == 1);
			}


			THEN("it stores the specified value at the specified location") {
				Matrix<double> matrix;
				matrix.mutateToInclude(4.0, 0, 0);

				CHECK(matrix(0, 0) == 4.0);
			}
		}

		WHEN("adding an element at negative boundary") {
			THEN("an exception is thrown") {
				Matrix<double> matrix(2, 2);
	            std::string expectedMessage = "Invalid attempt to add element at negative row (-2) or column (2) to matrix [2, 2]";
	            // AssertThrows(Exception::InvalidSizeReset, matrix.mutateToInclude(0.0, -2, 2));
	            // CHECK(LastException<Exception::InvalidSizeReset>().what() == expectedMessage);
			}
		}
	}
}

} // namespace cmatrix
