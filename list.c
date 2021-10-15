/* CIUREA Robert-Mihai - 313CB */

#include "list.h"

// Initialize node and place info in node

DL init_list  (void *x) {
    DL s = NULL;

    s = (DL) malloc (sizeof (node));
    if (!s) return NULL;
    s->pre = s->next = s;
    s->info = x;

    return s;
}

// If head already exists, introduce another node in list

DL insert_node (DL s, void *info, int *length) {
    DL aux = s, new = NULL;
    int x = *length;

    while (x != 1) {
        aux = aux->next;
        x--;
    }
    new = init_list (info);
    new->pre = aux;
    new->next = s;
    aux->next = new;
    s->pre = new;
    (*length)++;

    return s;
}