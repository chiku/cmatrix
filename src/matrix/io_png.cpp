// Written by     : Chirantan Mitra

#include <vendor/pngwriter/pngwriter.h>

// Output a png using constant colour scale applied for all colors
template <class Type>
void CMatrix::Matrix<Type>::pngize(const char* fileName, Type redScale, Type blueScale, Type greenScale) const
{
    pngwriter png(rows(), columns(), 0, fileName);
    for(int i = 0; i < rows(); i++)
        for (int j = 0; j < columns(); j++)
            png.plot(i, j, redScale * (*this)(i, j), blueScale * (*this)(i, j), greenScale * (*this)(i, j));

   png.close();
}

// Output a png using variable colour scale applied for all colors
template <class Type>
template <typename RedFunc, typename BlueFunc, typename GreenFunc>
void CMatrix::Matrix<Type>::pngize(const char* fileName, RedFunc redScale, BlueFunc blueScale, GreenFunc greenScale) const
{
    pngwriter png(rows(), columns(), 0, fileName);
    for(int i = 0; i < rows(); i++)
        for (int j = 0; j < columns(); j++)
            png.plot(i, j, (*redScale)(i, j) * (*this)(i, j), (*blueScale)(i, j) * (*this)(i, j), (*greenScale)(i, j) * (*this)(i, j));

   png.close();
}

