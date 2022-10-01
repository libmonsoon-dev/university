#include "../include/slice.h"

#define MIN_SLICE_CAP 10

Slice::Slice() {
    this->len = 0;
    this->cap = MIN_SLICE_CAP;
    this->data = new Point[this->cap];
}

void Slice::Append(Point val) {
    if (this->len == this->cap) {
        this->cap *= 2;
        auto oldData = this->data;
        this->data = new Point[this->cap];

        for (int i = 0; i < this->len; i++) {
            this->data[i] = oldData[i];
        }

        delete[] oldData;
    }

    this->data[this->len] = val;
    this->len++;
}

void Slice::Remove(int index) {
    for (int i = index; i < this->len - 1; i++) {
        this->data[i] = this->data[i + 1];
    }

    this->len--;
}

int Slice::Length() {
    return this->len;
}

Point *Slice::Array() {
    return this->data;
}
