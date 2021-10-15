/* CIUREA Robert-Mihai - 313CB */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifndef list
#define list

// Define functions to be used generically

typedef int (*cmp) (const char*, const char *);

// Define a generic circular double-linked list

typedef struct DL{
    void *info;
    struct DL *pre;
    struct DL *next;
} node, *DL;

// Define operations with list

DL init_list  (void *x); // Init head of list
DL insert_node (DL s, void *info, int *length);

#endif