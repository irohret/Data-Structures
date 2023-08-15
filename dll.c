#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#include "dll.h"

Node *ll_create(int data){
    Node *n = (Node *)malloc(sizeof(Node));
    assert(n);     
    n->data = data;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

Node *ll_insert_front(Node *n, int data){
    Node *new_node = ll_create(data);
    
    /**** this method also works ****
    if(n != NULL){
        n->prev = new_node;
     }

     new_node->next = n;
     return new_node;
    *********************************/
    
    
    if(n == NULL){
        n = new_node;
    } else {
    
        new_node->next = n;
        n->prev = new_node;
        n = new_node;
    }
    return new_node;
}

Node *ll_insert_middle(Node *n, int data, int index){
    Node *new_node = ll_create(data);     
    if(n == NULL){ return n; }

    Node *current = n;
    int count = 0;
    while(current->next != NULL && count > index -1){
        current = current->next;
        count++;
    }
    
    new_node->next = current->next;
    current->next = new_node;
  
    return new_node;
}

Node *ll_insert_rear(Node *n, int data){
    Node *new_node = ll_create(data);

    if(n == NULL){
        return new_node;
    }

    Node *current = n;
    while(current->next != NULL){
        current = current->next;
    }
    
    current->next = new_node;
    new_node->prev = current;

    return new_node;
}

// TODO: find a way to remove the first node from the list
// without segfault or freeing more than what is allocated 
Node *ll_remove(Node *n, int target){
    Node *current = n;
    Node *prev = NULL;

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

void ll_print_forwards(Node *n){
    Node *current = n;
    while(current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void ll_print_backwards(Node *n){
    if(n == NULL){ return; }
    
    Node *current = n;
    
    while(current->next != NULL){
         current = current->next;
    }
  
    while(current != NULL){
        printf("%d -> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

void ll_free(Node *n){
    Node *current = n;
    while(current != NULL){
        Node *temp = current;
        current = current->next;
        free(temp);
    }
}


int main(int argc, char **argv){
    int arr[] = {1, 3, 7, 9, 12};
    int SIZE = sizeof(arr) / sizeof(arr[0]);

    Node *head = NULL;

    for(int i = 0; i < SIZE; i++){
        if(head == NULL){
            head = ll_insert_front(head, arr[i]);
        } else {
            Node *current = head;
            while(current->next != NULL){
                current = current->next;
            }
            current = ll_insert_rear(current, arr[i]);
        }
    }

    ll_print_forwards(head);
    
    // ll_print_backwards(head);
    
    ll_insert_middle(head, 5, 2);
    
    ll_print_forwards(head);
   
    ll_remove(head, 5);

    ll_print_forwards(head);

    ll_free(head);
 
    return 0;
}
