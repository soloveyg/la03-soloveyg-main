#ifndef LIST_H
#define LIST_H

// Same as level 2
struct ll_node {
    int data;
    struct ll_node *next;
};
struct ll_node *ll_head(struct ll_node *node);
struct ll_node *ll_tail(struct ll_node *node);
int             ll_size(struct ll_node *node);
struct ll_node *ll_find(struct ll_node *node, int value);


/**
 * TODO: Javadoc
 */
struct ll_node *ll_create(int data);
/**
 * TODO: Javadoc
 */
void            ll_append(struct ll_node *list, int data);
/**
 * TODO: Javadoc
 */
void            ll_destroy(struct ll_node *node);
/**
 * TODO: Javadoc
 */
struct ll_node *ll_delete(struct ll_node *head, int value);

#endif
