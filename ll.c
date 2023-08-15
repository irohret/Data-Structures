#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <inttypes.h>

#include "ll.h" 

Node *ll_create(int data){
    Node *n = (Node *)malloc(sizeof(Node));
    assert(n);
    n->data = data;
    n->next = NULL;
    return n;
}

Node *ll_insert(Node *n, int data){
    if(n == NULL){
        n = ll_create(data);
        return n;
    }
    
    Node *current = n;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = ll_create(data);
    return n;
}

// TODO: find a way to remove the first node from the list
// without segfault or freeing more than what is allocated


/*
Node *ll_remove(Node *n, int target){
    Node *current = n;
    Node *prev = NULL;

    if (n->data == target) {

        Node *temp = n;
        n = n->next;
        printf("next node in the list: %d\n", n->data);
        //free(temp);
        return temp;
    }
    
    while(current != NULL){
        if(current->data == target){
            prev->next = current->next;
            
            Node *temp = current;
            current = current->next;
            free(temp);
        }
        prev = current;
        current = current->next;
   }
   
   return n = prev;
}*/

Node *ll_remove(Node *n, int target){
    Node *current = n;
    Node *prev = NULL;
    
    while(current != NULL){
        if(current->data == target){
            if(prev == NULL){
                n = current->next;
            } else {
                prev->next = current->next;
            } 
            
            Node *temp = current;
            current = current->next;
            free(temp);

           } else{
                prev = current;
                current = current->next;
           }
    }

    return n;
}

bool ll_search(Node *n, int target){
    Node *current = n;
    while(current != NULL){
        if(current->data == target){
            return true;
        }
        current = current->next;
    }
    return false;
}

Node *ll_reverse(Node *n){
    Node *current = n;
    Node *prev = NULL;
    Node *temp = NULL;

    while(current != NULL){
        temp = current->next;
        current->next = prev;

        prev = current;
        current = temp;
    }
    return n = prev;
}

uint64_t ll_length(Node *n){
    Node *current = n;
    uint64_t count = 0;
    while(current != NULL){
        count++;
        current = current->next;
    }
    return count;
}

bool ll_cycle(Node *n){
    Node *fast = n;
    Node *slow = n;
    while(fast && slow && fast->next){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return true;
        }
    }
    return false;
}

void ll_free(Node **n){
    Node *current = *n;
    while(current != NULL){
        Node *temp = current;
        current = current->next;
        free(temp);
    }
}

void ll_print(Node *n){
    Node *current = n;
    while(current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main(int argc, char **argv){

    int arr[] = {2, 4, 6, 8, 10, 12}; 
    int SIZE = sizeof(arr) / sizeof(arr[0]);
    
    Node *head = NULL;
    for(int i = 0; i < SIZE; i++){
        if(head == NULL){
            head = ll_insert(head, arr[i]);
        } else {
            Node *current = head;
            while(current->next != NULL){
                current = current->next;
            }
            current = ll_insert(current, arr[i]);
        }
    }

    ll_print(head);
    
    // head = ll_reverse(head);

    ll_remove(head, 2);

    // printf("length: %lu\n", ll_length(head));

    printf("search: %d\n", ll_search(head, 6));
    
    ll_print(head);

    ll_free(&head);
    
    return 0;
}
