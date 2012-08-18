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

        class InversionNotPossible : public std::runtime_error
        {
            public: InversionNotPossible(std::string message) : std::runtime_error(message) {}
        };
    };

    class ExceptionBody
    {
    public:
        static std::basic_string<char> InvalidSizeSet(long int rows, long int columns)
        {
            std::stringstream message;
            message << "Invalid attempt to set rows to " << rows << " and columns to " << columns;
            return message.str();
        }

        static std::basic_string<char> BadSizeReset(Size bounds, long int rows, long int columns)
        {
            std::stringstream message;
            message << "Invalid attempt to reset rows to " << rows << " and columns to " << columns
                    << " from [" << bounds.getRows() << ", " << bounds.getColumns() << "]";
            return message.str();
        }

        static std::basic_string<char> AccessOutOfBound(Size bounds, long int row, long int column)
        {
            std::stringstream message;
            message << "Invalid attempt to access (" << row << ", " << column << ") which lies "
                    <<  "outside bounds [" << bounds.getRows() << ", " << bounds.getColumns() << "]";
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

        static std::basic_string<char> NonSquareMatrix(Size bounds)
        {
            std::stringstream message;
            message << "Cannot invert a non-square matrix [" << bounds.getRows() << ", " << bounds.getColumns() << "]";
            return message.str();
        }

        static std::basic_string<char> SingularMatrix()
        {
            return "Cannot invert a singular matrix";
        }
    };
}

#endif
