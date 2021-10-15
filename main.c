/* CIUREA Robert-Mihai - 313CB */

#include "H.h"

int main (int argc, char *argv[]) {
    if (argc != 4) {
        printf ("Not enough arguments\n");
        return -1;
    }

    FILE *input = NULL;
    FILE *output = NULL;
    char *buffer = NULL, *key = NULL, *value = NULL;
    TH table = NULL;
    int M, flag = 0, index_bucket, find_or_not;

    input = fopen (argv[2], "rt");
    if (!input) return -1;

    output = fopen (argv[3], "wt");
    if (!output) {
        fclose (input);
        return -1;
    }

    M = atoi (argv[1]);
    printf ("Tabel M: %d\n", M);
    table = create_table (M, key_code);
    if (!table) {
        fclose (input);
        fclose (output);
        return -1;
    }

    for (int i = 0; i < table->M; i++)
        table->v[i] = NULL;

    buffer = (char *) calloc (MAX_BUFFER, sizeof (char));
    if (!buffer) {
        free (table->lenghts);
        free (table->v);
        free (table);
        fclose (input);
        fclose (output);
        return -1;
    }

    key = (char *) calloc (MAX_BUFFER, sizeof (char));
    if (!key) {
        free (buffer);
        free (table->lenghts);
        free (table->v);
        free (table);
        fclose (input);
        fclose (output);
        return -1;
    }

    value = (char *) calloc (MAX_BUFFER, sizeof (char));
    if (!value) {
        free (key);
        free (buffer);
        free (table->lenghts);
        free (table->v);
        free (table);
        fclose (input);
        fclose (output);
        return -1;
    }

    // Check string from input to identify command

    while (fscanf (input, "%s", buffer) != EOF) {
        if (strcmp (buffer, "put") == 0) {
            fscanf (input, "%s", key);
            fscanf (input, "%s", value);
            table = put (table, key, value);
            // print_bucket (table, 0, output);
        } else if (strcmp (buffer, "find") == 0) {
                fscanf (input, "%s", key);
                find_or_not = find (table, key);
                if (find_or_not) fprintf (output, "True\n");
                else fprintf (output, "False\n");
        } else if (strcmp (buffer, "print") == 0)
            print_TH (table, output);
        else if (strcmp (buffer, "remove") == 0) {
            fscanf (input, "%s", key);
            table = remove_node (table, key, &flag);
        } else if (strcmp (buffer, "print_bucket") == 0) {
            fscanf (input, "%d", &index_bucket);
            print_bucket (table, index_bucket, output);
        } else if (strcmp (buffer, "get") == 0) {
            fscanf (input, "%s", key);
            if (get (table, key) == NULL) fprintf (output, "NULL\n");
            else fprintf (output, "%s\n", get (table, key));
        }
    }

    // Free memory used

    free (value);
    free (key);
    free (buffer);
    delete_table (&table);
    fclose (input);
    fclose (output);

    return 0;
}