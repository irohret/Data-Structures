#pragma once

typedef struct Queue Queue;

struct Queue{
    int *arr;         // number of elements in the queue (array)
    int front;        // keep track of the front of the queue
    int rear;         // keep track of the rear of the queue
    int capacity;     // maximum number of elements the queue can hold
};

Queue *queue_create(int capacity);

bool queue_isEmpty(Queue *q);

bool queue_isFull(Queue *q);

Queue *queue_endqueue(Queue *q, int data);

Queue *queue_dequeue(Queue *q);

void queue_print(Queue *q);

void queue_free(Queue **q);


