//
// Created by daniil_stepanenko on 11.01.2022.
//

#include <cmath>

#include "../include/array_utils.h"
#include "../include/number_utils.h"

void insert_sort_insert(int arr[], int *bottom, int *top, int pos, int value);

void bubble_sort(int arr[], const int size) {
    for (auto k = 0; k < size - 1; k++) {
        for (auto i = 0; i < size - k - 1; i++) {
            if (arr[i + 1] < arr[i]) {
                swap_array_elements(arr, i, i + 1);
            }
        }
    }
}

void fast_path_bubble_sort(int arr[], const int size) {
    for (auto k = 0; k < size - 1; k++) {
        bool swapped = false;

        for (auto i = 0; i < size - k - 1; i++) {
            if (arr[i + 1] < arr[i]) {
                swap_array_elements(arr, i, i + 1);
                swapped = true;
            }
        }

        if (!swapped) {
            return;
        }
    }
}

int get_insert_position(const int arr[], int bottom, int top, int value) {
    while (bottom <= top) {
        int mid = bottom + (top - bottom) / 2;
        if (value == arr[mid]) {
            bottom = mid;
            break;
        } else if (value > arr[mid]) {
            bottom = mid + 1;
        } else {
            top = mid - 1;
        }
    }

    // preserving the order of equal elements
    while (value == arr[bottom]) {
        bottom++;
    }

    return bottom;
}

void insert_sort(int arr[], const int size) {
    int tmp_arr[2 * size - 1];

    tmp_arr[size - 1] = arr[0];
    int bottom = size - 1;
    int top = bottom;

    for (int i = 1; i < size; i++) {
        auto pos = get_insert_position(tmp_arr, bottom, top, arr[i]);
        insert_sort_insert(tmp_arr, &bottom, &top, pos, arr[i]);
    }

    for (int i = 0; i <= top - bottom; i++) {
        arr[i] = tmp_arr[bottom + i];
    }
}

void insert_sort_insert(int arr[], int *bottom, int *top, int pos, const int value) {
    if (*top - pos < pos - *bottom) {
        for (int i = *top; i >= pos; i--) {
            swap_array_elements(arr, i, i + 1);
        }
        (*top)++;
    } else {
        for (int i = *bottom; i < pos; i++) {
            swap_array_elements(arr, i, i - 1);
        }
        (*bottom)--;
        pos--;
    }

    arr[pos] = value;
}

void block_sort(int arr[], const int size) {
    int matrix[10][size];
    int index[10];

    int number;
    int max_number_digits = count_digits(array_max(arr, size));
    for (int digits = 1; digits <= max_number_digits; digits++) {
        for (int &i: index) {
            i = 0;
        }

        int y = int(pow(10, digits));
        int z = int(pow(10, digits - 1));
        for (int i = 0; i < size; i++) {
            number = arr[i] % y / z;
            matrix[number][index[number]] = arr[i];
            index[number]++;
        }

        int i = 0;
        for (number = 0; number < 10; number++) {
            for (int j = 0; j < index[number]; j++) {
                arr[i] = matrix[number][j];
                i++;
            }
        }
    }
}
