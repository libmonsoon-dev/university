//
// Created by daniil_stepanenko on 13.11.2021.
//

#include <stdio.h>
#include <stdlib.h>

#include "../include/matrix.h"
#include "../include/io_utils.h"

template <typename T> inline const char* get_printf_format();

template <typename T>
int read_array(T* arr, int size) {
    auto format = get_printf_format<T>();

    for (int i = 0; i < size; i++) {
        printf("Введите значение элемента с индексом %i\n> ", i);
        if (scanf(format, &arr[i]) != 1) {
            printf("Невалидный ввод\n");
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}

template <typename T>
void print_array(T* arr, int size) {
    auto format = get_printf_format<T>();

    for (int i = 0; i < size; i++) {
        if (i != 0) {
            printf(" ");
        }
        printf(format, arr[i]);
    }
    printf("\n");
}

template <typename T> int read_matrix(Matrix<T>* matrix) {
    const char* format = get_printf_format<T>();
    T tmp;

    for (int i = 0; i < matrix->count_rows(); i++) {
        for (int j = 0; j < matrix->count_columns(); j++) {
            printf("Введите значение элемента с координатами (%i, %i)\n> ", i, j);
            if (scanf(format, &tmp) != 1) {
                printf("Недопустимое значение\n");
                return EXIT_FAILURE;
            }

            matrix->set_element(i, j, tmp);
        }
    }

    return EXIT_SUCCESS;
}

template <typename T> void print_matrix(Matrix<T>* matrix) {
    const char* format = get_printf_format<T>();

    for (int i = 0; i < matrix->count_rows(); i++) {
        for (int j = 0; j < matrix->count_columns(); j++) {
            if (j != 0) {
                printf(" ");
            }
            printf(format, matrix->get_element(i, j));
        }
        printf("\n");
    }
}

template<> inline const char* get_printf_format<int>() {
    return "%i";
}

template int read_array(int* arr, int size);

template void print_array(int* arr, int size);

template int read_matrix(Matrix<int>* matrix);

template void print_matrix(Matrix<int>* matrix);
