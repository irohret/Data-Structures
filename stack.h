
#pragma once

typedef struct Stack Stack;

// implementation of a stack ADT

struct Stack{
    int *arr;       // number of elements in the stack (array)
    int capacity;   // maximum number of elements the stack can hold
    int top;        // keep track of the top of the stack 
};

Stack *stack_create(int capacity);

bool stack_isEmpty(Stack *s);

bool stack_isFull(Stack *s);

Stack *stack_push(Stack *s, int data);

Stack *stack_pop(Stack *s);

void stack_print(Stack *s);

void stack_free(Stack **s);


