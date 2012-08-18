// Written by     : Chirantan Mitra

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <sstream>

#include "exception.h"
#include "size.h"

namespace CMatrix
{
    template<typename Type> class Matrix;

    template<typename Type> Matrix<Type> operator + (const Matrix<Type> firstMatrix, const Matrix<Type> secondMatrix);
    template<typename Type> Matrix<Type> operator - (const Matrix<Type> firstMatrix, const Matrix<Type> secondMatrix);
    template<typename Type> Matrix<Type> operator * (const Matrix<Type> firstMatrix, const Matrix<Type> secondMatrix);

    template<typename Type> std::ostream& operator << (std::ostream& outputStream, const Matrix<Type>& firstMatrix);


    template <class Type>
    class Matrix
    {
    private:
        Type* values;

        Size size;

        void clearMemory();
        void setMatrixAsUnassigned();

        Type& access(long int row, long int column);
        Type access(long int row, long int column) const;

    public:
        Matrix();
        Matrix(long int rows, long int columns);
        Matrix(const Matrix& otherMatrix);
        ~Matrix();

        Matrix<Type>& operator=(const Matrix& otherMatrix);

        long int rows() const;
        long int columns() const;
        long int elements() const;

        void setSize(long int rows, long int columns);

        bool operator == (const Matrix& otherMatrix) const;
        bool operator != (const Matrix& otherMatrix) const;

        Type& operator()(long int row, long int column);
        Type operator()(long int row, long int column) const;

        friend Matrix<Type> operator + <>(const Matrix<Type> firstMatrix, const Matrix<Type> secondMatrix);
        friend Matrix<Type> operator - <>(const Matrix<Type> firstMatrix, const Matrix<Type> secondMatrix);
        friend Matrix<Type> operator * <>(const Matrix<Type> firstMatrix, const Matrix<Type> secondMatrix);

        Matrix<Type>& operator += (const Matrix<Type> secondMatrix);
        Matrix<Type>& operator -= (const Matrix<Type> secondMatrix);
        Matrix<Type>& operator *= (const Matrix<Type> secondMatrix);

        Matrix<Type> operator + ();
        Matrix<Type> operator - ();

        bool isSquare() const;
        bool isUnit() const;
        bool isZero() const;

        Matrix<Type> invert();

        template <typename FunctObj> Matrix<Type> map(FunctObj function);
        template <typename FunctObj> Matrix<Type>& fillByPosition(FunctObj function, long int xShift=0, long int yShift=0);
        template <typename FunctObj> Matrix<Type>& fillByPosition(FunctObj function, long int xShift, long int yShift, Type xScale, Type yScale);
        
        friend std::ostream& operator << <>(std::ostream& outputStream, const Matrix<Type>& firstMatrix);
        void pngize(const char* fileName, Type redScale, Type blueScale, Type greenScale) const;
        template <typename RedFunc, typename BlueFunc, typename GreenFunc> void pngize(const char* fileName, RedFunc redScale, BlueFunc blueScale, GreenFunc greenScale) const;
    };
}

#include "matrix/base.cpp"
#include "matrix/properties.cpp"
#include "matrix/numerical.cpp"
#include "matrix/functionoid.cpp"
#include "matrix/invert.cpp"

#include "matrix/io/stream.cpp"

#ifdef WITH_PNG
#include "matrix/io/png.cpp"
#endif

#endif
