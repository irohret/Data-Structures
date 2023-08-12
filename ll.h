#pragma once

typedef struct Node Node;

struct Node{
    int data;
    Node *next;
};

Node *ll_create(int data);

Node *ll_insert(Node *n, int data);

Node *ll_remove(Node *n, int target);

bool ll_search(Node *n, int target);

Node *ll_reverse(Node *n);

uint64_t ll_length(Node *n);

bool ll_cycle(Node *n);

void ll_free(Node **n);

void ll_print(Node *n);


