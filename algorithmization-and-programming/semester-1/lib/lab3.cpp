//
// Created by daniil_stepanenko on 13.11.2021.
//

#include <cmath>
#include <cstdio>
#include <cstdlib>

#include "../include/geom.h"
#include "../include/matrix.h"
#include "../include/array_utils.h"
#include "../include/lab3.h"

void lab3_1(int arr[], int size) {
    int max_element_index = 0;
    int min_element_index = 0;

    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[max_element_index]) {
            max_element_index = i;
        }

        if (arr[i] < arr[min_element_index]) {
            min_element_index = i;
        }
    }

    delete_array_element(arr, size, fmax(max_element_index, min_element_index));
    delete_array_element(arr, size, fmin(max_element_index, min_element_index));
}

inline bool check_direction(Matrix<bool> *field, Point<int> point, int dy, int dx) {
    while (field->is_include(point)) {
        if (field->get_element(point)) {
            return true;
        }

        point.y += dy;
        point.x += dx;
    }

    return false;
}

bool lab3_2(int field_size_y, int field_size_x, Point<int> a, Point<int> b) {
    auto field = new Matrix<bool>(field_size_y, field_size_x);
    if (!field->is_include(a) || !field->is_include(b)) {
        printf("Недопустимое значение координат: значения вне границ поля\n");
        exit(EXIT_FAILURE);
    }

    if (a.y == b.y || a.x == b.x) {
        delete field;
        return true;
    }

    field->set_element(a.y, a.x, true);

    auto result = check_direction(field, b, 1, 1)
                  || check_direction(field, b, 1, -1)
                  || check_direction(field, b, -1, 1)
                  || check_direction(field, b, -1, -1);

    delete field;
    return result;
}
