//
// Created by daniil_stepanenko on 14.11.2021.
//

#include <cstdio>
#include <cstdlib>

#include "../include/time.h"
#include "../include/lab4.h"

int main() {
    int size;

    printf("Введите размер массива\n> ");
    if (scanf("%i", &size) != 1) {
        printf("Невалидный ввод\n");
        return EXIT_FAILURE;
    }

    time_of_day list[size];

    int h;
    int m;
    int s;

    for (int i = 0; i < size; i++) {
        printf("Введите время в формате hh:mm:ss\n> ");
        if (scanf("%i:%i:%i", &h, &m, &s) != 3) {
            printf("Невалидный ввод\n");
            return EXIT_FAILURE;
        }

        list[i] = make_time_of_day(h, m, s);
    }

    auto result = lab4(list, size);
    print_time_of_day(result);

    return EXIT_SUCCESS;
}
