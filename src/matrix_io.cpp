// Written by     : Chirantan Mitra

#include <matrix.h>

// Output to stream
template <class Type>
std::ostream& CMatrix::operator << (std::ostream& outputStream, const CMatrix::Matrix<Type>& firstMatrix)
{
    outputStream << '\n';
    for(int i = 0; i < firstMatrix.rows(); i++)
    {
        for(int j = 0; j< firstMatrix.columns(); j++)
            outputStream << firstMatrix(i, j) << '\t';
        outputStream << '\n';
    }

    return outputStream;
}

