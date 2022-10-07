#include "list.h" // Include user header file
#include <stdio.h> // For printf
#include <stdlib.h> // For NULL

struct ll_node *ll_create(int data) {
    struct ll_node* head = NULL;
    head = malloc(sizeof(struct ll_node));
    head->data= data;
    head->next= NULL;
    return head;
}
void ll_destroy(struct ll_node *head) {
    // TODO
    if (head == NULL)
    {
        return;
    }
    
    struct ll_node* temp= head;
    
    struct ll_node* prev;

    while (temp->next!= NULL)
    {
        prev = temp;
        temp = temp->next;
        free(prev);
    }
    free(temp);

}

void ll_append(struct ll_node *list, int data) {
    // TODO
    if (list == NULL)
    {
        return;
    }
    
    struct ll_node* temp= list;

    while (temp->next!= NULL)
    {
        temp = temp->next;
    }
    temp->next = ll_create(data);
}

struct ll_node *ll_delete(struct ll_node *head, int value) {
    // TODO
    if (head == NULL)
    {
        return NULL;
    }
    
    struct ll_node* temp= head;
    struct ll_node* prev;

    if (temp->data == value)
    {
        prev = temp;
        temp = temp->next;
        free(prev);
        return head;
    }
    
    while (temp->data!= value && temp != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next; 
    free(temp);
    
    return head;
}
