// Written by     : Chirantan Mitra

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

    for(int i = 0; i < elements(); i++)
        values[i] = otherMatrix.values[i];
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


// Overloaded assignment operator
template <class Type>
CMatrix::Matrix<Type>& CMatrix::Matrix<Type>::operator = (const Matrix& otherMatrix)
{
    setSize(otherMatrix.rows(), otherMatrix.columns());

    for(int i = 0; i < elements(); i++)
        values[i] = otherMatrix.values[i];

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
        throw Exception::SizeResetException();

    if (rows == 0 || columns == 0)
        throw Exception::InvalidSizeSet();

    clearMemory();

    size.set(rows, columns);

    values = new Type[rows * columns];
}

// Lvalue element accessor
template <class Type>
Type& CMatrix::Matrix<Type>::operator()(unsigned int row, unsigned int column)
{
    if (row >= rows() || column >= columns())
        throw Exception::AccessOutOfBound(ExceptionBody::AccessOutOfBound(size, row, column));

    return values[row * columns() + column];
}

// Rvalue element accessor (const)
template <class Type>
Type CMatrix::Matrix<Type>::operator()(unsigned int row, unsigned int column) const
{
    if (row >= rows() || column >= columns())
        throw Exception::AccessOutOfBound(ExceptionBody::AccessOutOfBound(size, row, column));

    return values[row * columns() + column];
}

// Overloaded equality operator
template <class Type>
bool CMatrix::Matrix<Type>::operator==(const Matrix& otherMatrix) const
{
    if (size != otherMatrix.size)
        return false;

    for(int i = 0; i < elements(); i++)
        if(values[i] != otherMatrix.values[i])
            return false;

    return true;
}

// Overloaaded not-equals operator
template <class Type>
bool CMatrix::Matrix<Type>::operator != (const Matrix& otherMatrix) const
{
    return !operator == (otherMatrix);
}

