// Written by     : Chirantan Mitra

#ifndef MATRIX_EXCEPTIONS_H
#define MATRIX_EXCEPTIONS_H

#include <stdexcept>

#include "size.h"

namespace CMatrix
{
    class Exception
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
                public: AccessOutOfBound(std::string message) : std::runtime_error(message) {}
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

    class ExceptionBody
    {
        public:
            static std::basic_string<char> AccessOutOfBound(Size bound, unsigned int row, unsigned int column)
            {
                std::stringstream message;
                message << "Attempt to access out of bound. (" << row << ", " << column << ")"
                        <<  " lies outside [" << bound.getRows() << ", " << bound.getColumns() << "]";
                return message.str();
            };
    };
}

#endif

