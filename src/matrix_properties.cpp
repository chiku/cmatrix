// Written by     : Chirantan Mitra

#include "matrix.h"

template <class Type>
bool CMatrix::Matrix<Type>::isSquare() const
{
    return size.isSquare();
}

template <class Type>
bool CMatrix::Matrix<Type>::isUnit() const
{
    if (rows() != columns())
        return false;

    for (int i = 0; i < rows(); i++)
        for (int j = 0; j < columns(); j++)
            if ( ( i != j && (*this)(i, j) != 0) || (i == j && (*this)(i, j) != 1) )
                return false;

    return true;
}

template <class Type>
bool CMatrix::Matrix<Type>::isZero() const
{
    for (int i = 0; i < rows(); i++)
        for (int j = 0; j < columns(); j++)
            if ( (*this)(i, j) != 0 )
                return false;

    return true;
}

