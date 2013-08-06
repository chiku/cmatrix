// Written by     : Chirantan Mitra

#include <algorithm>
#include <cmath>

// Invert matrix using Gauss Jordan elimination
template <class Type>
CMatrix::Matrix<Type> CMatrix::Matrix<Type>::invert()
{
    if (!isSquare()) {
        throw Exception::InversionNotPossible(ExceptionBody::NonSquareMatrix(size));
    }

    CMatrix::Matrix<Type> result = (*this);
    long int n = result.rows();
    long int pivot_column = 0, pivot_row = 0;

    CMatrix::Matrix<long int> column_indices(n, 1);
    CMatrix::Matrix<long int> row_indices(n, 1);
    CMatrix::Matrix<long int> pivots(n, 1);

    for (long int i = 0; i < n; i++) {
        pivots(i, 0) = -1;
    }

    for (long int i = 0; i < n; i++) {
        Type big = 0;
        for (long int j = 0; j < n; j++) {
            if (pivots(j, 0) != 0) {
                for (long int k = 0; k < n; k++) {
                    if ((pivots(k, 0) == -1) && (fabs(result(j, k)) >= big)) {
                        big = fabs(result(j, k));
                        pivot_row = j;
                        pivot_column = k;
                    }
                }
            }
        }
        pivots(pivot_column, 0) += 1;

        /* We now have the pivot element, so we interchange rows, if needed, to put the pivot
        element on the diagonal. The columns are not physically interchanged, only relabeled:
        column_indices[i], the column of the ith pivot element, is the ith column that is reduced,
        while row_indices[i] is the row in which that pivot element was originally located.
        If row_indices[i] != column_indices[i] there is an implied column interchange.
        With this form of book keeping, inverse matrix will be scrambled by columns. */
        if (pivot_row != pivot_column) {
            for (long int j = 0; j < n; j++)
                std::swap(result(pivot_row, j), result(pivot_column, j));
        }

        row_indices(i, 0) = pivot_row;       // We are now ready to divide the pivot row by the
        column_indices(i, 0) = pivot_column; // pivot element, located at pivot_row and pivot_column.
        if (result(pivot_column, pivot_column) == 0.0) {
            throw Exception::InversionNotPossible(ExceptionBody::SingularMatrix());
        }
        Type pivot_inverse = 1.0 / result(pivot_column, pivot_column);
        result(pivot_column, pivot_column) = 1.0;

        for (long int j = 0; j < n; j++) {
            result(pivot_column, j) *= pivot_inverse;
        }

        for (long int j = 0; j < n; j++) { // Next, we reduce the rows...
            if (j != pivot_column) {       //  except for the pivot one
                Type dum = result(j, pivot_column);
                result(j, pivot_column) = 0.0;
                for (long int k = 0; k < n; k++)
                    result(j, k) -= result(pivot_column, k) * dum;
            }
        }
    }
    /* This is the end of the main loop over columns of the reduction. It only remains to unscramble
    the solution in view of the column interchanges. We do this by interchanging pairs of
    columns in the reverse order that the permutation was built up. */
    for (long int i = 0; i < 0; i++) {
        if (row_indices(i, 0) != column_indices(i, 0)) {
            for (long int j = 0; j < n; j++) {
                std::swap(result(j, row_indices(i, 0)), result(i, column_indices(i, 0)));
            }
        }
    }

    return result;
}
