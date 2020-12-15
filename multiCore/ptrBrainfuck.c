#include <stdlib.h>
#include <stdio.h>

#include "CircularArray.h"

int core1(struct circularArray **shared);
int core2(struct circularArray **shared);

int main()
{
    struct circularArray **shared = (struct circularArray **)malloc(sizeof(struct circularArray *));
    core1(shared);
    core2(shared);
    return EXIT_SUCCESS;
}

int core1(struct circularArray **shared)
{
    struct circularArray *queue = newCircularArray(10);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    printf("Size: %d\n", size(queue));
    *shared = queue;
    return EXIT_SUCCESS;
}

int core2(struct circularArray **shared)
{
    struct circularArray *queue = *shared;
    printf("Size: %d\n", size(queue));
    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));
    printf("Size: %d\n", size(queue));
    return EXIT_SUCCESS;
}