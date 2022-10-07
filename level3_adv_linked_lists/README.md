# Level 3

In this level, you will be writing some basic functions to practice the use of pointers. You may use malloc, free, and any functions you've written in level 2.

## Level 3 Part A

For this part, you will implement a function that creates a linked list and destroys it. To do so, there are three
functions you need to write:

    struct ll_node *ll_create(int data);
    void ll_append(struct ll_node *list, int data);
    void ll_destroy(struct ll_node *node);

The `ll_create` function will create a new linked list with a single node. The newly created node is returned.
The `ll_append` function will add to the tail a new node with the specified value.
This `ll_destroy` function will take in a list, and call `free` on each node of the list.

## Level 3 Part B

For this part, you will implement a function that destroys a single node. The function signature looks like
the following:

    struct ll_node *ll_delete(struct ll_node *head, int value);

This function will take in a list, and call `free` on a specific node that has the same value. It returns the new
head.

This is needed because if the value is found in the head, you need to change the head to point to a new one. This can
be done by the following sequence:

    head = ll_delete(head, x);

## Troubleshooting

For this level you might also see the following error message:

    =================================================================
    ==4160==ERROR: LeakSanitizer: detected memory leaks

    Indirect leak of 16 byte(s) in 1 object(s) allocated from:
        #0 0x7f7b96fddbc8 in malloc (/lib/x86_64-linux-gnu/libasan.so.5+0x10dbc8)
        #1 0x7f7b9794864b in ll_append level3_adv_linked_lists/list.c:28
        #2 0x7f7b9794838b in test_four level3_adv_linked_lists/test_list_delete.c:44
        #3 0x7f7b9794af94 in UnityDefaultTestRun (level3_adv_linked_lists/test_list_delete+0x3f94)
        #4 0x7f7b979484d3 in main level3_adv_linked_lists/test_list_delete.c:66
        #5 0x7f7b96cf70b2 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)

This means you forgot to call `free` on some object. The object was created using `malloc` at line 28 in
list.c, but was never freed.

To solve this problem, try adding `printf` functions in strategic locations (i.e. before line 28 of list.c) and see if
you see them in your program output.

You may also see the following error message:

    ==4833==ERROR: AddressSanitizer: attempting double-free on 0x602000000010 in thread T0:
        #0 0x7f65f86fd7cf in __interceptor_free (/lib/x86_64-linux-gnu/libasan.so.5+0x10d7cf)
        #1 0x7f65f907c94e in ll_delete level3_adv_linked_lists/list.c:43
        #2 0x7f65f907c229 in test_one level3_adv_linked_lists/test_list_delete.c:12
        #3 0x7f65f907f221 in UnityDefaultTestRun (level3_adv_linked_lists/test_list_delete+0x4221)
        #4 0x7f65f907c6e0 in main level3_adv_linked_lists/test_list_delete.c:122
        #5 0x7f65f84170b2 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
        #6 0x7f65f907c12d in _start (level3_adv_linked_lists/test_list_delete+0x112d)

This means you are calling free twice on the same object.
