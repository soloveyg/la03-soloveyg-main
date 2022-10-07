# Level 2

In this level, you will be writing some functions that work with linked lists

## Level 2 Part A

For this part, you will implement the following functions. The first function is `ll_head`, and returns the head of a
list. The second function is `ll_tail`, and returns the tail of the list. The third function is `ll_size` and returns
the number of elements in the list.

The function definitions look like the following:

    struct ll_node *ll_head(struct ll_node *node);
    struct ll_node *ll_tail(struct ll_node *node);
    int             ll_count(struct ll_node *node);

As always, make sure `node` is chacked against a NULL pointer.

## Level 2 Part B

For this part, you will implement a function that takes two arguments: a list and a number. The function searches
through the list, and returns the node when the number is found. If not found, return NULL.

The function definition looks like the following:

    struct ll_node *ll_find(struct ll_node *node, int value);

