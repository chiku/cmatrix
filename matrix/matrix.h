// Written by     : Chirantan Mitra

#ifndef CMATRIX_H
#define CMATRIX_H

#include <iostream>
#include <sstream>

#include "storage_engine.h"
#include "exception.h"
#include "size.h"

namespace CMatrix
{
    template<typename Type> class Matrix;

    template<typename Type> Matrix<Type> operator + (const Matrix<Type> firstMatrix, const Matrix<Type> secondMatrix);
    template<typename Type> Matrix<Type> operator - (const Matrix<Type> firstMatrix, const Matrix<Type> secondMatrix);
    template<typename Type> Matrix<Type> operator * (const Matrix<Type> firstMatrix, const Matrix<Type> secondMatrix);

    template<typename Type> std::ostream& operator << (std::ostream& outputStream, const Matrix<Type>& matrix);
    template<typename Type> std::istream& operator >> (std::istream& inputStream, CMatrix::Matrix<Type>& matrix);


    template <class Type>
    class Matrix
    {
    private:
        Size size;
        StorageEngine<Type> engine;

        void clearMemory();
        void setMatrixAsUnassigned();

        Type& access(long int row, long int column);
        Type access(long int row, long int column) const;

    public:
        Matrix();
        Matrix(long int rows, long int columns);
        Matrix(const Matrix& otherMatrix);
        ~Matrix();

        Matrix<Type>& operator = (const Matrix& otherMatrix);

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

        Matrix<Type> scale(Type value);

        bool isSquare() const;
        bool isUnit() const;
        bool isZero() const;

        void fillWith(Type value);
        void fillWithZeros();

        Matrix<Type> invert();
        void mutateToInclude(Type value, long int row, long int column);

        template <typename FunctObj> Matrix<Type> map(FunctObj function);
        template <typename FunctObj> Matrix<Type>& fillByPosition(FunctObj function, long int xShift=0, long int yShift=0);
        template <typename FunctObj> Matrix<Type>& fillByPosition(FunctObj function, long int xShift, long int yShift, Type xScale, Type yScale);
        
        friend std::ostream& operator << <>(std::ostream& outputStream, const Matrix<Type>& firstMatrix);
    };
}

#include "core/base.cpp"
#include "core/accessor.cpp"
#include "core/equality.cpp"
#include "core/assignment.cpp"
#include "core/properties.cpp"
#include "core/numerical.cpp"
#include "core/functionoid.cpp"
#include "core/invert.cpp"
#include "core/mutators.cpp"
#include "core/populators.cpp"

#include "core/io/stream.cpp"

#endif
