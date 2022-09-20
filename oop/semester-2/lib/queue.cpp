#include <ostream>
#include <iostream>

#include "../include/queue.h"

#define EMPTY_QUEUE_ERROR "Попытка чтения из пустой очереди"

template<typename T>
Queue<T>::Queue() {
    this->first = nullptr;
    this->last = nullptr;
}

template<typename T>
Queue<T> Queue<T>::operator<<(T value) {
    auto next = new QueueItem<T>(this->last, value);

    if (this->last != nullptr) {
        this->last->next = next;
    }

    this->last = next;

    if (this->first == nullptr) {
        this->first = next;
    }

    return *this;
}

template<typename T>
Queue<T> Queue<T>::operator>(T *output) {
    if (this->first == nullptr) {
        throw EMPTY_QUEUE_ERROR;
    }

    *output = this->first->value;
    return *this;
}

template<typename T>
Queue<T> Queue<T>::operator>>(T *output) {
    if (this->first == nullptr) {
        throw EMPTY_QUEUE_ERROR;
    }

    auto *current = this->first;
    *output = current->value;
    this->first = current->next;
    delete current;

    return *this;
}

std::ostream &operator<<(std::ostream &out, Queue<int> q) {
    out << "Queue(";
    for (auto item = q.first; item != nullptr; item = item->next) {
        out << item->value;
        if (item->next != nullptr) {
            out << ", ";
        }
    }
    out << ")";

    out << std::endl;
    return out;
};

std::istream &operator>>(std::istream &in, Queue<int> &q) {
    int val;
    in >> val;
    q << val;

    return in;
}

template<typename T>
bool Queue<T>::operator==(Queue<T> other) {
    auto a = this->first;
    auto b = other.first;

    while (true) {
        if (a == nullptr && b == nullptr) {
            return true;
        }

        if (a == nullptr || b == nullptr) {
            return false;
        }

        if (a->value != b->value) {
            return false;
        }

        a = a->next;
        b = b->next;
    }
}

template<typename T>
bool Queue<T>::operator!=(Queue<T> other) {
    return !this->operator==(other);
};

template<typename T>
QueueItem<T>::QueueItem(QueueItem *prev, T value) {
    this->next = nullptr;
    this->prev = prev;
    this->value = value;
}
