//
// Created by daniil_stepanenko on 13.11.2021.
//

#include "../include/matrix.h"

template<typename T>
Matrix<T>::Matrix(int rows, int columns) {
    this->rows = rows;
    this->columns = columns;

    this->data = new T *[rows];
    for (int i = 0; i < rows; i++) {
        this->data[i] = new T[columns];
    }
}

template<typename T>
Matrix<T>::~Matrix() {
    for (int i = 0; i < this->rows; i++) {
        delete[] this->data[i];
    }

    delete[] this->data;
}

template<typename T>
inline int Matrix<T>::count_rows() {
    return this->rows;
}

template<typename T>
inline int Matrix<T>::count_columns() {
    return this->columns;
}

template<typename T>
inline T Matrix<T>::get_element(int y, int x) {
    return this->data[y][x];
}

template<typename T>
inline void Matrix<T>::set_element(int y, int x, T val) {
     this->data[y][x] = val;
}
