// Written by     : Chirantan Mitra

template <class Type>
inline bool CMatrix::Matrix<Type>::isMemoryAssigned() const
{
    return values != NULL;
}

template <class Type>
inline void CMatrix::Matrix<Type>::unallocateMemory() const
{
    delete values;
}

template <class Type>
inline void CMatrix::Matrix<Type>::markMemoryAsUnused()
{
    values = NULL;
}

template <class Type>
inline void CMatrix::Matrix<Type>::allocateMemory(long int rows, long int columns)
{
    values = new std::vector<Type>(rows * columns);
}

// Lvalue element accessor - unchecked
template <class Type>
inline Type& CMatrix::Matrix<Type>::access(long int row, long int column)
{
    return (*values)[row * columns() + column];
}

// Rvalue element accessor (const) - unchecked
template <class Type>
inline Type CMatrix::Matrix<Type>::access(long int row, long int column) const
{
    return (*values)[row * columns() + column];
}
