// File           : matrix_exceptions.h
// Written by     : Chirantan Mitra
// Created        : 26/03/2009

#ifndef MATRIX_EXCEPTIONS_H
#define MATRIX_EXCEPTIONS_H

namespace CMatrix
{
    class MatrixException
    {
        public:
            class InvalidSizeSet {};
            class SizeResetException {};
            class AccessOutOfBound {};

            class IncompatibleAddition {};
            class IncompatibleSubtraction {};
            class IncompatibleMultiplication {};
    };
}

#endif

