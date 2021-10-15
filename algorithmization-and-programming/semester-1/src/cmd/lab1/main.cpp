//
// Created by daniil_stepanenko on 10.10.2021.
//

#include "../../lab1/lab1.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    double input;
    printf("Введите число\n> ");
    if (scanf("%lf", &input) != 1) {
        printf("Невалидный ввод\n");
        return EXIT_FAILURE;
    }

    double output = lab1(input);
    printf("Результат вычислений: %lf\n", output);
    return EXIT_SUCCESS;
}
