//
// Created by daniil_stepanenko on 13.11.2021.
//

#ifndef UNIVERSITY_IO_UTILS_H
#define UNIVERSITY_IO_UTILS_H

#include "matrix.h"

template <typename T> int read_array(T* arr, int size);

template <typename T> void print_array(T* arr, int size);

template <typename T> int read_matrix(Matrix<T>* matrix);

template <typename T> void print_matrix(Matrix<T>* matrix);

#endif //UNIVERSITY_IO_UTILS_H
