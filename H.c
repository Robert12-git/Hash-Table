/* CIUREA Robert-Mihai - 313CB */

#include "H.h"

// Get Hash code to identify where to put info in Hash Table

int key_code (void *string, size_t M) {
    int ascii = 0;
    char *s = (char *) calloc (strlen ((char *)string) + 1, sizeof (char));

    strcpy (s, string);
    for (int i = 0; i < strlen (string); i++)
        ascii += s[i];

    free (s);
    
    return ascii % M;
}

TH create_table (int M, H_function create_key) {
    TH table = NULL;

    table = (TH) calloc (1, sizeof (table_form));
    if (!table) {
        printf ("No table done\n");
        return NULL;
    }
    table->fun = create_key;
    table->M = M;
    table->v = (DL *) calloc (M, sizeof (DL));
    if (!table->v) {
        free (table);
        return NULL;
    }

    table->lenghts = (int *) calloc (table->M, sizeof (int));
    if (!table->lenghts) {
        free (table->v);
        free (table);
        return NULL;
    }    

    return table;
}

// Function for command put

TH put (TH s, char *key, char *value) {
    int key_info = s->fun (key, s->M), flag = 1;
    site_node *info = NULL, *key_copy;
    DL copy;

    info = (site_node *) calloc (1, sizeof (site_node));
    if (!info) return s;

    info->key = (char*) calloc (strlen (key) + 1, sizeof (char));
    if (!info->key) {
        printf ("Abort\n");
        return s;
    }
    info->value = (char *) calloc (strlen (value) + 1, sizeof (char));
    if (!info->value) {
        printf ("No IP address\n");
        free (info->key);
        return s;
    }

    strcpy (info->key, key);
    strcpy (info->value, value);

    for (int i = 0; i < s->M; i++) {
        copy = s->v[i];
        if (i == key_info) {
            if (s->v[i] == NULL) {
                s->lenghts[i]++;
                s->v[i] = init_list (info);
            }
            else {
                for (int j = 0; j < s->lenghts[i]; j++) {
                    key_copy = (site_node *) (copy->info);
                    if (strcmp (key_copy->key, key) == 0) {
                        flag = 0;
                        free (info->value);
                        free (info->key);
                        free (info);
                        break;
                    }
                    copy = copy->next;
                }
                if (flag == 1) {
                    s->v[i] = insert_node (s->v[i], info, &(s->lenghts[i]));
                    break;
                }
            }
        }
    }

    return s;
}

// Function for command get

char *get (TH s, char *key) {
    site_node *copy;

    for (int i = 0; i < s->M; i++)
        if (i == s->fun (key, s->M))
            for (int j = 0; j < s->lenghts[i]; j++) {
                copy = (site_node *) (s->v[i]->info);
                if (strcmp (copy->key, key) == 0)
                    return (void *)copy->value;
                s->v[i] = s->v[i]->next;
            }

    return NULL;
}

// Function for command remove

TH remove_node (TH s, char *key, int *flag) {
    site_node *copy;
    DL aux, pre, next;

    for (int i = 0; i < s->M; i++) {
        if (i == s->fun (key, s->M))
            for (int j = 0; j < s->lenghts[i]; j++) {
                copy = (site_node *) (s->v[i]->info);
                if (strcmp (copy->key, key) == 0) {
                    free (copy->value);
                    free (copy->key);
                    free (copy);
                    aux = s->v[i];
                    pre = s->v[i]->pre;
                    next = s->v[i]->next;
                    s->v[i] = s->v[i]->next;
                    pre->next = next;
                    next->pre = pre;
                    s->lenghts[i]--;
                    free (aux);
                    *flag = 1;
                    break;
                } else s->v[i] = s->v[i]->next;
            }
    }

    return s;
}

// Function for command find

int find (TH s, char *key) {
    site_node *copy;

    for (int i = 0; i < s->M; i++) {
        if (i == s->fun (key, s->M)) {
            for (int j = 0; j < s->lenghts[i]; j++) {
                copy = (site_node *) (s->v[i]->info);
                if (strcmp (copy->key, key) == 0)
                    return 1;
                else s->v[i] = s->v[i]->next;
            }
        }
    }

    return 0;
}

// Sort all lists alphbetically

TH sort_list (TH s) {
    DL dlist1, dlist2;
    site_node *data1, *data2;
    void *aux;

    for (int i = 0; i < s->M; i++) {
        if (s->lenghts[i]) {
            dlist1 = s->v[i];
            for (int q = 0; q < s->lenghts[i] - 1; q++) {
                data1 = (site_node *)dlist1->info;
                dlist2 = dlist1->next;
                for (int k = q + 1; k < s->lenghts[i]; k++) {
                    data2 = (site_node *) dlist2->info;
                    if (strcmp (data1->key, data2->key) > 0) {
                        aux = dlist1->info;
                        dlist1->info = dlist2->info;
                        dlist2->info = aux;
                        data1 = (site_node *) dlist1->info;
                        data2 = (site_node *) dlist2->info;
                    }
                    dlist2 = dlist2->next;
                }
                dlist1 = dlist1->next;
            }
        }
    }

    return s;
}

// Function print

void print_TH (TH s, FILE *output) {
    site_node *copy;
    DL list_val;

    s = sort_list (s);
    for (int i = 0; i < s->M; i++)
        if (s->lenghts[i]) {
            list_val = s->v[i];
            fprintf (output, "%d: ", i);
            for (int j = 0; j < s->lenghts[i]; j++) {
                copy = (site_node *)list_val->info;
                fprintf (output, "%s ", copy->value);
                list_val = list_val->next;
            }
            fprintf (output, "\n");
        }
}

// Function print_bucket

void print_bucket (TH s, int index_bucket, FILE *output) {
    site_node *copy;
    DL list_val;
    
    s = sort_list (s);
    for (int i = 0; i < s->M; i++) {
        if (index_bucket == i) {
            if (s->lenghts[i]) {
                list_val = s->v[i];
                for (int j = 0; j < s->lenghts[i]; j++) {
                    copy = (site_node *)list_val->info;
                    fprintf (output, "%s ", copy->value);
                    list_val = list_val->next;
                }
                fprintf (output, "\n");
            } else fprintf (output, "VIDA\n");
        }
    }
}

// Free all memory used by hash table

void delete_table (TH *s) {
    site_node *aux;
    DL next;

    for (int i = 0; i < (*s)->M; i++)
        if ((*s)->v[i])
            for (int j = 0; j < (*s)->lenghts[i]; j++) {
                aux = (site_node *) ((*s)->v[i]->info);
                next = (*s)->v[i];
                (*s)->v[i] = (*s)->v[i]->next;
                free (aux->value);
                free (aux->key);
                free (aux);
                free (next);
            }

    free ((*s)->lenghts);
    free ((*s)->v);
    free (*s);
}