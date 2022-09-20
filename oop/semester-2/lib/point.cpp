#include <cstdio>

#include "../include/point.h"

template<typename T>
Point<T>::Point() {
    this->x = 0;
    this->y = 0;
}

template<typename T>
Point<T>::Point(int x, int y, T value) {
    this->x = x;
    this->y = y;
    this->value = value;
}

template<typename T>
Point<T> Point<T>::transpose() {
    return Point(this->y, this->x, value);
}

template<typename T>
Point<T> Point<T>::multiply(T multiplier) {
    return Point<T>(this->x, this->y, this->value * multiplier);
}

Point<int> scan_point() {
    int x, y, value;
    printf("Введите положение х, y и значение элемента матрицы (через пробел)\n> ");
    if (scanf("%i %i %i", &x, &y, &value) != 3) {
        throw "Невалидный ввод\n";
    }
    return {x, y, value};
}
