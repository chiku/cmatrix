// Written by     : Chirantan Mitra

#include <size.h>

CMatrix::Size::Size()
{
    rows    = 0;
    columns = 0;
}

CMatrix::Size::Size(int rows, int columns)
{
    set(rows, columns);
}

void CMatrix::Size::set(int rows, int columns)
{
    (*this).rows    = rows;
    (*this).columns = columns;
}

bool CMatrix::Size::isValid() const
{
    return rows > 0 && columns > 0;
}

int CMatrix::Size::getRows() const
{
    return rows;
}

int CMatrix::Size::getColumns() const
{
    return columns;
}

int CMatrix::Size::elements() const
{
    return getRows() * getColumns();
}

int CMatrix::Size::isSquare() const
{
    return getRows() == getColumns();
}

// Overloaded equality operator
bool CMatrix::Size::operator==(const Size& otherSize) const
{
    return (getRows() == otherSize.getRows() && getColumns() == otherSize.getColumns());
}

// Overloaaded not-equals operator
bool CMatrix::Size::operator != (const Size& otherSize) const
{
    return !operator == (otherSize);
}

