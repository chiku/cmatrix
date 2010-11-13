// File           : matrix_numerical.cpp
// Written by     : Chirantan Mitra
// Created        : 25/03/2009

#include "matrix.h"

// Binary addition
template <class Type>
CMatrix::Matrix<Type> CMatrix::operator + (const CMatrix::Matrix<Type> firstMatrix, const CMatrix::Matrix<Type> secondMatrix)
{
    if (firstMatrix.rows != secondMatrix.rows || firstMatrix.columns != secondMatrix.columns)
        throw MatrixException::IncompatibleAddition();

    CMatrix::Matrix<Type> sum(firstMatrix.rows, firstMatrix.columns);
    
    for(int i = 0; i < firstMatrix.rows; i++)
        for(int j = 0; j< firstMatrix.columns; j++)
            sum(i, j) = firstMatrix(i, j) + secondMatrix(i, j);

    return sum;
}

// Binary subtraction
template <class Type>
CMatrix::Matrix<Type> CMatrix::operator - (const CMatrix::Matrix<Type> firstMatrix, const CMatrix::Matrix<Type> secondMatrix)
{
    if (firstMatrix.rows != secondMatrix.rows || firstMatrix.columns != secondMatrix.columns)
        throw MatrixException::IncompatibleSubtraction();

    CMatrix::Matrix<Type> difference(firstMatrix.rows, firstMatrix.columns);
    
    for(int i = 0; i < firstMatrix.rows; i++)
        for(int j = 0; j< firstMatrix.columns; j++)
            difference(i, j) = firstMatrix(i, j) - secondMatrix(i, j);

    return difference;
}

// Binary multiplication
template <class Type>
CMatrix::Matrix<Type> CMatrix::operator * (const CMatrix::Matrix<Type> firstMatrix, const CMatrix::Matrix<Type> secondMatrix)
{
    if (firstMatrix.columns != secondMatrix.rows)
        throw MatrixException::IncompatibleMultiplication();

    CMatrix::Matrix<Type> product(firstMatrix.rows, secondMatrix.columns);

    for(int i = 0; i < firstMatrix.rows; i++)
        for(int j = 0; j < secondMatrix.columns; j++)
        {
            product(i, j) = 0;
            for(int k = 0; k < firstMatrix.columns; k++)
                product(i, j) += firstMatrix(i, k) * secondMatrix(k, j);
        }

    return product;
}


// Shorthand binary addition
template <class Type>
CMatrix::Matrix<Type>& CMatrix::Matrix<Type>::operator += (const CMatrix::Matrix<Type> secondMatrix)
{
    if (rows != secondMatrix.rows || columns != secondMatrix.columns)
        throw MatrixException::IncompatibleAddition();
    
    for(int i = 0; i < rows; i++)
        for(int j = 0; j< columns; j++)
            (*this)(i, j) = (*this)(i, j) + secondMatrix(i, j);

    return (*this);
}

// Shorthand binary subtraction
template <class Type>
CMatrix::Matrix<Type>& CMatrix::Matrix<Type>::operator -= (const CMatrix::Matrix<Type> secondMatrix)
{
    if (rows != secondMatrix.rows || columns != secondMatrix.columns)
        throw MatrixException::IncompatibleSubtraction();
    
    for(int i = 0; i < rows; i++)
        for(int j = 0; j< columns; j++)
            (*this)(i, j) = (*this)(i, j) - secondMatrix(i, j);

    return (*this);
}


// Unary addition
template <class Type>
CMatrix::Matrix<Type> CMatrix::Matrix<Type>::operator + ()
{
    Matrix<Type> result = (*this);
    return result;
}

// Unary subtraction
template <class Type>
CMatrix::Matrix<Type> CMatrix::Matrix<Type>::operator - ()
{
    Matrix<Type> result(rows, columns);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            result(i, j) = - (*this)(i, j);

    return result;
}

