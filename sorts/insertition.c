#include <stdio.h>
#include <stdlib.h>

#include "insertition.h"

void insertition(int arr[], int size){
    for(int i = 1; i < size; i++){
        int temp = arr[i];
        int j = i;
        while(j > 0 && temp < arr[j -1]){
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = temp;
    }
}

int main(int argc, char **argv){
    int arr[] = {2, 9, 4, 8, 1, 6, 0, 7, 3, 5};
    int SIZE = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    insertition(arr, SIZE);
    
    for(int i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
