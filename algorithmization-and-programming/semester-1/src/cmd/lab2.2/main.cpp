#include <stdio.h>
#include <stdlib.h>
#include <cmath>

#include "../../lab2/lab2.h"

int main() {
    double y;

    for (double x = -0.9; x <= 0.9; x += 0.1) {
        y = lab2_2(x);
        printf("f(%lf) = %lf (%lf)\n", x, y, asin(x));
    }

    return EXIT_SUCCESS;
}
