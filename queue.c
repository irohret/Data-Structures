#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <assert.h>

#include "queue.h"

Queue *queue_create(int capacity){
    Queue *q = (Queue *) malloc(sizeof(Queue));
    assert(q);
    q->arr = (int *) malloc(sizeof(int) * capacity);
    assert(q->arr);
    q->front = -1;
    q->rear = -1;
    q->capacity = capacity;
    return q;
}

// dequeue
bool queue_isEmpty(Queue *q){
    return q->front == -1;
}

// enqueue
bool queue_isFull(Queue *q){
    return q->rear == q->capacity -1;
}

Queue *queue_enqueue(Queue *q, int data){
    if(queue_isFull(q)){
        fprintf(stderr, "Error[enqueue]: cannot insert into the queue.\n");
        exit(1);
    }

    if(q->front == -1){
        q->front = 0;
    }

    q->rear++;
    q->arr[q->rear] = data;
    return q;
}

// this method is time efficient but not space efficient
Queue *queue_dequeue(Queue *q){
    if(queue_isEmpty(q)){
        fprintf(stderr, 
        "Error[dequeue]: queue is already empty.\n"
        "cannot remove from the queue.\n");
        exit(1);
    }

    // printf("dequeue: %d\n", q->arr[q->front]);
    
    if(q->front == q->rear){
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
        // q->front = (q->front + 1) % q->capacity;
    }
      
    return q;
}

int queue_peek(Queue *q){
    return q->arr[q->front];
}

uint64_t queue_size(Queue *q){
    if (q->front == -1) {
        return 0;
    }
    // return (q->rear - q->front + q->capacity) % q->capacity + 1;
    return q->rear - q->front +1;
}

void queue_print(Queue *q){
    // int front = q->front;
    if(q->front == -1){
        q->front = 0;
    }
    
    for(int i = q->front; i < q->rear+1; i++){
        printf("%d -> ", q->arr[i]);
    }
    printf("NULL\n");
}

void queue_free(Queue **q){
    if(*q){
        free((*q)->arr);
        free(*q);
    }
    (*q) = NULL;
}

int main(int argc, char **argv){
    
    int arr[] = {2, 4, 6, 10, 12, 14, 16, 18, 20};
    int SIZE = sizeof(arr) / sizeof(arr[0]);

    Queue *queue = queue_create(SIZE);

    for(int i = 0; i < SIZE; i++){
        queue = queue_enqueue(queue, arr[i]);
    }

    printf("size of the queue: %lu\n", queue_size(queue));
    queue_print(queue);
    
    
    queue_dequeue(queue);
    queue_dequeue(queue);
    queue_dequeue(queue);

    printf("size of the queue: %lu\n", queue_size(queue));
    queue_print(queue);

    queue_free(&queue);

    return 0;
}
