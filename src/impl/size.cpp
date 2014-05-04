// Written by     : Chirantan Mitra

namespace CMatrix
{

inline Size::Size()
{
    rows    = 0;
    columns = 0;
}

inline Size::Size(long int rows, long int columns)
{
    set(rows, columns);
}

inline void Size::set(long int rows, long int columns)
{
    (*this).rows    = rows;
    (*this).columns = columns;
}

inline bool Size::isValid() const
{
    return (rows >= 0) && (columns >= 0);
}

inline long int Size::getRows() const
{
    return rows;
}

inline long int Size::getColumns() const
{
    return columns;
}

inline long int Size::elements() const
{
    return getRows() * getColumns();
}

inline bool Size::isSquare() const
{
    return getRows() == getColumns();
}

inline bool Size::matches(long int otherRows, long int otherColumns) const
{
    return getRows() == otherRows && getColumns() == otherColumns;
}

inline bool Size::contains(long int row, long int column) const
{
    return 0 <= row && row < getRows() && 0 <= column && column < getColumns();
}

// Overloaded equality operator
inline bool Size::operator==(const Size& otherSize) const
{
    return matches(otherSize.getRows(), otherSize.getColumns());
}

// Overloaded not-equals operator
inline bool Size::operator != (const Size& otherSize) const
{
    return !operator == (otherSize);
}

} // namespace CMatrix
