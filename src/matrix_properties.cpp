// Written by     : Chirantan Mitra
// Created        : 25/03/2009

#include "matrix.h"

// Test matrix is square
template <class Type>
bool CMatrix::Matrix<Type>::isSquare() const
{
    return rows == columns;
}

// Test matrix is unit
template <class Type>
bool CMatrix::Matrix<Type>::isUnit() const
{
    if (rows != columns)
        return false;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            if ( ( i != j && (*this)(i, j) != 0) || (i == j && (*this)(i, j) != 1) )
                return false;

    return true;
}

// Test matrix is zero
template <class Type>
bool CMatrix::Matrix<Type>::isZero() const
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            if ( (*this)(i, j) != 0 )
                return false;

    return true;
}

