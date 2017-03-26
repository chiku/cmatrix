// Written by     : Chirantan Mitra

#include "../doctest.h"

#include <matrix.h>

namespace cmatrix
{

SCENARIO("cmatrix::Matrix<double> populators") {
    GIVEN("matrix") {
        Matrix<double> matrix(2, 1);

        WHEN("filled with a value") {
            matrix.fillWith(-1.5);

            THEN("all cells are populated with the value") {
                CHECK(matrix(0, 0) == -1.5);
                CHECK(matrix(1, 0) == -1.5);
            }

            THEN("the matrix size does not change") {
                CHECK(matrix.rows() == 2);
                CHECK(matrix.columns() == 1);
            }
        }

        WHEN("filled with a value") {
            matrix.fillWithZeros();

            THEN("all cells are populated with zero") {
                CHECK(matrix(0, 0) == 0);
                CHECK(matrix(1, 0) == 0);
            }

            THEN("the matrix size does not change") {
                CHECK(matrix.rows() == 2);
                CHECK(matrix.columns() == 1);
            }
        }
    }
}

} // namespace cmatrix
