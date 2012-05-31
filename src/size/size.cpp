// Written by     : Chirantan Mitra

#include <size.h>

CMatrix::Size::Size()
{
    rows    = 0;
    columns = 0;
}

CMatrix::Size::Size(long int rows, long int columns)
{
    set(rows, columns);
}

void CMatrix::Size::set(long int rows, long int columns)
{
    (*this).rows    = rows;
    (*this).columns = columns;
}

bool CMatrix::Size::isValid() const
{
    return rows > 0 && columns > 0;
}

long int CMatrix::Size::getRows() const
{
    return rows;
}

long int CMatrix::Size::getColumns() const
{
    return columns;
}

long int CMatrix::Size::elements() const
{
    return getRows() * getColumns();
}

bool CMatrix::Size::isSquare() const
{
    return getRows() == getColumns();
}

// Overloaded equality operator
bool CMatrix::Size::operator==(const Size& otherSize) const
{
    return (getRows() == otherSize.getRows() && getColumns() == otherSize.getColumns());
}

// Overloaded not-equals operator
bool CMatrix::Size::operator != (const Size& otherSize) const
{
    return !operator == (otherSize);
}

