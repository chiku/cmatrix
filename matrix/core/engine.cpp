// Written by     : Chirantan Mitra

template <class Type>
inline bool CMatrix::Matrix<Type>::isMemoryAssigned() const
{
    return engine.isMemoryAssigned();
}

template <class Type>
inline void CMatrix::Matrix<Type>::unallocateMemory() const
{
    engine.unallocateMemory();
}

template <class Type>
inline void CMatrix::Matrix<Type>::markMemoryAsUnused()
{
    engine.markMemoryAsUnused();
}

template <class Type>
inline void CMatrix::Matrix<Type>::allocateMemory(CMatrix::Size size)
{
    engine.allocateMemory(size);
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
