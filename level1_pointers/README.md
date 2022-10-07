# Level 1

In this level, you will be writing some basic functions to practice the use of pointers.

## Level 1 Part A

For this part, you will implement a function that computes the maximum of two numbers, and stores the result in a
pointer.
The function definition looks like the following:

    void set_max(int a, int b, int *pm);

`pm` is a pointer to another integer variable. *NOTE*, `pm` may or may not point to a NULL pointer, so make sure you
guard against this possibilty!

To test this function, there is a set of unit tests provided in test_set_max.c.

## Level 1 Part B

For this part, you will implement a function that takes a number, `x`, and returns an array that's filled with numbers
1 through x, For example, given 4, you should get back `{1, 2, 3, 4}` (in that order). If `x` is invalid (say 0), return `NULL`.

The function definition looks like the following:

    int *range(int x);

Note that the function returns a pointer to an integer array, so you need to use dynamic memory (aka `malloc`) here.

## Level 1 Part C

For this part, you will implement a function that takes a string `s` (and its corresponding length slen) and returns
a new string that has all of its lower-case alphabet characters into uppercase, using the `toupper` function.

The function definition looks like the following:

    char* capitalize(char *s, int slen);

Note that the function returns a pointer to an character array, so you need to use dynamic memory (aka `malloc`) here.

Also, **make sure** you fully understand the difference between a character array, and a null-terminated string. What is the
length of an array `{'a', 'b', 'c'}`, vs. the length of a string ``abc``?

## Troubleshooting

This assignment we'll be enabling tools called "sanitizers". These are tools to help you track down any issues with
using dynamic memory. For example, we might see the following error message:

    =================================================================
    ==1355==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x602000000053 at pc 0x7f651d307a6d bp 0x7fffd4245b80 sp 0x7fffd4245328
    READ of size 4 at 0x602000000053 thread T0
        #0 0x7f651d307a6c  (/lib/x86_64-linux-gnu/libasan.so.5+0x67a6c)
        #1 0x7f651dd15b96 in test_abc level1_pointers/test_pointers.c:90
        #2 0x7f651dd188b4 in UnityDefaultTestRun (level1_pointers/test_pointers+0x58b4)
        #3 0x7f651dd15d8a in main level1_pointers/test_pointers.c:129
        #4 0x7f651d0c70b2 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
        #5 0x7f651dd152cd in _start (level1_pointers/test_pointers+0x22cd)

This means that you are "overflowing" your buffer. This is C's equivalent of an `IndexOutOfBoundsException` In `#1`
you see that the exception came from `test_pointers.c` line 90.
