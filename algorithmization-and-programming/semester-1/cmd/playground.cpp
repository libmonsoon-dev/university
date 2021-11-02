//
// Created by daniil_stepanenko on 16.10.2021.
//

#include <stdio.h>
#include <stdlib.h>

#include "../include/factorial.h"

int main() {
    FactorialCache<int> a;
    FactorialCache<int> b;

    printf("%d\n", a.factorial(1) + a.factorial(2) + a.factorial(3) + a.factorial(4) + a.factorial(5));
    printf("%d\n", b.factorial_sum(5));

    return EXIT_SUCCESS;
}
