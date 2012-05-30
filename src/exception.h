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
                public: IncompatibleAddition(std::string message) : std::runtime_error(message) {}
            };

            class IncompatibleSubtraction : public std::runtime_error
            {
                public: IncompatibleSubtraction(std::string message) : std::runtime_error(message) {}
            };

            class IncompatibleMultiplication : public std::runtime_error
            {
                public: IncompatibleMultiplication(std::string message) : std::runtime_error(message) {}
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

            static std::basic_string<char> IncompatibleAddition(Size first, Size second)
            {
                std::stringstream message;
                message << "Cannot add [" << first.getRows() << ", " << first.getColumns() << "] "
                        <<  "and [" << second.getRows() << ", " << second.getColumns() << "]";
                return message.str();
            }

            static std::basic_string<char> IncompatibleSubtraction(Size first, Size second)
            {
                std::stringstream message;
                message << "Cannot subtract [" << second.getRows() << ", " << second.getColumns() << "] "
                        <<  "from [" << first.getRows() << ", " << first.getColumns() << "]";
                return message.str();
            }

            static std::basic_string<char> IncompatibleMultiplication(Size first, Size second)
            {
                std::stringstream message;
                message << "Cannot multiply [" << first.getRows() << ", " << first.getColumns() << "] "
                        <<  "with [" << second.getRows() << ", " << second.getColumns() << "]";
                return message.str();
            }
    };
}

#endif

