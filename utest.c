#include <stdio.h>
#include "hashtable.h"
#include <stdlib.h>
#include <string.h>
#define HASHTAB_SIZE 128
#define HASHTAB_MUL 31

int main() {
        ST_ERR err;
        struct listnode *node;
        //Test 1 - create
        hashtab_init(hashtab);
        hashtab_add(hashtab, "Tigr", 190,&err);

        //Test2 - collision
        hashtab_add(hashtab, "Slon", 2300, &err);
        hashtab_add(hashtab, "Slon", 2300, &err);
        hashtab_add(hashtab, "Volk", 60, &err);

        //Test 3 - find in hashtable
        node = hashtab_lookup(hashtab, "Slon",&err);
        printf("Node: %s, %d\n", node->key, node->value);
        node = hashtab_lookup(hashtab, "Slon",&err);
        printf("Node: %s, %d\n", node->key, node->value);

        //Test 4 - find the element wich is not in the table
        node = hashtab_lookup(hashtab, "Crocodile",&err);

        //Test 5 - to delete element
        hashtab_delete(hashtab, "Slon", &err);
        node = hashtab_lookup(hashtab, "Slon",&err);
        printf("Node: %s, %d\n", node->key, node->value);

        //Test 6 - to delete element wich is not in the table 
        hashtab_delete(hashtab, "Crocodile", &err);
        return 0;
}

