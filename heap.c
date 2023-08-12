
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "heap.h"

// implementation of a Heap(Min/Max) -> this is a Max Heap 

void swap(int *val_1, int *val_2){
    int temp = *val_1;
    *val_1 = *val_2;
    *val_2 = temp;
}

int heap_parent(int i){
    return (i - 1) / 2;
}

int heap_left(int i){
    return (2 * i) + 1;
}

int heap_right(int i){
    return (2 * i) + 2; 
}

int heap_top(Heap *h) {
    return h->arr[0];
}

Heap *heap_create(int capacity){
    Heap *h = (Heap *) malloc(sizeof(Heap));
    assert(h);
    h->arr = (int *)malloc(sizeof(int) * capacity);
    assert(h->arr);
    h->capacity = capacity;
    h->size = 0; 
    return h; 
}

// flip < for min 
Heap *heap_insert(Heap *h, int index){
    h->size++;
  
    h->arr[h->size -1] = index;
  
    int current = h->size -1;
    
    while(current > 0 && h->arr[heap_parent(current)] < h->arr[current]){
        swap(&h->arr[heap_parent(current)], &h->arr[current]);
        current = heap_parent(current);
    }
   
    return h; 
}

// call heapify()
// flip < for min
Heap *heapify(Heap *h, int index){
  
    int left = heap_left(index);
    int right = heap_right(index);
    
    int value = index; 
    
    if(left < h->size && h->arr[left] > h->arr[value]){
        value = left;
    }
    
    if(right < h->size && h->arr[right] > h->arr[index]){
        value = right;
    }
    
    if(value != index){
        swap(&h->arr[value], &h->arr[index]);
        h = heapify(h, index);
    }
    
    return h; 
}

// call heapify()
Heap * heap_delete(Heap *h){
    
    int size = h->size;
    int last_element = h->arr[size -1];
  
    // swap 
    h->arr[0] = last_element;
  
    h->size--;
    size--;

    h = heapify(h, 0);
  
    return h; 
}

// call heap_delete()
// flip < for min
Heap *heap_delete_index(Heap *h, int index){
    
    h->arr[index] = heap_top(h);
      
    int current = index;
    
    while(current > 0 && h->arr[heap_parent(current)] < h->arr[current]){
        swap(&h->arr[heap_parent(current)], &h->arr[current]);
        current = heap_parent(current);
    }
 
    h = heap_delete(h);
    return h;
}

void heap_print(Heap *h){
    for(int i = 0; i < h->size; i++){
        printf("%d -> ", h->arr[i]);
    }
    printf("NULL\n");
}

void heap_free(Heap **h){
    if(*h){
        free((*h)->arr);
        free(*h);
    }
    (*h) = NULL;
}


int main (int argc, char **agcv){

    Heap *heap = heap_create(10);
     
    int arr[] = {5, 10, 15, 20, 25, 30}; 
    int SIZE = sizeof(arr) / sizeof(arr[0]);
    
    for(int i = 0; i < SIZE; i++){
        heap_insert(heap, arr[i]);
    }

    heap_print(heap);
    heap_delete(heap);

    // heap_delete_index(heap, 0);

    heap_print(heap);
    
    heap_free(&heap);
    
    return 0;    
}
