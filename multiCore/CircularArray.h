#ifndef CIRCULARARRAY_CIRCULARARRAY_H
#define CIRCULARARRAY_CIRCULARARRAY_H

#include <stdbool.h>

struct circularArray
{
    int front;
    int rear;
    int size;
    int *arr;
};

struct circularArray *newCircularArray(int size);

int size(struct circularArray *pt);

bool isEmpty(struct circularArray *pt);

int front(struct circularArray *pt);

int dequeue(struct circularArray *pt);

int enqueue(struct circularArray *pt, int object);

#endif // CIRCULARARRAY_CIRCULARARRAY_H
