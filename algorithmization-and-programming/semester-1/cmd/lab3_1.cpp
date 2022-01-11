//
// Created by daniil_stepanenko on 13.11.2021.
//

#include <cstdlib>

#include "../include/lab3.h"
#include "../include/io_utils.h"

int main() {
    const int size = 10;
    int arr[size];

    read_array(arr, size);
    print_array(arr, size);
    lab3_1(arr, size);
    print_array(arr, size - 2);

    return EXIT_SUCCESS;
}
