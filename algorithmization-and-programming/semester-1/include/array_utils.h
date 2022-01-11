//
// Created by daniil_stepanenko on 13.11.2021.
//

#ifndef UNIVERSITY_ARRAY_UTILS_H
#define UNIVERSITY_ARRAY_UTILS_H

template<typename T>
void swap_array_elements(T arr[], int i, int j);

template<typename T>
void delete_array_element(T arr[], int size, int index);

int *generate_array(int size);

template<typename T>
T *deep_copy_array(const T source[], int size);

template<typename T>
bool is_sorted_array(const T arr[], int size);

int array_max(const int arr[], int size);

#endif //UNIVERSITY_ARRAY_UTILS_H
