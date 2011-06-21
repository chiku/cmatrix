// Written by     : Chirantan Mitra

#ifndef MATRIX_EXCEPTIONS_H
#define MATRIX_EXCEPTIONS_H

#include <stdexcept>

namespace CMatrix
{
    class MatrixException
    {
        public:
            class InvalidSizeSet : public std::runtime_error
            {
                public: InvalidSizeSet() : std::runtime_error("Invalid size set") {}
            };

            class SizeResetException : public std::runtime_error
            {
                public: SizeResetException() : std::runtime_error("Invalid size set") {}
            };

            class AccessOutOfBound : public std::runtime_error
            {
                public: AccessOutOfBound() : std::runtime_error("Attempt to access out of bound") {}
            };

            class IncompatibleAddition : public std::runtime_error
            {
                public: IncompatibleAddition() : std::runtime_error("Incompatible addition") {}
            };

            class IncompatibleSubtraction : public std::runtime_error
            {
                public: IncompatibleSubtraction() : std::runtime_error("Incompatible subtraction") {}
            };

            class IncompatibleMultiplication : public std::runtime_error
            {
                public: IncompatibleMultiplication() : std::runtime_error("Incompatible multiplication") {}
            };
    };
}

#endif

