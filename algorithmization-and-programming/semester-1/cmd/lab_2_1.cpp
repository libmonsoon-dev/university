#include <stdio.h>
#include <stdlib.h>

#include "../lab2/lab2.h"

int main() {
    double beta, gamma, omega, y;

    printf("Введите β\n> ");
    if (scanf("%lf", &beta) != 1) {
        printf("Недопустимое значение\n");
        return EXIT_FAILURE;
    }

    printf("Введите γ\n> ");
    if (scanf("%lf", &gamma) != 1) {
        printf("Недопустимое значение\n");
        return EXIT_FAILURE;
    }

    printf("Введите ω\n> ");
    if (scanf("%lf", &omega) != 1) {
        printf("Недопустимое значение\n");
        return EXIT_FAILURE;
    }

    for (double alpha = 0; alpha <= 1; alpha+= 0.2) {
        y = lab2_1(alpha, beta, gamma, omega);
        printf("f(%lf) = %lf\n", alpha, y);
    }

    return EXIT_SUCCESS;
}
