#include <stdio.h>
#include <stdlib.h>

#include "quick.h"

void swap(int *value1, int *value2){
    int temp = *value1;
    *value1 = *value2;
    *value2 = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low -1;
    
    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void quick(int arr[], int low, int high){ 
    if(low < high){
        int pivot = partition(arr, low, high);
        quick(arr, low, pivot -1);
        quick(arr, pivot +1, high);
    }
}

int main(int argc, char **argv){
    int arr[] = {2, 9, 4, 8, 1, 6, 0, 7, 3, 5};
    int SIZE = sizeof(arr) / sizeof(arr[0]);
    
    for (int i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");     
    
    quick(arr, 0, SIZE-1);
    
    for (int i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }
    printf("\n"); 
    return 0;
}
