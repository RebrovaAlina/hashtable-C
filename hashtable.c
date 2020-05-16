#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include <limits.h>
#include <unistd.h>
#define HASHTAB_SIZE 128

unsigned int hashtab_hash(char *key)
{
        int len = strlen(key), hashf = 0;
        if (len <= 1)
               hashf = key[0];
        else
               hashf = key[0] + key[len-1];
        return hashf % HASHTAB_SIZE;


}

void hashtab_init(struct listnode **hashtab)
{
        int i;
        for (i = 0; i < HASHTAB_SIZE; i++)
        {
                hashtab[i] = NULL;
        }
}

void hashtab_add(struct listnode **hashtab, char *key, int value, ST_ERR *err)
{
        *err= STERR_SUCCESS;
        struct listnode *node;
        int index = hashtab_hash(key);
        node = malloc(sizeof(*node));
        if (node != NULL)
        {
                node->key = key;
                node->value = value;
                node->next = hashtab[index];
                hashtab[index] = node;
                return;
        }
        fprintf(stderr, "Can't add the element\n");
        if (err != NULL)
                *err= STERR_NOADD;
        return;
}

struct listnode *hashtab_lookup( struct listnode **hashtab, char *key, ST_ERR *err
{
        *err= STERR_SUCCESS;
        int index;
        struct listnode *node;
        index = hashtab_hash(key);
        for (node = hashtab[index]; node != NULL; node = node->next)
        {
                if (strcmp(node->key, key) == 0)
                {
                        printf("Node: %s, %d\n", node->key, node->value);
                        return node;
                };
        };
        fprintf(stderr, "No such element\n");
        if (err != NULL)
        {
                *err= STERR_NOELEM;
                return NULL;
        }
        return NULL;
};
void hashtab_delete(struct listnode **hashtab, char *key, ST_ERR *err)
{
        *err= STERR_SUCCESS;
        int index;
        struct listnode *p, *prev = NULL;
        index = hashtab_hash(key);
        for (p = hashtab[index]; p != NULL; p = p->next)
        {
                if (strcmp(p->key, key) == 0)
                {
                        if (prev == NULL)
                                hashtab[index] = p->next;
                        else prev->next = p->next;
                        free(p);
                        return;
                }
                prev = p;
        }

        fprintf(stderr, "Can't delete the element\n");
        if (err != NULL)
                *err= STERR_DELETED;


}
void delete_all(struct listnode **hashtab, ST_ERR *err)
{
        *err= STERR_SUCCESS;
        int index = 0;
        int i = 0;
        struct listnode *p, *prev = NULL;
        for (index = 0; index < HASHTAB_SIZE; index++)
        {
                p = hashtab[index];
                if(p!=NULL)
                {
                        if (prev == NULL)
                                hashtab[index] = p->next;
                        else prev->next = p->next;
                        free(p);
                        i++;
                };
                prev = p;
        }

        if(i==0)
        {
                fprintf(stderr, "There is no table\n");
                if (err != NULL)
                        *err= STERR_DELETEDALL;
                return;
        }
}
