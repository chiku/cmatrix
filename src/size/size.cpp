// Written by     : Chirantan Mitra

inline CMatrix::Size::Size()
{
    rows    = 0;
    columns = 0;
}

inline CMatrix::Size::Size(long int rows, long int columns)
{
    set(rows, columns);
}

inline void CMatrix::Size::set(long int rows, long int columns)
{
    (*this).rows    = rows;
    (*this).columns = columns;
}

inline bool CMatrix::Size::isValid() const
{
    return rows > 0 && columns > 0;
}

inline long int CMatrix::Size::getRows() const
{
    return rows;
}

inline long int CMatrix::Size::getColumns() const
{
    return columns;
}

inline long int CMatrix::Size::elements() const
{
    return getRows() * getColumns();
}

inline bool CMatrix::Size::isSquare() const
{
    return getRows() == getColumns();
}

// Overloaded equality operator
inline bool CMatrix::Size::operator==(const Size& otherSize) const
{
    return (getRows() == otherSize.getRows() && getColumns() == otherSize.getColumns());
}

// Overloaded not-equals operator
inline bool CMatrix::Size::operator != (const Size& otherSize) const
{
    return !operator == (otherSize);
}
