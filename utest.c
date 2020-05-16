#include <stdio.h>
#include "hashtable.h"
#include <stdlib.h>
#include <string.h>

int main() {
        ST_ERR err;
        struct listnode *node;
        hashtab_init(hashtab);

        hashtab_add(hashtab, "Slon", 190,&err);
        hashtab_add(hashtab, "Volk", 60, &err);
        if (err == STERR_NOADD)
                fprintf(stdout, "Test_1\t->\tFAILED\n");
        else
                fprintf(stdout, "Test_1\t->\tPASSED\n");
        printf("\n");

        node = hashtab_lookup(hashtab, "Slon",&err);
        if (err == STERR_NOELEM)
                fprintf(stdout, "Test_2\t->\tFAILED\n");
        else
                fprintf(stdout, "Test_2\t->\tPASSED\n");
        printf("\n");

        node = hashtab_lookup(hashtab, "Crocodile",&err);
        if (err == STERR_NOELEM)
                fprintf(stdout, "Test_3\t->\tFAILED\n");
        else
                fprintf(stdout, "Test_3\t->\tPASSED\n");
        printf("\n");

        hashtab_delete(hashtab, "Slon", &err);
        if (err == STERR_DELETED)
                fprintf(stdout, "Test_4\t->\tFAILED\n");
        else
                fprintf(stdout, "Test_4\t->\tPASSED\n");
        printf("\n");

        node = hashtab_lookup(hashtab, "Slon",&err);
        if (err == STERR_NOELEM)
                fprintf(stdout, "Test_5\t->\tFAILED\n");
        else
                fprintf(stdout, "Test_5\t->\tPASSED\n");
        printf("\n");

        hashtab_delete(hashtab, "Crocodile", &err);
        if (err == STERR_DELETED)
                fprintf(stdout, "Test_6\t->\tFAILED\n");
        else
                fprintf(stdout, "Test_6\t->\tPASSED\n");
        printf("\n");

        delete_all(hashtab, &err);
        if (err == STERR_DELETEDALL)
                fprintf(stdout, "Test_7\t->\tFAILED\n");
        else
                fprintf(stdout, "Test_7\t->\tPASSED\n");
        printf("\n");

        delete_all(hashtab, &err);
        if (err == STERR_DELETEDALL)
                fprintf(stdout, "Test_8\t->\tFAILED\n");
        else
                fprintf(stdout, "Test_8\t->\tPASSED\n");
        printf("\n");
        return 0;
}
