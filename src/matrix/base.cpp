// Written by     : Chirantan Mitra

template <class Type>
CMatrix::Matrix<Type>::Matrix()
{
    setMatrixAsUnassigned();
}

template <class Type>
CMatrix::Matrix<Type>::Matrix(long int rows, long int columns)
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

    for (long int i = 0; i < rows(); i++) {
        for (long int j = 0; j < columns(); j++) {
            access(i, j) = otherMatrix.access(i, j);
        }
    }
}

template <class Type>
CMatrix::Matrix<Type>::~Matrix()
{
    clearMemory();
}

template <class Type>
void CMatrix::Matrix<Type>::clearMemory()
{
    if (values != NULL) {
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

    for (long int i = 0; i < rows(); i++) {
        for (long int j = 0; j < columns(); j++) {
            access(i, j) = otherMatrix.access(i, j);
        }
    }

    return *this;
}

template <class Type>
inline long int CMatrix::Matrix<Type>::rows() const
{
    return size.getRows();
}

template <class Type>
inline long int CMatrix::Matrix<Type>::columns() const
{
    return size.getColumns();
}

template <class Type>
inline long int CMatrix::Matrix<Type>::elements() const
{
    return size.elements();
}

template <class Type>
void CMatrix::Matrix<Type>::setSize(long int rows, long int columns)
{
    if ((*this).rows() > 0 && (*this).columns() > 0 && !size.matches(rows, columns)) {
        throw Exception::InvalidSizeReset(ExceptionBody::BadSizeReset(size, rows, columns));
    }

    if (rows < 0 || columns < 0) {
        throw Exception::InvalidSizeSet(ExceptionBody::InvalidSizeSet(rows, columns));
    }

    clearMemory();

    size.set(rows, columns);

    values = new Type[rows * columns];
}

// Lvalue element accessor - unchecked (used internally)
template <class Type>
inline Type& CMatrix::Matrix<Type>::access(long int row, long int column)
{
    return values[row * columns() + column];
}

// Lvalue element accessor
template <class Type>
Type& CMatrix::Matrix<Type>::operator () (long int row, long int column)
{
    if (! size.contains(row, column)) {
        throw Exception::AccessOutOfBound(ExceptionBody::AccessOutOfBound(size, row, column));
    }

    return access(row, column);
}

// Rvalue element accessor (const) - unchecked (used internally)
template <class Type>
inline Type CMatrix::Matrix<Type>::access(long int row, long int column) const
{
    return values[row * columns() + column];
}

// Rvalue element accessor (const)
template <class Type>
Type CMatrix::Matrix<Type>::operator () (long int row, long int column) const
{
    if (! size.contains(row, column)) {
        throw Exception::AccessOutOfBound(ExceptionBody::AccessOutOfBound(size, row, column));
    }

    return access(row, column);
}

// Overloaded equality operator
template <class Type>
bool CMatrix::Matrix<Type>::operator == (const Matrix& otherMatrix) const
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

// Overloaded not-equals operator
template <class Type>
inline bool CMatrix::Matrix<Type>::operator != (const Matrix& otherMatrix) const
{
    return !operator == (otherMatrix);
}
