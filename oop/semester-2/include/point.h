#ifndef UNIVERSITY_POINT_H
#define UNIVERSITY_POINT_H


class Point {
public:
    Point();

    Point(int x, int y, int value);

    Point multiply(int multiplier);

    Point transpose();

    int x;
    int y;
    int value;
};

Point scan_point();

#endif //UNIVERSITY_POINT_H
