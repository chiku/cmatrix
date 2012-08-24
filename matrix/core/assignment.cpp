// Written by     : Chirantan Mitra

// Overloaded assignment operator
template <class Type>
CMatrix::Matrix<Type>& CMatrix::Matrix<Type>::operator = (const Matrix& otherMatrix)
{
    setSize(otherMatrix.rows(), otherMatrix.columns());

    for (long int i = 0; i < rows(); i++) {
        for (long int j = 0; j < columns(); j++) {
            access(i, j) = otherMatrix.access(i, j);
        }
    }

    return *this;
}
