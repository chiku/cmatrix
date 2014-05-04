// Written by     : Chirantan Mitra

namespace CMatrix
{

template <class Type>
void Matrix<Type>::setMatrixAsUnassigned()
{
    engine.markMemoryAsUnused();
    size.set(0, 0);
}

template <class Type>
void Matrix<Type>::clearMemory()
{
    if (engine.isMemoryAssigned()) {
        engine.unallocateMemory();
        setMatrixAsUnassigned();
    }
}

template <class Type>
Matrix<Type>::Matrix()
{
    setMatrixAsUnassigned();
}

template <class Type>
Matrix<Type>::Matrix(long int rows, long int columns)
{
    setMatrixAsUnassigned();
    setSize(rows, columns);
}

// Copy Constructor
template <class Type>
Matrix<Type>::Matrix(const Matrix& otherMatrix)
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
Matrix<Type>::~Matrix()
{
    clearMemory();
}

template <class Type>
void Matrix<Type>::setSize(long int rows, long int columns)
{
    if ((*this).rows() > 0 && (*this).columns() > 0 && !size.matches(rows, columns)) {
        throw Exception::InvalidSizeReset(ExceptionBody::BadSizeReset(size, rows, columns));
    }

    if (rows < 0 || columns < 0) {
        throw Exception::InvalidSizeSet(ExceptionBody::InvalidSizeSet(rows, columns));
    }

    clearMemory();

    size.set(rows, columns);

    engine.allocateMemory(size);
}

} // namespace CMatrix
