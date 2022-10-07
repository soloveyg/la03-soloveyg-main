#include "list.h" // Include user header file
#include <stdio.h> // For printf
#include <stdlib.h> // For NULL

struct ll_node *ll_head(struct ll_node *node) {
    // TODO
    return node;
}

struct ll_node *ll_tail(struct ll_node *node) {
    // TODO
    if (node==NULL)
    {
        return NULL;
    }
    struct ll_node* temp= node;

    while (temp->next!= NULL)
    {
        temp = temp->next;
    }
    return temp;
}
int ll_size(struct ll_node *head) {
    if (head == NULL)
    {
        return NULL;
    }

    int result = 1;
    while ((head->next) != NULL)
    {
        head = head->next;
        result++;
    }
    return result;
}

struct ll_node *ll_find(struct ll_node *node, int value) {
    if (node == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < ll_size; i++)
    {
        if (node->data == value)
        {
            return node;
        }
        node = node->next;
    }
    
    //Otherwise return NULL
    return NULL;
}

