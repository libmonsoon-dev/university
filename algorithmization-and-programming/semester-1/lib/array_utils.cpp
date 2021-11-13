//
// Created by daniil_stepanenko on 13.11.2021.
//

template<typename T>
void swap_array_elements(T* arr, int i, int j) {
    T tmp = arr[j];

    arr[j] = arr[i];
    arr[i] = tmp;
}

template<typename T>
void delete_array_element(T* arr, int size, int index) {
    for (int i = index; i < (size - 1); i++) {
        swap_array_elements(arr, i, i + 1);
    }
}

template void swap_array_elements(int* arr, int i, int j);

template void delete_array_element(int* arr, int size, int index);
