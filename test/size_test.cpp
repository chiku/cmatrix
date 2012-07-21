// Written by     : Chirantan Mitra

#include <igloo/igloo_alt.h>
#include <matrix.h>

using namespace igloo;
using namespace CMatrix;

Describe(CMatrix_Size)
{
    It(IsInvalidWithRowAsZero)
    {
        Assert::That(Size(0, 1).isValid(), IsFalse());
    }

    It(IsInvalidWithColumnAsZero)
    {
        Assert::That(Size(1, 0).isValid(), IsFalse());
    }

    It(IsValidWithRowAndColumnGreaterThanZero)
    {
        Assert::That(Size(1, 1).isValid(), IsTrue());
    }

    It(KnowsItsRows)
    {
        Assert::That(Size(4, 2).getRows(), Equals(4));
    }

    It(KnowsItsColumns)
    {
        Assert::That(Size(4, 2).getColumns(), Equals(2));
    }

    It(KnowsItsElementCount)
    {
        Assert::That(Size(4, 2).elements(), Equals(8));
        Assert::That(Size(2, 0).elements(), Equals(0));
    }

    It(KnowsItIsSquareWhenRowsAndColumnsAreEqual)
    {
        Assert::That(Size(2, 2).isSquare(), IsTrue());
    }

    It(KnowsItIsSquareWhenRowsAndColumnsAreNotEqual)
    {
        Assert::That(! Size(2, 3).isSquare(), IsTrue());
    }

    It(DoesNotEqualAnotherSizeIfRowsAreUnequal)
    {
        Size twoByTwo = Size(2, 2);
        Size oneByTwo = Size(1, 2);

        Assert::That(twoByTwo == oneByTwo, IsFalse());
        Assert::That(twoByTwo != oneByTwo, IsTrue());
    }

    It(DoesNotEqualAnotherSizeIfColumnsAreUnequal)
    {
        Size twoByTwo = Size(2, 2);
        Size twoByOne = Size(2, 1);

        Assert::That(twoByTwo == twoByOne, IsFalse());
        Assert::That(twoByTwo != twoByOne, IsTrue());
    }

    It(EqualsAnotherSizeIfRowsAndColumnsAreUnequal)
    {
        Size firstTwoByTwo  = Size(2, 2);
        Size secondTwoByTwo = Size(2, 2);

        Assert::That(firstTwoByTwo == secondTwoByTwo, IsTrue());
        Assert::That(firstTwoByTwo != secondTwoByTwo, IsFalse());
    }
};
