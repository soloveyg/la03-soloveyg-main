#ifndef LIST_H
#define LIST_H

/**
 * TODO: Javadoc
 */
struct ll_node {
    int data;
    struct ll_node *next;
};

/**
 * TODO: Javadoc
 */
struct ll_node *ll_head(struct ll_node *node);
/**
 * TODO: Javadoc
 */
struct ll_node *ll_tail(struct ll_node *node);
/**
 * TODO: Javadoc
 */
int             ll_size(struct ll_node *node);
/**
 * TODO: Javadoc
 */
struct ll_node *ll_find(struct ll_node *node, int value);

#endif
