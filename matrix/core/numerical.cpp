// Written by     : Chirantan Mitra

// Binary addition
template <class Type>
CMatrix::Matrix<Type> CMatrix::operator + (const CMatrix::Matrix<Type> firstMatrix, const CMatrix::Matrix<Type> secondMatrix)
{
    if (firstMatrix.size != secondMatrix.size) {
        throw Exception::IncompatibleAddition(ExceptionBody::IncompatibleAddition(firstMatrix.size, secondMatrix.size));
    }

    CMatrix::Matrix<Type> sum(firstMatrix.rows(), firstMatrix.columns());

    for (int i = 0; i < firstMatrix.rows(); i++) {
        for (int j = 0; j < firstMatrix.columns(); j++) {
            sum.access(i, j) = firstMatrix.access(i, j) + secondMatrix.access(i, j);
        }
    }

    return sum;
}

// Binary subtraction
template <class Type>
CMatrix::Matrix<Type> CMatrix::operator - (const CMatrix::Matrix<Type> firstMatrix, const CMatrix::Matrix<Type> secondMatrix)
{
    if (firstMatrix.size != secondMatrix.size) {
        throw Exception::IncompatibleSubtraction(ExceptionBody::IncompatibleSubtraction(firstMatrix.size, secondMatrix.size));
    }

    CMatrix::Matrix<Type> difference(firstMatrix.rows(), firstMatrix.columns());

    for (int i = 0; i < firstMatrix.rows(); i++) {
        for (int j = 0; j < firstMatrix.columns(); j++) {
            difference.access(i, j) = firstMatrix.access(i, j) - secondMatrix.access(i, j);
        }
    }

    return difference;
}

// Binary multiplication
template <class Type>
CMatrix::Matrix<Type> CMatrix::operator * (const CMatrix::Matrix<Type> firstMatrix, const CMatrix::Matrix<Type> secondMatrix)
{
    if (firstMatrix.columns() != secondMatrix.rows()) {
        throw Exception::IncompatibleMultiplication(ExceptionBody::IncompatibleMultiplication(firstMatrix.size, secondMatrix.size));
    }

    CMatrix::Matrix<Type> product(firstMatrix.rows(), secondMatrix.columns());

    for (int i = 0; i < firstMatrix.rows(); i++) {
        for (int j = 0; j < secondMatrix.columns(); j++) {
            product(i, j) = 0;
            for (int k = 0; k < firstMatrix.columns(); k++) {
                product(i, j) += firstMatrix(i, k) * secondMatrix(k, j);
            }
        }
    }

    return product;
}


// Shorthand binary addition
template <class Type>
CMatrix::Matrix<Type>& CMatrix::Matrix<Type>::operator += (const CMatrix::Matrix<Type> secondMatrix)
{
    if (size != secondMatrix.size) {
        throw Exception::IncompatibleAddition(ExceptionBody::IncompatibleAddition(size, secondMatrix.size));
    }

    for (int i = 0; i < rows(); i++) {
        for (int j = 0; j < columns(); j++) {
            access(i, j) = access(i, j) + secondMatrix.access(i, j);
        }
    }

    return (*this);
}

// Shorthand binary subtraction
template <class Type>
CMatrix::Matrix<Type>& CMatrix::Matrix<Type>::operator -= (const CMatrix::Matrix<Type> secondMatrix)
{
    if (size != secondMatrix.size) {
        throw Exception::IncompatibleSubtraction(ExceptionBody::IncompatibleSubtraction(size, secondMatrix.size));
    }

    for (int i = 0; i < rows(); i++) {
        for (int j = 0; j < columns(); j++) {
            access(i, j) = access(i, j) - secondMatrix.access(i, j);
        }
    }

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
    Matrix<Type> result(rows(), columns());

    for (int i = 0; i < rows(); i++) {
        for (int j = 0; j < columns(); j++) {
            result.access(i, j) = -access(i, j);
        }
    }

    return result;
}

// Scalar multiplication
template <class Type>
CMatrix::Matrix<Type> CMatrix::Matrix<Type>::scale(Type value)
{
    Matrix<Type> result(rows(), columns());

    for (int i = 0; i < rows(); i++) {
        for (int j = 0; j < columns(); j++) {
            result.access(i, j) = value * access(i, j);
        }
    }

    return result;
}
