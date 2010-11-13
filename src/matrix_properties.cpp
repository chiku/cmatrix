// File           : matrix_numerical.cpp
// Written by     : Chirantan Mitra
// Created        : 25/03/2009

#include "matrix.h"

// Test matrix is square
template <class Type>
bool CMatrix::Matrix<Type>::isSquare() const
{
    return rows == columns;
}

