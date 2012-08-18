// Written by     : Chirantan Mitra

#ifndef MATRIX_SIZE_H
#define MATRIX_SIZE_H

namespace CMatrix
{
    class Size
    {
    private:
        long int rows;
        long int columns;

    public:
        Size();
        Size(long int rows, long int columns);
        void set(long int rows, long int columns);
        bool isValid() const;
        long int getRows() const;
        long int getColumns() const;
        long int elements() const;
        bool isSquare() const;
        bool operator == (const Size& otherSize) const;
        bool operator != (const Size& otherSize) const;
    };
}

#include "size/size.cpp"

#endif
