#include <stdio.h>

#include "selection.h"

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection(int arr[], int size){
   for(int i = 0; i < size; i++){
        int min_value = i; 
        for(int j = i +1; j < size; j++){
            if(arr[j] < arr[min_value]){
                min_value = j;
             }
        }
        swap(&arr[i], &arr[min_value]);
    }        
}

int main(int argc, char **argv){
    
    int arr[] = {2, 9, 4, 8, 1, 6, 0, 7, 3, 5};
    int SIZE = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }
    printf("\n"); 

    selection(arr, SIZE);

    for(int i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }
    printf("\n"); 

    return 0;
}
