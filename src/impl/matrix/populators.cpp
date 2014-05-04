// Written by     : Chirantan Mitra

namespace cmatrix
{

template <class Type>
void Matrix<Type>::fillWith(Type value)
{
    for (long int i = 0; i < rows(); i++) {
        for (long int j = 0; j < columns(); j++) {
            access(i, j) = value;
        }
    }
}

template <class Type>
inline void Matrix<Type>::fillWithZeros()
{
    fillWith(0);
}

} // namespace cmatrix
