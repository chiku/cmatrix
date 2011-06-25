// Written by     : Chirantan Mitra

#ifndef MATRIX_SIZE_H
#define MATRIX_SIZE_H

namespace CMatrix
{
    class Size
    {
        private:
            unsigned int rows;
            unsigned int columns;

        public:
            Size();
            Size(int rows, int columns);
            void set(int rows, int columns);
            bool isValid() const;
            int getRows() const;
            int getColumns() const;
            int elements() const;
            int isSquare() const;
            bool operator==(const Size& otherSize) const;
            bool operator != (const Size& otherSize) const;
    };
}

#endif
