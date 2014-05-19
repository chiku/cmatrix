// Written by     : Chirantan Mitra

#ifndef CMATRIX_STORAGE_ENGINE_H
#define CMATRIX_STORAGE_ENGINE_H

#include "size.h"

namespace cmatrix
{

template <class Type>
class StorageEngine
{
public:
    bool isMemoryAssigned() const
    {
        return values != NULL;
    }

    void unallocateMemory() const
    {
        delete[] values;
    }

    void markMemoryAsUnused()
    {
        values = NULL;
    }

    void allocateMemory(Size size)
    {
        values = new Type[size.elements()];
        this->size = size;
    }

    // Lvalue element accessor - unchecked
    Type& access(long int row, long int column)
    {
        return values[row * size.getColumns() + column];
    }

    // Rvalue element accessor (const) - unchecked
    Type access(long int row, long int column) const
    {
        return values[row * size.getColumns() + column];
    }

private:
    Type* values;
    Size size;
};

} // namespace cmatrix

#endif
