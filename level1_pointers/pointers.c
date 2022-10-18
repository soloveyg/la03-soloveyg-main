#include "pointers.h" // Include user header file
#include <ctype.h> // For toupper
#include <stdlib.h> // For NULL


void set_max(int a, int b, int *pm) {
    // TODO

    if(pm == NULL){
        return;
    }

    if (a > b)
    {
        *pm = a;
    } else if (b > a)
    {
        *pm = b;
    } else{
        *pm = a;
    }
    
}

int* range(int x) {
    // TODO
    int* array = malloc(sizeof(int) * x);
    for (int i = 0; i < x; i++)
    {
        array[i] = i+1;
    }
    
    return array;
}

char* capitalize(char* s, int slen) {
    // TODO: Use toupper to convert a char to an uppercase char
    // NOTE: See README.md for more troubleshooting information
    char* array = malloc(sizeof(int) * slen);
    if (slen <= 0 || s == NULL)
    {
        return array;
    }
    
    for (int i = 0; i < slen; i++)
    {
        array[i] =  toupper(s[i]);
        
    }
    return array;
}
