// Written by     : Chirantan Mitra

template <class Type>
inline long int CMatrix::Matrix<Type>::rows() const
{
    return size.getRows();
}

template <class Type>
inline long int CMatrix::Matrix<Type>::columns() const
{
    return size.getColumns();
}

template <class Type>
inline long int CMatrix::Matrix<Type>::elements() const
{
    return size.elements();
}

// Lvalue element accessor - unchecked
template <class Type>
inline Type& CMatrix::Matrix<Type>::access(long int row, long int column)
{
    return engine.access(row, column);
}

// Rvalue element accessor (const) - unchecked
template <class Type>
inline Type CMatrix::Matrix<Type>::access(long int row, long int column) const
{
    return engine.access(row, column);
}

// Lvalue element accessor
template <class Type>
Type& CMatrix::Matrix<Type>::operator () (long int row, long int column)
{
    if (! size.contains(row, column)) {
        throw Exception::AccessOutOfBound(ExceptionBody::AccessOutOfBound(size, row, column));
    }

    return access(row, column);
}

// Rvalue element accessor (const)
template <class Type>
Type CMatrix::Matrix<Type>::operator () (long int row, long int column) const
{
    if (! size.contains(row, column)) {
        throw Exception::AccessOutOfBound(ExceptionBody::AccessOutOfBound(size, row, column));
    }

    return access(row, column);
}
