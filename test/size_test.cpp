// Written by     : Chirantan Mitra

#include <matrix_test.h>

void MatrixTest::sizeIsInvalidWithRowAsZero(void)
{
    CPPUNIT_ASSERT (!Size(0, 1).isValid());
}

void MatrixTest::sizeIsInvalidWithColumnAsZero(void)
{
    CPPUNIT_ASSERT (!Size(1, 0).isValid());
}

void MatrixTest::sizeIsValidWithRowAndColumnGreaterThanZero(void)
{
    CPPUNIT_ASSERT (Size(1, 1).isValid());
}

void MatrixTest::sizeKnowsItsRows(void)
{
    CPPUNIT_ASSERT (Size(4, 2).getRows() == 4);
}

void MatrixTest::sizeKnowsItsColumns(void)
{
    CPPUNIT_ASSERT (Size(4, 2).getColumns() == 2);
}

void MatrixTest::sizeKnowsItsElementCount(void)
{
    CPPUNIT_ASSERT (Size(4, 2).elements() == 8);
    CPPUNIT_ASSERT (Size(2, 0).elements() == 0);
}

void MatrixTest::sizeKnowsItIsSquareWhenRowsAndColumnsAreEqual(void)
{
    CPPUNIT_ASSERT (Size(2, 2).isSquare());
}

void MatrixTest::sizeKnowsItIsSquareWhenRowsAndColumnsAreNotEqual(void)
{
    CPPUNIT_ASSERT (! Size(2, 3).isSquare());
}

void MatrixTest::sizesWithDifferentRowsAreUnequal(void)
{
    Size twoByTwo = Size(2, 2);
    Size oneByTwo = Size(1, 2);

    CPPUNIT_ASSERT (! (twoByTwo == oneByTwo));
    CPPUNIT_ASSERT (twoByTwo != oneByTwo);
}

void MatrixTest::sizesWithDifferentColumnsAreUnequal(void)
{
    Size twoByTwo = Size(2, 2);
    Size twoByOne = Size(2, 1);

    CPPUNIT_ASSERT (! (twoByTwo == twoByOne));
    CPPUNIT_ASSERT (twoByTwo != twoByOne);
}

void MatrixTest::sizesWithSameRowsAndColumnsAreEqual(void)
{
    Size firstTwoByTwo  = Size(2, 2);
    Size secondTwoByTwo = Size(2, 2);

    CPPUNIT_ASSERT (firstTwoByTwo == secondTwoByTwo);
    CPPUNIT_ASSERT (! (firstTwoByTwo != secondTwoByTwo));
}

