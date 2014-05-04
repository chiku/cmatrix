// Written by     : Chirantan Mitra

#ifndef CMATRIX_SIZE_H
#define CMATRIX_SIZE_H

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
        bool matches(long int otherRows, long int otherColumns) const;
        bool contains(long int rowBound, long int columnBound) const;
        bool operator == (const Size& otherSize) const;
        bool operator != (const Size& otherSize) const;
    };
}

#include "impl/size.cpp"

#endif
