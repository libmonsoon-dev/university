#include <cstdio>

#include "../include/point.h"

Point::Point() {
    this->x = 0;
    this->y = 0;
}

Point::Point(int x, int y, int value) {
    this->x = x;
    this->y = y;
    this->value = value;
}

Point Point::transpose() {
    return Point(this->y, this->x, value);
}

Point Point::multiply(int multiplier) {
    return Point(this->x, this->y, this->value * multiplier);
}

Point scan_point() {
    int x, y, value;
    printf("Введите положение х, y и значение элемента матрицы (через пробел)\n> ");
    if (scanf("%i %i %i", &x, &y, &value) != 3) {
        throw "Невалидный ввод\n";
    }
    return {x, y, value};
}
