
#include <stdio.h>
#include <stdlib.h>

#include "bubble.h"

void swap(int *value1, int *value2){
    int temp = *value1;
    *value1 = *value2;
    *value2 = temp;
}

void bubble(int arr[], int size){
    for(int i = 0; i < size-1; i++){
        for(int j = 0; j < size -1; j++){
            if(arr[j+1] < arr[j]){
                swap(&arr[j+1], &arr[j]);
             }
        }
    }
}

int main(int argc, char **argv){

    int arr[] = {2, 9, 4, 8, 1, 6, 0, 7, 3, 5};
    int SIZE = sizeof(arr) / sizeof(arr[0]);
    
    for (int i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");     
    
    bubble(arr, SIZE);
    
    for (int i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }
    printf("\n"); 
   
    return 0;
}
