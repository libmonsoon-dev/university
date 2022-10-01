#ifndef UNIVERSITY_SPARSE_MATRIX_H
#define UNIVERSITY_SPARSE_MATRIX_H

#include "point.h"
#include "slice.h"

class SparseMatrix {
public:
    SparseMatrix();

    SparseMatrix(int rows, int columns);

    SparseMatrix(SparseMatrix &other);

    SparseMatrix(SparseMatrix &&other);

    void set(Point point);

    void Print();

    SparseMatrix Multiply(int multiplier);

    SparseMatrix Multiply(SparseMatrix);

    SparseMatrix Add(SparseMatrix);

    SparseMatrix Transpose();

    bool Equal(SparseMatrix);

    int At(int x, int y);

private:
    int rows;
    int columns;
    Slice *points;

    int IndexOf(int x, int y);
};

SparseMatrix scan_sparse_matrix();

#endif //UNIVERSITY_SPARSE_MATRIX_H
