// Written by     : Chirantan Mitra

#include "matrix.h"

template <class Type>
CMatrix::Matrix<Type>::Matrix()
{
    setMatrixAsUnassigned();
}

template <class Type>
CMatrix::Matrix<Type>::Matrix(unsigned int rows, unsigned int columns)
{
    setMatrixAsUnassigned();
    setSize(rows, columns);
}

// Copy Constructor
template <class Type>
CMatrix::Matrix<Type>::Matrix(const Matrix& otherMatrix)
{
    setMatrixAsUnassigned();
    setSize(otherMatrix.rows(), otherMatrix.columns());

    for(int i = 0; i < rows(); i++)
        for (int j = 0; j < columns(); j++)
            (*this)(i, j) = otherMatrix(i, j);
}

template <class Type>
CMatrix::Matrix<Type>::~Matrix()
{
    clearMemory();
}

template <class Type>
void CMatrix::Matrix<Type>::clearMemory()
{
    if (values != NULL)
    {
        delete[] values;
        setMatrixAsUnassigned();
    }
}

template <class Type>
void CMatrix::Matrix<Type>::setMatrixAsUnassigned()
{
    values = NULL;
    size.set(0, 0);
}


// Overloaded equals operator
template <class Type>
CMatrix::Matrix<Type>& CMatrix::Matrix<Type>::operator = (const Matrix& otherMatrix)
{
    setSize(otherMatrix.rows(), otherMatrix.columns());

    for(int i = 0; i < rows(); i++)
        for (int j = 0; j < columns(); j++)
            (*this)(i, j) = otherMatrix(i, j);

    return *this;
}

template <class Type>
int CMatrix::Matrix<Type>::rows() const
{
    return size.getRows();
}

template <class Type>
int CMatrix::Matrix<Type>::columns() const
{
    return size.getColumns();
}

template <class Type>
int CMatrix::Matrix<Type>::elements() const
{
    return size.elements();
}

template <class Type>
void CMatrix::Matrix<Type>::setSize(unsigned int rows, unsigned int columns)
{
    if ((*this).rows() != 0 && (*this).columns() != 0 && (*this).rows() != rows && (*this).columns() != columns)
        throw MatrixException::SizeResetException();

    if (rows == 0 || columns == 0)
        throw MatrixException::InvalidSizeSet();

    clearMemory();

    size.set(rows, columns);

    values = new Type[rows * columns];
}

// Lvalue element accessor
template <class Type>
Type& CMatrix::Matrix<Type>::operator()(unsigned int row, unsigned int column)
{
    if (row >= rows() || column >= columns())
        throw MatrixException::AccessOutOfBound();

    return values[row * columns() + column];
}

// Rvalue element accessor (const)
template <class Type>
Type CMatrix::Matrix<Type>::operator()(unsigned int row, unsigned int column) const
{
    if (row >= rows() || column >= columns())
        throw MatrixException::AccessOutOfBound();

    return values[row * columns() + column];
}

// Overloaded equality operator
template <class Type>
bool CMatrix::Matrix<Type>::operator==(const Matrix& otherMatrix) const
{
    if (rows() != otherMatrix.rows() || columns() != otherMatrix.columns())
        return false;

    for(int i = 0; i < rows(); i++)
        for(int j = 0; j < columns(); j++)
            if((*this)(i, j) != otherMatrix(i, j))
                return false;

    return true;
}

// Overloaaded not-equals operator
template <class Type>
bool CMatrix::Matrix<Type>::operator != (const Matrix& otherMatrix) const
{
    return !operator == (otherMatrix);
}

