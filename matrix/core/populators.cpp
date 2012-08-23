// Written by     : Chirantan Mitra

template <class Type>
void CMatrix::Matrix<Type>::fillWith(Type value)
{
    for (long int i = 0; i < rows(); i++) {
        for (long int j = 0; j < columns(); j++) {
            access(i, j) = value;
        }
    }
}

template <class Type>
inline void CMatrix::Matrix<Type>::fillWithZeros()
{
    fillWith(0);
}
