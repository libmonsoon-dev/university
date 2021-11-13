//
// Created by daniil_stepanenko on 13.11.2021.
//

#ifndef UNIVERSITY_MATRIX_H
#define UNIVERSITY_MATRIX_H

#include "geom.h"

template <typename T>
class Matrix {
public:
    Matrix(int rows, int columns);
    ~Matrix();

    int count_rows();
    int count_columns();
    bool is_include(Point<int> p);

    T get_element(int y, int x);
    T get_element(Point<int> p);
    void set_element(int y, int x, T val);
    void set_element(Point<int> p, T val);
private:
    int rows;
    int columns;
    T** data;
};

template class Matrix<int>;
template class Matrix<bool>;

#endif //UNIVERSITY_MATRIX_H
