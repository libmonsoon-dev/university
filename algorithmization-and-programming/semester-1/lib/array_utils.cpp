//
// Created by daniil_stepanenko on 13.11.2021.
//

#include <cstdlib>
#include <iostream>
#include <climits>

template<typename T>
void swap_array_elements(T arr[], int i, int j) {
    T tmp = arr[j];

    arr[j] = arr[i];
    arr[i] = tmp;
}

template<typename T>
void delete_array_element(T arr[], int size, int index) {
    for (int i = index; i < (size - 1); i++) {
        swap_array_elements(arr, i, i + 1);
    }
}

int *generate_array(const int size) {
    auto arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand();
    }

    return arr;
}

template<typename T>
T *deep_copy_array(const T source[], int size) {
    auto arr = new T[size];
    for (int i = 0; i < size; i++) {
        arr[i] = source[i];
    }

    return arr;
}

template<typename T>
bool is_sorted_array(const T arr[], const int size) {
    for (auto i = size - 1; i > 0; i--) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }

    return true;
}

int array_max(const int arr[], const int size) {
    int max = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

template void swap_array_elements(int arr[], int i, int j);

template void delete_array_element(int arr[], int size, int index);

template int *deep_copy_array(const int source[], const int size);

template bool is_sorted_array(const int arr[], const int size);
