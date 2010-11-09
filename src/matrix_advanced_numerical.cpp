// File           : matrix_advanced_numerical.cpp
// Written by     : Chirantan Mitra
// Created        : 25/03/2009
// Last modified  : 28/03/2009

#include "matrix.h"

// Per-element function passing
template <class Type>
template <typename FunctObj> 
CMatrix::Matrix<Type> CMatrix::Matrix<Type>::map(FunctObj function)
{
    CMatrix::Matrix<Type> result(rows, columns);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            result(i, j) = (*function)((*this)(i, j));

    return result;
}

// Per-element filling by position
template <class Type>
template <typename FunctObj> 
CMatrix::Matrix<Type>& CMatrix::Matrix<Type>::fillByPosition(FunctObj function, int xShift, int yShift)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            (*this)(i, j) = (*function)(i - xShift, j - yShift);

    return (*this);
}

// Per-element filling by position with scaling and position shift
template <class Type>
template <typename FunctObj> 
CMatrix::Matrix<Type>& CMatrix::Matrix<Type>::fillByPosition(FunctObj function, int xShift, int yShift, Type xScale, Type yScale)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            (*this)(i, j) = (*function)((i - xShift) * xScale, (j - yShift) * yScale);

    return (*this);
}

