// Written by     : Chirantan Mitra

template <class Type>
bool CMatrix::Matrix<Type>::isSquare() const
{
    return size.isSquare();
}

template <class Type>
bool CMatrix::Matrix<Type>::isUnit() const
{
    if (!isSquare()) {
        return false;
    }

    for (int i = 0; i < rows(); i++) {
        for (int j = 0; j < columns(); j++) {
            if (( i != j && access(i, j) != 0) || (i == j && access(i, j) != 1)) {
                return false;
            }
        }
    }

    return true;
}

template <class Type>
bool CMatrix::Matrix<Type>::isZero() const
{
    for (int i = 0; i < rows(); i++) {
        for (int j = 0; j < columns(); j++) {
            if (access(i, j) != 0) {
                return false;
            }
        }
    }

    return true;
}