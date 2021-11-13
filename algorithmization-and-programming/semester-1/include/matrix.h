//
// Created by daniil_stepanenko on 13.11.2021.
//

#ifndef UNIVERSITY_MATRIX_H
#define UNIVERSITY_MATRIX_H

template <typename T>
class Matrix {
public:
    Matrix(int rows, int columns);
    ~Matrix();

    int count_rows();
    int count_columns();

    T get_element(int x, int y);
    void set_element(int x, int y, T val);
private:
    int rows;
    int columns;
    T** data;
};

template class Matrix<int>;

#endif //UNIVERSITY_MATRIX_H
