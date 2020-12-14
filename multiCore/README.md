# Problem

Sharing a Queue between two CPU Cores, which only have 1 shared Address.

## Start

The Project contains a `Makefile` which provides basic functions.

- `make` to compile the project
- `make clean` to clean the project
- To start:
  1. first use `make`
  2. then `./prog` to run the program

## Structure

To simulate the situation, first we create a address, which both cores can use.

Each Core is simulated by a function, which only nows the shared address of the size of 8 bytes

```{c}
printf("%lu\n", sizeof(struct circularArray **)); // 8
```

This leads to the following two function definitions

```{c}
int core1(struct circularArray **shared);
int core2(struct circularArray **shared);
```

In `core1` we define the *queue* and fill it with some elements.
In `core2` we look at the size and dequeue the *queue* to look if everything works fine.

## Queue

The queue is a basic implementation of the FiFo principle. It is based on a circular Array data structure for faster access. The disadvantage is, that the *max-size* is fixed.
At the moment the queue only works on int, but that can be changed easily.

### Changing Data Type

First in the `CircularArray.h` the pointer of the array must be changed.

```{c}
struct circularArray {
    int front;
    int rear;
    int size;
    {dataType} *arr; // <- here
};
```

Then in the `CircularArray.c` are 3 changes needed:

- Array Allocation

```{c}
struct circularArray *newCircularArray(int size){
    struct circularArray *pt = (struct circularArray *)malloc(sizeof(struct circularArray));
    pt->front = 0;
    pt->rear = 0;
    pt->size = size;
    pt->arr = ({dataType} *)malloc(sizeof({dataType} [size]));  <- here
    return pt;
}
```

- front-func
  
```{c}
{dataType} front(struct circularArray *pt){    <- here
    return pt->arr[pt->front];
}
```

- enqueue element

```{c}
int enqueue(struct circularArray *pt, {dataType} object){  <- here
    if(size(pt) == pt->size-1){
        return -1;
    }
    pt->arr[pt->rear] = object;
    pt->rear = (pt->rear +1)%pt->size;
    return 1;
}

```

- dequeue return
  
```{c}
{dataType} dequeue(struct circularArray *pt){ <- here
    if(isEmpty(pt)){
        return {error sign of dataType};
    } else {
        int t = pt->arr[pt->front];
        pt->front = (pt->front + 1) % pt->size;
        return t;
    }
}
```

You need to define a Element which indicates that the queue was empty. Before we used the -1 but when you change the data type, you have to define your on Indicator.
