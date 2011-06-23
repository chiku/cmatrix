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
            Size()
            {
                rows    = 0;
                columns = 0;
            }

            Size(int rows, int columns)
            {
                set(rows, columns);
            }

            void set(int rows, int columns)
            {
                (*this).rows    = rows;
                (*this).columns = columns;
            }

            bool isValid() const
            {
                return rows > 0 && columns > 0;
            }

            int getRows() const
            {
                return rows;
            }

            int getColumns() const
            {
                return columns;
            }

            int elements() const
            {
                return getRows() * getColumns();
            }

            int isSquare() const
            {
                return getRows() == getColumns();
            }
    };
}

#endif
