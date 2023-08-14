#pragma once

// implementaion of a double linked list

typedef struct Node Node;

struct Node{
    int data; 
    Node *next;
    Node *prev;
};

Node *ll_create(int data);

Node *ll_insert_front(Node *n, int data);

Node *ll_insert_middle(Node *n, int data);

Node *ll_insert_rear(Node *n, int data);

Node *ll_remove(Node *n, int target);

void ll_print_forwards(Node *n);

void ll_print_backwards(Node *n);

void ll_free(Node *n);

