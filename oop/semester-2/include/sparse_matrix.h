#ifndef UNIVERSITY_SPARSE_MATRIX_H
#define UNIVERSITY_SPARSE_MATRIX_H

#include "point.h"
#include "slice.h"

template<typename T>
class SparseMatrix {
public:
    SparseMatrix();

    SparseMatrix(int rows, int columns);

    SparseMatrix(SparseMatrix &other);

    SparseMatrix(SparseMatrix &&other);

    void set(Point<T> point);

    void Print();

    SparseMatrix<T> Multiply(int multiplier);

    SparseMatrix<T> Multiply(SparseMatrix<T>);

    SparseMatrix<T> Add(SparseMatrix<T>);

    SparseMatrix<T> Transpose();

    bool Equal(SparseMatrix<T>);

    T At(int x, int y);

private:
    int rows;
    int columns;
    Slice<Point<T>> *points;

    int IndexOf(int x, int y);
};

SparseMatrix<int> scan_sparse_matrix();

template
class SparseMatrix<int>;

#endif //UNIVERSITY_SPARSE_MATRIX_H
