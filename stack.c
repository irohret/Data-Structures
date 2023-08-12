#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "stack.h" 

// Stack ADT

Stack *stack_create(int capacity){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    assert(s);
    s->arr = (int *)malloc(sizeof(int) * capacity);
    assert(s->arr);
    s->capacity = capacity;
    s->top = -1;
    return s;
}

bool stack_isEmpty(Stack *s){
    return s->top == -1;
}

bool stack_isFull(Stack *s){
    return s->capacity -1 == s->top;
}

Stack *stack_push(Stack *s, int data){
    if(stack_isFull(s)){
        fprintf(stderr, 
        "Error[push]: cannot insert.\n" 
        "Please allocate larger size for stack!!\n"
        "You allocated room for %d elements but are trying to insert %d elements.\n", s->capacity, data);
        exit(1);
    }
    
    s->top++;
    s->arr[s->top] = data;
    return s; 
}

Stack *stack_pop(Stack *s){
    if(stack_isEmpty(s)){
        fprintf(stderr, "Error[pop]: stack is Empty!!\n");
        exit(1);
    }

    s->top--;
    return s; 
}


void stack_print(Stack *s){
    for(int i = 0; i < s->top; i++){
        printf("%d -> ", s->arr[i]);
    }
    printf("NULL\n");
}
    

void stack_free(Stack **s){
    if(*s){
        free((*s)->arr);
        free(*s);
    }
    (*s) = NULL;
}

int main(int argc, char **argv){

    Stack *stack = stack_create(6);

    int arr[] = {2, 4, 6, 8, 10, 12};
    int SIZE = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i < SIZE; i++){
        stack_push(stack, arr[i]);
    }

    stack_print(stack);
    
    stack_pop(stack);

    stack_print(stack);
    
    stack_free(&stack);
    return 0; 
}
