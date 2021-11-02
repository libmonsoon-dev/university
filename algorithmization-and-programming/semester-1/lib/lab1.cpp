//
// Created by daniil_stepanenko on 10.10.2021.
//

#include "cmath"
#include "../include/lab1.h"

double lab1(double x) {
    if (x < 0) {
        return -pow(x, 2);
    } else {
        return x * exp(-x);
    }
}
