#ifndef UNIVERSITY_SLICE_H
#define UNIVERSITY_SLICE_H

#include "point.h"

template<typename T>
class Slice {
public:
    Slice();

    void Append(T val);

    void Remove(int index);

    int Length();

    T *Array();

private:
    T *data;
    int len;
    int cap;
};

template
class Slice<Point<int>>;

#endif //UNIVERSITY_SLICE_H
