#ifndef UNIVERSITY_QUEUE_H
#define UNIVERSITY_QUEUE_H

class QueueItem {
public:
    QueueItem *next;
    QueueItem *prev;
    int value;

    QueueItem(QueueItem *prev, int value);
};

class Queue {
public:
    Queue();

    Queue(Queue &other);

    Queue(Queue &&other);

    Queue operator<<(int item);

    Queue operator>>(int *output);

    Queue operator>(int *output);

    bool operator==(Queue other);

    bool operator!=(Queue other);

    friend std::ostream &operator<<(std::ostream &out, Queue q);

    friend std::istream &operator>>(std::istream &out, Queue &q);

private:
    QueueItem *first;
    QueueItem *last;
};

#endif //UNIVERSITY_QUEUE_H
