#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

// implementation of a a Heap(Min/Max)
typedef struct Heap Heap; 

struct Heap{
    int *arr;       // number of elements in the heap (array)
    int capacity;   // maximum number of elements the heap can hold
    int size;       // keep track of the size of the heap
};

int heap_parent(int i);

int heap_left(int i);

int heap_right(int i);

int heap_top(Heap *h);

Heap *heap_create(int capacity);

Heap *heap_insert(Heap *h, int index);

// call hepaify()
// reorder the heap to maintain the heap property
Heap *heapify(Heap *h, int index);

// call heapify()
// delete the top of the heap with the last element
Heap *heap_delete(Heap *h); 

// call heap_delete()
// delete a value at a specified index
Heap *heap_delete_index(Heap *h, int index);

// print the heap data
void heap_print(Heap *h);

// free the heap struct
void heap_free(Heap **h);


