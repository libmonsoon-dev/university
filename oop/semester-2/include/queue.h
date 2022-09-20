#ifndef UNIVERSITY_QUEUE_H
#define UNIVERSITY_QUEUE_H

template<typename T>
class QueueItem {
public:
    QueueItem *next;
    QueueItem *prev;
    T value;

    QueueItem<T>(QueueItem *prev, T value);
};


template<typename T>
class Queue {
public:
    Queue();

    Queue operator<<(T item);

    Queue operator>>(T *output);

    Queue operator>(T *output);

    bool operator==(Queue<T> other);

    bool operator!=(Queue<T> other);

    friend std::ostream &operator<<(std::ostream &out, Queue<int> q);

    friend std::istream &operator>>(std::istream &out, Queue<int> &q);

private:
    QueueItem<T> *first;
    QueueItem<T> *last;
};

template
class Queue<int>;

#endif //UNIVERSITY_QUEUE_H
