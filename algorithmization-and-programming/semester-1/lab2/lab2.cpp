//
// Created by daniil_stepanenko on 15.10.2021.
//

#include "cmath"

#include "lab2.h"

double lab2_1(double alpha, double beta, double gamma, double omega) {
    return 2 * sin(alpha - beta) + cos(gamma - omega);
}

double calc_tailor_element(double n, double x);

double abs_double(double x);

double lab2_2(double x) {
    double min_element = pow(10, -6);
    double sum = 0, n = 0;

    while (true) {
        double element = calc_tailor_element(n, x);
        n++;

        sum += element;
        if (abs_double(element) < min_element) {
            return sum;
        }
    }
}

// (1 * 3 * 5 .. (2n-1) x ^ (2n+1)) / (2 * 4 * 6 .. (2n) * (2n+1))
// n = 0..inf
// |x| < 1
double calc_tailor_element(double n, double x) {
    double numerator = 1, denominator = 1;

    for (double i = 1; i <= 2*n-1; i += 2) {
        numerator *= i;
    }
    numerator *= pow(x, 2*n + 1);

    for (double i = 2; i <= 2*n; i += 2) {
        denominator *= i;
    }
    denominator *= 2*n + 1;

    return numerator / denominator;
}

double abs_double(double x) {
    if (x < 0) {
        return -x;
    }
    return x;
}
