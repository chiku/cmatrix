// Written by     : Chirantan Mitra

namespace cmatrix
{

template <class Type>
void Matrix<Type>::mutateToInclude(Type value, long int row, long int column)
{
	if (row < 0 || column < 0) {
		throw Exception::InvalidSizeReset(ExceptionBody::BadSizeOnMutate(size, row, column));
	}

	if (size.contains(row, column)) {
		access(row, column) = value;
		return;
	}

	Size newSize(std::max(rows(), row + 1), std::max(columns(), column + 1));
	StorageEngine<Type> newEngine;
	newEngine.allocateMemory(newSize);

	for (long int i = 0; i < rows(); i++) {
		for (long int j = 0; j < columns(); j++) {
			newEngine.access(i, j) = engine.access(i, j);
		}
	}

	engine.markMemoryAsUnused();
	engine = newEngine;
	size = newSize;

	access(row, column) = value;
}

} // namespace cmatrix
