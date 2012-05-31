// Written by     : Chirantan Mitra

// Per-element function passing
template <class Type>
template <typename FunctObj>
CMatrix::Matrix<Type> CMatrix::Matrix<Type>::map(FunctObj function)
{
    CMatrix::Matrix<Type> result(rows(), columns());
    for(int i = 0; i < elements(); i++)
        result.values[i] = (*function)(values[i]);

    return result;
}

// Per-element filling by position
template <class Type>
template <typename FunctObj>
CMatrix::Matrix<Type>& CMatrix::Matrix<Type>::fillByPosition(FunctObj function, long int xShift, long int yShift)
{
    for (int i = 0; i < rows(); i++)
        for (int j = 0; j < columns(); j++)
            (*this)(i, j) = (*function)(i - xShift, j - yShift);

    return (*this);
}

// Per-element filling by position with scaling and position shift
template <class Type>
template <typename FunctObj>
CMatrix::Matrix<Type>& CMatrix::Matrix<Type>::fillByPosition(FunctObj function, long int xShift, long int yShift, Type xScale, Type yScale)
{
    for (int i = 0; i < rows(); i++)
        for (int j = 0; j < columns(); j++)
            (*this)(i, j) = (*function)((i - xShift) * xScale, (j - yShift) * yScale);

    return (*this);
}

