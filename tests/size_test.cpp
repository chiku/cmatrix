// Written by     : Chirantan Mitra

#include <igloo/igloo_alt.h>
#include <matrix.h>

using namespace igloo;

namespace cmatrix
{

Describe(cmatrix_size)
{
    Describe(When_with_negative_rows)
    {
        It(is_invalid)
        {
            Assert::That(Size(-1, 1).isValid(), IsFalse());
        }
    };

    Describe(When_with_negative_columns)
    {
        It(is_invalid)
        {
            Assert::That(Size(1, -1).isValid(), IsFalse());
        }
    };

    Describe(with_zero_sizes)
    {
        It(Is_valid)
        {
            Assert::That(Size(0, 0).isValid(), IsTrue());
        }
    };

    Describe(With_positive_sizes)
    {
        It(Is_valid)
        {
            Assert::That(Size(1, 1).isValid(), IsTrue());
        }
    };

    Describe(size_of_4x2)
    {
        It(has_4_rows)
        {
            Assert::That(Size(4, 2).getRows(), Equals(4));
        }

        It(has_2_columns)
        {
            Assert::That(Size(4, 2).getColumns(), Equals(2));
        }

        It(has_8_elements)
        {
            Assert::That(Size(4, 2).elements(), Equals(8));
        }
    };

    Describe(Size_of_2x0)
    {
        It(has_0_elements)
        {
            Assert::That(Size(2, 0).elements(), Equals(0));
        }
    };

    Describe(When_it_has_same_rows_and_columns)
    {
        It(is_square)
        {
            Assert::That(Size(2, 2).isSquare(), IsTrue());
        }
    };

    Describe(When_it_has_different_rows_and_columns)
    {
        It(is_not_square)
        {
            Assert::That(Size(2, 3).isSquare(), IsFalse());
        }
    };

    Describe(When_comparing)
    {
        Describe(to_another_size)
        {
            Describe(When_both_have_same_rows_and_columns)
            {
                It(is_equal)
                {
                    Size firstTwoByOne  = Size(2, 1);
                    Size secondTwoByOne = Size(2, 1);

                    Assert::That(firstTwoByOne == secondTwoByOne, IsTrue());
                    Assert::That(firstTwoByOne != secondTwoByOne, IsFalse());
                }
            };

            Describe(When_both_have_different_rows)
            {
                It(is_not_equal)
                {
                    Size twoByTwo = Size(2, 2);
                    Size oneByTwo = Size(1, 2);

                    Assert::That(twoByTwo == oneByTwo, IsFalse());
                    Assert::That(twoByTwo != oneByTwo, IsTrue());
                }
            };

            Describe(When_both_have_different_columns)
            {
                It(is_not_equal)
                {
                    Size twoByTwo = Size(2, 2);
                    Size twoByOne = Size(2, 1);

                    Assert::That(twoByTwo == twoByOne, IsFalse());
                    Assert::That(twoByTwo != twoByOne, IsTrue());
                }
            };
        };

        Describe(To_a_row_column_pair)
        {
            Describe(When_both_have_same_rows_and_columns)
            {
                It(matches)
                {
                    Assert::That(Size(2, 1).matches(2, 1), IsTrue());
                }
            };

            Describe(When_both_have_different_rows)
            {
                It(does_not_match)
                {
                    Assert::That(Size(2, 1).matches(3, 1), IsFalse());
                }
            };

            Describe(When_both_have_different_columns)
            {
                It(does_not_match)
                {
                    Assert::That(Size(2, 1).matches(2, 3), IsFalse());
                }
            };
        };

        Describe(When_row_exceeds_row_size)
        {
            It(is_not_contained_in_the_size_limits)
            {
                Assert::That(Size(2, 5).contains(3, 1), IsFalse());
            }
        };

        Describe(When_row_is_less_than_zero)
        {
            It(is_not_contained_in_the_size_limits)
            {
                Assert::That(Size(2, 5).contains(-1, 1), IsFalse());
            }
        };

        Describe(When_column_size_exceeds_column_size)
        {
            It(is_not_contained_in_the_size_limits)
            {
                Assert::That(Size(2, 5).contains(1, 5), IsFalse());
            }
        };

        Describe(When_column_is_less_than_zero)
        {
            It(is_not_contained_in_the_size_limits)
            {
                Assert::That(Size(2, 5).contains(1, -1), IsFalse());
            }
        };

        Describe(When_row_column_pair_are_within_size)
        {
            It(is_contained)
            {
                Assert::That(Size(2, 5).contains(0, 0), IsTrue());
            }
        };
    };
};

} // namespace cmatrix
