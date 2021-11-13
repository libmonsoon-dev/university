//
// Created by daniil_stepanenko on 13.11.2021.
//

#include <stdio.h>
#include <stdlib.h>

#include "../include/geom.h"
#include "../include/lab3.h"

int main() {
    int field_size_y;
    int field_size_x;
    Point<int> a;
    Point<int> b;

    printf("Введите размер поля (через пробел)\n> ");
    if (scanf("%i %i", &field_size_y, &field_size_x) != 2) {
        printf("Невалидный ввод\n");
        return EXIT_FAILURE;
    }

    printf("Введите положение первого ферзя (через пробел)\n> ");
    if (scanf("%i %i", &a.y, &a.x) != 2) {
        printf("Невалидный ввод\n");
        return EXIT_FAILURE;
    }

    printf("Введите положение второго ферзя (через пробел)\n> ");
    if (scanf("%i %i", &b.y, &b.x) != 2) {
        printf("Невалидный ввод\n");
        return EXIT_FAILURE;
    }

    if (lab3_2(field_size_y, field_size_x, a, b)) {
        printf("Ферзи находятся под боем друг друга");
    } else {
        printf("Ферзи не находятся под боем друг друга");
    }

    return EXIT_SUCCESS;
}
