//
// Created by daniil_stepanenko on 13.11.2021.
//

#include <cmath>

#include "../include/array_utils.h"
#include "../include/lab3.h"

void lab3_1(int* arr, int size) {
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
