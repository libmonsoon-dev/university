#ifndef UNIVERSITY_POINT_H
#define UNIVERSITY_POINT_H

template<typename T>
class Point {
public:
    Point();

    Point(int x, int y, T value);

    Point<T> multiply(T multiplier);

    Point transpose();

    int x;
    int y;
    T value;
};

template
class Point<int>;

Point<int> scan_point();

#endif //UNIVERSITY_POINT_H
