#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "tree.h"
#include "stack.h"

typedef struct HashMap {
    Tree *proot;
    int size;
} HashMap;

int hash(const char *name);
int addHM(HashMap *root, node *player, int HashedKey);
node *getHM(HashMap *root, char *name);
int removeHM(HashMap *root, char *name);
int updateHM(HashMap *root, char *name, int newValue);
void prefixe(Tree *root);
void prefixeHM(HashMap *root);
int sizeHM(HashMap *root);
void freeTree(Tree *root);
void freeHashMap(HashMap *root);
int isTreeNode(HashMap *root, node *player);

#endif /* HASHTABLE_H */
