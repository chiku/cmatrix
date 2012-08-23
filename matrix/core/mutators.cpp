// Written by     : Chirantan Mitra

template <class Type>
void CMatrix::Matrix<Type>::mutateToInclude(Type value, long int row, long int column)
{
	if (row < 0 || column < 0) {
		throw Exception::InvalidSizeReset(ExceptionBody::BadSizeOnMutate(size, row, column));
	}

	if (size.contains(row, column)) {
		access(row, column) = value;
		return;
	}

	if (! size.isValid()) {
		values->resize(column + 1);
		size = Size(1, column + 1);
		values = new std::vector<Type>(size.elements());
		access(row, column) = value;
		return;
	}

	CMatrix::Size newSize(std::max(rows(), row + 1), std::max(columns(), column + 1));
	std::vector<Type>* newValues = new std::vector<Type>(newSize.elements());

	for (long int i = 0; i < rows(); i++) {
		for (long int j = 0; j < columns(); j++) {
			(*newValues)[i * newSize.getColumns() + j] = access(i, j);
		}
	}

	delete values;
	values = newValues;
	size = newSize;

	access(row, column) = value;
}
