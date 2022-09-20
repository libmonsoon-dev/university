#include "../include/slice.h"

#define MIN_SLICE_CAP 10

template<typename T>
Slice<T>::Slice() {
    this->len = 0;
    this->cap = MIN_SLICE_CAP;
    this->data = new T[this->cap];
}

template<typename T>
void Slice<T>::Append(T val) {
    if (this->len == this->cap) {
        this->cap *= 2;
        auto oldData = this->data;
        this->data = new T[this->cap];

        for (int i = 0; i < this->len; i++) {
            this->data[i] = oldData[i];
        }

        delete[] oldData;
    }

    this->data[this->len] = val;
    this->len++;
}

template<typename T>
void Slice<T>::Remove(int index) {
    for (int i = index; i < this->len - 1; i++) {
        this->data[i] = this->data[i + 1];
    }

    this->len--;
}

template<typename T>
int Slice<T>::Length() {
    return this->len;
}

template<typename T>
T *Slice<T>::Array() {
    return this->data;
}
