// Written by     : Chirantan Mitra

#include <iomanip>

namespace cmatrix
{

// Output to stream
template <class Type>
std::ostream& operator << (std::ostream& outputStream, const Matrix<Type>& matrix)
{
    for (int i = 0; i < matrix.rows(); i++) {
        for (int j = 0; j< matrix.columns(); j++) {
            outputStream << std::setiosflags(std::ios::fixed) << std::setprecision(4) << matrix.access(i, j) << std::string("\t");
        }

        outputStream << std::string("\n");
    }

    return outputStream;
}

// Input from stream
template <class Type>
std::istream& operator >> (std::istream& inputStream, Matrix<Type>& matrix)
{
    for (long int i = 0; i < matrix.rows(); i++) {
        for (long int j = 0; j < matrix.columns(); j++) {
            inputStream >> matrix.access(i, j);
        }
    }

    return inputStream;
}

} // namespace cmatrix
