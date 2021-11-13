//
// Created by daniil_stepanenko on 13.11.2021.
//

#include "../include/geom.h"

template<typename T>
Point<T>::Point() {
    this->x = 0;
    this->y = 0;
}

template<typename T>
Point<T>::Point(T x, T y) {
    this->x = x;
    this->y = y;
}

template class Point<int>;
