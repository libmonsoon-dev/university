//
// Created by daniil_stepanenko on 02.11.2021.
//

#include "../include/math.h"

template <typename T>
T project_abs(T x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

template double project_abs<double>(double);
