// Written by     : Chirantan Mitra

// Binary addition
template <class Type>
CMatrix::Matrix<Type> CMatrix::operator + (const CMatrix::Matrix<Type> firstMatrix, const CMatrix::Matrix<Type> secondMatrix)
{
    if (firstMatrix.size != secondMatrix.size)
        throw Exception::IncompatibleAddition();

    CMatrix::Matrix<Type> sum(firstMatrix.rows(), firstMatrix.columns());

    for(int i = 0; i < firstMatrix.elements(); i++)
        sum.values[i] = firstMatrix.values[i] + secondMatrix.values[i];

    return sum;
}

// Binary subtraction
template <class Type>
CMatrix::Matrix<Type> CMatrix::operator - (const CMatrix::Matrix<Type> firstMatrix, const CMatrix::Matrix<Type> secondMatrix)
{
    if (firstMatrix.size != secondMatrix.size)
        throw Exception::IncompatibleSubtraction();

    CMatrix::Matrix<Type> difference(firstMatrix.rows(), firstMatrix.columns());

    for(int i = 0; i < firstMatrix.elements(); i++)
        difference.values[i] = firstMatrix.values[i] - secondMatrix.values[i];

    return difference;
}

// Binary multiplication
template <class Type>
CMatrix::Matrix<Type> CMatrix::operator * (const CMatrix::Matrix<Type> firstMatrix, const CMatrix::Matrix<Type> secondMatrix)
{
    if (firstMatrix.columns() != secondMatrix.rows())
        throw Exception::IncompatibleMultiplication();

    CMatrix::Matrix<Type> product(firstMatrix.rows(), secondMatrix.columns());

    for(int i = 0; i < firstMatrix.rows(); i++)
        for(int j = 0; j < secondMatrix.columns(); j++)
        {
            product(i, j) = 0;
            for(int k = 0; k < firstMatrix.columns(); k++)
                product(i, j) += firstMatrix(i, k) * secondMatrix(k, j);
        }

    return product;
}


// Shorthand binary addition
template <class Type>
CMatrix::Matrix<Type>& CMatrix::Matrix<Type>::operator += (const CMatrix::Matrix<Type> secondMatrix)
{
    if (size != secondMatrix.size)
        throw Exception::IncompatibleAddition();

    for(int i = 0; i < elements(); i++)
        values[i] = values[i] + secondMatrix.values[i];

    return (*this);
}

// Shorthand binary subtraction
template <class Type>
CMatrix::Matrix<Type>& CMatrix::Matrix<Type>::operator -= (const CMatrix::Matrix<Type> secondMatrix)
{
    if (size != secondMatrix.size)
        throw Exception::IncompatibleSubtraction();

    for(int i = 0; i < elements(); i++)
        values[i] = values[i] - secondMatrix.values[i];

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

    for(int i = 0; i < elements(); i++)
        result.values[i] = -values[i];

    return result;
}

