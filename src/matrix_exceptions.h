// Written by     : Chirantan Mitra

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

