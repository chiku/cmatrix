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

