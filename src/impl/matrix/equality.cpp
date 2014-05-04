// Written by     : Chirantan Mitra

namespace cmatrix
{

// Overloaded equality operator
template <class Type>
bool Matrix<Type>::equal(const Matrix& otherMatrix) const
{
    if (size != otherMatrix.size) {
        return false;
    }

    for (long int i = 0; i < rows(); i++) {
        for (long int j = 0; j < columns(); j++) {
            if (access(i, j) != otherMatrix.access(i, j)) {
                return false;
            }
        }
    }

    return true;
}

// Overloaded equality operator
template <class Type>
inline bool Matrix<Type>::operator == (const Matrix& otherMatrix) const
{
    return equal(otherMatrix);
}

// Overloaded not-equals operator
template <class Type>
inline bool Matrix<Type>::operator != (const Matrix& otherMatrix) const
{
    return !equal(otherMatrix);
}

} // namespace cmatrix
