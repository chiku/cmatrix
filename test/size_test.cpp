// Written by     : Chirantan Mitra

#include <igloo/igloo_alt.h>
#include <matrix.h>

using namespace igloo;
using namespace CMatrix;

Describe(CMatrix_Size)
{
    Describe(IsInvalid)
    {
        It(With_Negative_Rows)
        {
            Assert::That(Size(-1, 1).isValid(), IsFalse());
        }

        It(With_Negative_Columns)
        {
            Assert::That(Size(1, -1).isValid(), IsFalse());
        }
    };

    Describe(Isvalid)
    {
        It(With_Zero_Sizes)
        {
            Assert::That(Size(0, 0).isValid(), IsTrue());
        }

        It(With_Positive_Sizes)
        {
            Assert::That(Size(1, 1).isValid(), IsTrue());
        }
    };

    Describe(Size_Of_4x2)
    {
        It(Has4Rows)
        {
            Assert::That(Size(4, 2).getRows(), Equals(4));
        }

        It(Has2Columns)
        {
            Assert::That(Size(4, 2).getColumns(), Equals(2));
        }

        It(Has8Elements)
        {
            Assert::That(Size(4, 2).elements(), Equals(8));
        }
    };

    Describe(Size_Of_2x0)
    {
        It(Has0Elements)
        {
            Assert::That(Size(2, 0).elements(), Equals(0));
        }
    };

    Describe(When_Rows_Equal_Columns)
    {
        It(IsASquare)
        {
            Assert::That(Size(2, 2).isSquare(), IsTrue());
        }
    };

    Describe(When_Rows_Do_Not_Equal_Columns)
    {
        It(IsNotASquare)
        {
            Assert::That(Size(2, 3).isSquare(), IsFalse());
        }
    };

    Describe(When_Comparing)
    {
        Describe(To_Another_Size)
        {
            Describe(Equals)
            {
                It(WhenBothHaveSameRowsAndColumns)
                {
                    Size firstTwoByOne  = Size(2, 1);
                    Size secondTwoByOne = Size(2, 1);

                    Assert::That(firstTwoByOne == secondTwoByOne, IsTrue());
                    Assert::That(firstTwoByOne != secondTwoByOne, IsFalse());
                }
            };

            Describe(Does_Not_Equal)
            {
                It(WhenBothHaveDifferentRows)
                {
                    Size twoByTwo = Size(2, 2);
                    Size oneByTwo = Size(1, 2);

                    Assert::That(twoByTwo == oneByTwo, IsFalse());
                    Assert::That(twoByTwo != oneByTwo, IsTrue());
                }

                It(WhenBothHaveDifferentColumns)
                {
                    Size twoByTwo = Size(2, 2);
                    Size twoByOne = Size(2, 1);

                    Assert::That(twoByTwo == twoByOne, IsFalse());
                    Assert::That(twoByTwo != twoByOne, IsTrue());
                }
            };
        };

        Describe(To_A_Row_Column_Pair)
        {
            Describe(Matches)
            {
                It(WhenBothHaveSameRowsAndColumns)
                {
                    Assert::That(Size(2, 1).matches(2, 1), IsTrue());
                }
            };

            Describe(Does_Not_Match)
            {
                It(WhenBothHaveDifferentRows)
                {
                    Assert::That(Size(2, 1).matches(3, 1), IsFalse());
                }

                It(WhenBothHaveDifferentColumns)
                {
                    Assert::That(Size(2, 1).matches(2, 3), IsFalse());
                }
            };
        };

        Describe(When_Row_Exceeds_Size_Rows)
        {
            It(IsNotContained)
            {
                Assert::That(Size(2, 5).contains(3, 1), IsFalse());
            }
        };

        Describe(When_Column_Exceeds_Size_Columns)
        {
            It(IsNotContained)
            {
                Assert::That(Size(2, 5).contains(1, 5), IsFalse());
            }
        };

        Describe(When_Row_Column_Are_Within_Size)
        {
            It(IsContained)
            {
                Assert::That(Size(2, 5).contains(0, 0), IsTrue());
            }
        };
    };
};
