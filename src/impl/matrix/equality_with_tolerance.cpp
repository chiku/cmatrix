// Written by     : Chirantan Mitra

namespace cmatrix
{

// Overloaded equality operator
template <class Type>
bool Matrix<Type>::equalWithTolerance(const Matrix& otherMatrix, const Type tolerance) const
{
    if (size != otherMatrix.size) {
        return false;
    }

    for (long int i = 0; i < rows(); i++) {
        for (long int j = 0; j < columns(); j++) {
            Type first = access(i, j), second = otherMatrix.access(i, j);
            if (((first - second) > tolerance) || (second - first) > tolerance) {
                return false;
            }
        }
    }

    return true;
}

} // namespace cmatrix
