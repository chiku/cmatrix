// Written by     : Chirantan Mitra
// Created        : 21/03/2009

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <matrix_exceptions.h>

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

            unsigned int rows;
            unsigned int columns;

            void clearMemory();
            void setMatrixAsUnassigned();

        public:
            Matrix();
            Matrix(unsigned int rows, unsigned int columns);
            Matrix(const Matrix& otherMatrix);
            ~Matrix();

            Matrix<Type>& operator=(const Matrix& otherMatrix);

            int getRows() const;
            int getColumns() const;

            void setSize(unsigned int rows, unsigned int columns);

            bool operator==(const Matrix& otherMatrix) const;
            bool operator!=(const Matrix& otherMatrix) const;

            Type& operator()(unsigned int row, unsigned int column);
            Type operator()(unsigned int row, unsigned int column) const;

            friend Matrix<Type> operator + <>(const Matrix<Type> firstMatrix, const Matrix<Type> secondMatrix);
            friend Matrix<Type> operator - <>(const Matrix<Type> firstMatrix, const Matrix<Type> secondMatrix);
            friend Matrix<Type> operator * <>(const Matrix<Type> firstMatrix, const Matrix<Type> secondMatrix);

            Matrix<Type>& operator += (const Matrix<Type> secondMatrix);
            Matrix<Type>& operator -= (const Matrix<Type> secondMatrix);
            Matrix<Type>& operator *= (const Matrix<Type> secondMatrix);

            Matrix<Type> operator + ();
            Matrix<Type> operator - ();

            bool isSquare() const;

            template <typename FunctObj> Matrix<Type> map(FunctObj function);
            template <typename FunctObj> Matrix<Type>& fillByPosition(FunctObj function, int xShift=0, int yShift=0);
            template <typename FunctObj> Matrix<Type>& fillByPosition(FunctObj function, int xShift, int yShift, Type xScale, Type yScale);
            
            friend std::ostream& operator << <>(std::ostream& outputStream, const Matrix<Type>& firstMatrix);
            void pngize(const char* fileName, Type redScale, Type blueScale, Type greenScale) const;
            template <typename RedFunc, typename BlueFunc, typename GreenFunc> void pngize(const char* fileName, RedFunc redScale, BlueFunc blueScale, GreenFunc greenScale) const;
    };
}

#endif

