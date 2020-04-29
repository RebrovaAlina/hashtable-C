#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define HASHTAB_SIZE 128 
#define HASHTAB_MUL 31
typedef enum{
        STERR_SUCCESS=0,
        STERR_FULL  = 1,
        STERR_DELETED= 2,
        STERR_NOELEM = 3
} ST_ERR;

struct listnode
{
        char *key;
        int value;
        struct listnode *next;
};


struct listnode *hashtab[HASHTAB_SIZE];
struct listnode *hashtab_lookup(struct listnode **hashtab, char *key, ST_ERR *err);
unsigned int hashtab_hash(char *key);
void hashtab_init(struct listnode **hashtab);
void hashtab_add(struct listnode **hashtab, char *key, int value, ST_ERR *err) ;
void hashtab_delete(struct listnode **hashtab, char *key, ST_ERR *err);
