// Written by     : Chirantan Mitra

#include "doctest.h"

#include <matrix.h>

namespace cmatrix
{

SCENARIO("cmatrix::Size validations") {
    GIVEN("Size") {
        WHEN("with negative rows") {
            THEN("it is invalid") {
                CHECK_FALSE(Size(-1, 1).isValid());
            }
        }

        WHEN("with negative columns") {
            THEN("it is invalid") {
                CHECK_FALSE(Size(1, -1).isValid());
            }
        }

        WHEN("with zero sides") {
            THEN("it is valid") {
                CHECK(Size(0, 0).isValid());
            }
        }

        WHEN("with positive sides") {
            THEN("it is valid") {
                CHECK(Size(1, 1).isValid());
            }
        }
    }
}

SCENARIO("cmatrix::Size getters") {
    GIVEN("Size") {
        WHEN("with size 4x2") {
            auto size = Size(4, 2);

            THEN("it has 4 rows") {
                CHECK(size.getRows() == 4);
            }

            THEN("it has 2 columns") {
                CHECK(size.getColumns() == 2);
            }

            THEN("it has 8 elements") {
                CHECK(size.elements() == 8);
            }
        }

        WHEN("with size 2x0") {
            auto size = Size(2, 0);

            THEN("is has 0 elements") {
                CHECK(size.elements() == 0);
            }
        }

        WHEN("with same number of rows and columns") {
            THEN("it is a square") {
                CHECK(Size(2, 2).isSquare());
            }
        }

        WHEN("with different number of rows and columns") {
            THEN("it is not a square") {
                CHECK_FALSE(Size(2, 3).isSquare());
            }
        }
    }
}

SCENARIO("cmatrix::Size equality") {
    GIVEN("Size") {
        WHEN("compairing to another Size with same number or rows and columns") {
            auto size1 = Size(2, 1);
            auto size2 = Size(2, 1);

            THEN("they are equal") {
                CHECK(size1 == size2);

            }

            THEN("they are not unequal") {
                CHECK_FALSE(size1 != size2);

            }
        }

        WHEN("compairing to another Size with same number of rows but different number of columns") {
            auto size1 = Size(2, 2);
            auto size2 = Size(2, 1);

            THEN("they are not equal") {
                CHECK_FALSE(size1 == size2);

            }

            THEN("they are unequal") {
                CHECK(size1 != size2);

            }
        }

        WHEN("compairing to another Size with same number of columns but different number of rows") {
            auto size1 = Size(2, 2);
            auto size2 = Size(1, 2);

            THEN("they are not equal") {
                CHECK_FALSE(size1 == size2);

            }

            THEN("they are unequal") {
                CHECK(size1 != size2);

            }
        }
    }
}

SCENARIO("cmatrix::Size matches()") {
    GIVEN("Size") {
        WHEN("when paired with a row-column pair equal to number of rows and columns respectively") {
            THEN("they match") {
                CHECK(Size(2, 1).matches(2, 1));
            }
        }

        WHEN("when paired with a row-column pair with same number of rows but different number of columns") {
            THEN("they don't match") {
                CHECK_FALSE(Size(2, 1).matches(2, 3));
            }
        }

        WHEN("when paired with a row-column pair with same number of columns but different number of rows") {
            THEN("they don't match") {
                CHECK_FALSE(Size(2, 1).matches(3, 1));
            }
        }
    }
}

SCENARIO("cmatrix::Size contains()") {
    GIVEN("Size") {
        WHEN("row exceeds row limit") {
            THEN("the size is not contained within the given limits") {
                CHECK_FALSE(Size(2, 5).contains(3, 1));
            }
        }

        WHEN("row is less than zero") {
            THEN("the size is not contained within limits") {
                CHECK_FALSE(Size(2, 5).contains(-1, 1));
            }
        }

        WHEN("column exceeds column limit") {
            THEN("the size is not contained within limits") {
                CHECK_FALSE(Size(2, 5).contains(1, 5));
            }
        }

        WHEN("column is less than zero") {
            THEN("the size is not contained within limits") {
                CHECK_FALSE(Size(2, 5).contains(1, -1));
            }
        }

        WHEN("row-column pair are within limits") {
            THEN("the size is contained within limits") {
                CHECK(Size(2, 5).contains(0, 0));
            }
        }
    }
}

} // namespace cmatrix
