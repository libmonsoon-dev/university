//
// Created by daniil_stepanenko on 14.11.2021.
//

#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <iostream>

#include "../include/array_utils.h"
#include "../include/sort.h"

typedef struct {
    const char *name;

    void (*fn)(int[], const int);
} sort;

int main() {
    int sizes[] = {100, 1000, 10000};

    sort sorts[] = {
            {"bubble",          bubble_sort},
            {"improved bubble", fast_path_bubble_sort},
            {"insert",          insert_sort},
            {"block",           block_sort}
    };

    for (auto size: sizes) {
        auto generated = generate_array(size);

        for (auto sort: sorts) {
            auto arr = deep_copy_array(generated, size);

            auto beforeSort = clock();
            sort.fn(arr, size);
            auto afterSort = clock();

            printf("sorting array with length %d using %s sort (%ld)\n", size, sort.name, afterSort - beforeSort);
            if (!is_sorted_array(arr, size)) {
                fprintf(stderr, "function %s sort failed to sort array", sort.name);
                exit(EXIT_FAILURE);
            }

            delete[] arr;
        }

        delete[] generated;
    }
}
