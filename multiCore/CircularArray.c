//
// Created by Hendrik Munske on 20.04.20.
//

#include "CircularArray.h"
#include <stdlib.h>


struct circularArray *newCircularArray(int size){
    struct circularArray *pt = (struct circularArray *)malloc(sizeof(struct circularArray));
    pt->front = 0;
    pt->rear = 0;
    pt->size = size;
    pt->arr = (int *)malloc(sizeof(int [size]));
    return pt;
}

int size(struct circularArray *pt){
    return (pt->size - pt->front + pt->rear)%pt->size;
}

bool isEmpty(struct circularArray *pt){
    return pt->rear == pt->front;
}

int front(struct circularArray *pt){
    return pt->arr[pt->front];
}

int dequeue(struct circularArray *pt){
    if(isEmpty(pt)){
        return -1;
    } else {
        int t = pt->arr[pt->front];
        pt->front = (pt->front + 1) % pt->size;
        return t;
    }
}

int enqueue(struct circularArray *pt, int object){
    if(size(pt) == pt->size-1){
        return -1;
    }
    pt->arr[pt->rear] = object;
    pt->rear = (pt->rear +1)%pt->size;
    return 1;
}
