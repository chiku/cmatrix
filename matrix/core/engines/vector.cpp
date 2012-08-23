// Written by     : Chirantan Mitra

template <class Type>
inline bool CMatrix::Matrix<Type>::isMemoryAssigned() const
{
    // return values != NULL;
    return engine.isMemoryAssigned();
}

template <class Type>
inline void CMatrix::Matrix<Type>::unallocateMemory() const
{
    // delete values;
    engine.unallocateMemory();
}

template <class Type>
inline void CMatrix::Matrix<Type>::markMemoryAsUnused()
{
    // values = NULL;
    engine.markMemoryAsUnused();
}

template <class Type>
inline void CMatrix::Matrix<Type>::allocateMemory(CMatrix::Size size)
{
    // values = new std::vector<Type>(size.elements());
    engine.allocateMemory(size);
}

// Lvalue element accessor - unchecked
template <class Type>
inline Type& CMatrix::Matrix<Type>::access(long int row, long int column)
{
    // return (*values)[row * columns() + column];
    return engine.access(row, column);
}

// Rvalue element accessor (const) - unchecked
template <class Type>
inline Type CMatrix::Matrix<Type>::access(long int row, long int column) const
{
    // return (*values)[row * columns() + column];
    return engine.access(row, column);
}
