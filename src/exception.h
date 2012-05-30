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
                public: InvalidSizeSet(std::string message) : std::runtime_error(message) {}
            };

            class InvalidSizeReset : public std::runtime_error
            {
                public: InvalidSizeReset(std::string message) : std::runtime_error(message) {}
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
            static std::basic_string<char> InvalidSizeSet(unsigned int rows, unsigned int columns)
            {
                std::stringstream message;
                message << "Invalid attempt to set rows to " << rows << " and columns to " << columns;
                return message.str();
            }

            static std::basic_string<char> BadSizeReset(Size bound, unsigned int rows, unsigned int columns)
            {
                std::stringstream message;
                message << "Invalid attempt to reset rows to " << rows << " and columns to " << columns
                        << " from [" << bound.getRows() << ", " << bound.getColumns() << "]";
                return message.str();
            }

            static std::basic_string<char> AccessOutOfBound(Size bound, unsigned int row, unsigned int column)
            {
                std::stringstream message;
                message << "Invalid attempt to access (" << row << ", " << column << ") which lies "
                        <<  "outside bounds [" << bound.getRows() << ", " << bound.getColumns() << "]";
                return message.str();
            }
    };
}

#endif

