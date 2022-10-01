#ifndef UNIVERSITY_SLICE_H
#define UNIVERSITY_SLICE_H

#include "point.h"

class Slice {
public:
    Slice();

    void Append(Point val);

    void Remove(int index);

    int Length();

    Point *Array();

private:
    Point *data;
    int len;
    int cap;
};

#endif //UNIVERSITY_SLICE_H
