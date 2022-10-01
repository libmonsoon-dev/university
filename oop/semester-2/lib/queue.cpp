#include <ostream>
#include <iostream>

#include "../include/queue.h"

#define EMPTY_QUEUE_ERROR "Попытка чтения из пустой очереди"

Queue::Queue() {
    this->first = nullptr;
    this->last = nullptr;
}

Queue::Queue(Queue &other) {
    this->first = other.first;
    this->last = other.last;
}

Queue::Queue(Queue &&other) {
    this->first = other.first;
    this->last = other.last;
};

Queue Queue::operator<<(int value) {
    auto next = new QueueItem(this->last, value);

    if (this->last != nullptr) {
        this->last->next = next;
    }

    this->last = next;

    if (this->first == nullptr) {
        this->first = next;
    }

    return *this;
}

Queue Queue::operator>(int *output) {
    if (this->first == nullptr) {
        throw EMPTY_QUEUE_ERROR;
    }

    *output = this->first->value;
    return *this;
}

Queue Queue::operator>>(int *output) {
    if (this->first == nullptr) {
        throw EMPTY_QUEUE_ERROR;
    }

    auto *current = this->first;
    *output = current->value;
    this->first = current->next;
    delete current;

    return *this;
}

std::ostream &operator<<(std::ostream &out, Queue q) {
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

std::istream &operator>>(std::istream &in, Queue &q) {
    int val;
    in >> val;
    q << val;

    return in;
}

bool Queue::operator==(Queue other) {
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

bool Queue::operator!=(Queue other) {
    return !this->operator==(other);
}

QueueItem::QueueItem(QueueItem *prev, int value) {
    this->next = nullptr;
    this->prev = prev;
    this->value = value;
}
