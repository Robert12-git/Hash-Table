/* CIUREA Robert-Mihai - 313CB */

#include "list.h"

#define MAX_BUFFER 50

#ifndef H
#define H

// Define functions to be used with Hash Table

typedef int (*H_function) (void *, size_t);

// Structure of a table
typedef struct tabel {
    size_t M;
    H_function fun;
    DL *v;
    int *lenghts;
} table_form, *TH;


// Info of each node
typedef struct address{
    char *key;
    char *value;
} site_node;

// Important functions

TH create_table (int M, H_function create_key);

// Insert in table if possible
TH put (TH s, char *key, char *value);

// Eliminate node and know by flag
TH remove_node (TH s, char *key, int *flag);

// Function to determin key code
int key_code (void *string, size_t M);

// Return ip address
char *get (TH s, char *key);

// Find if DNS exits or not
int find (TH s, char *key);

// Print entire table, each bucket on a different line
void print_TH (TH s, FILE *output);

// Print specified bucket
void print_bucket (TH s, int index_bucket, FILE *output);

// Memory free
void delete_table (TH *s);

#endif