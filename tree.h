#ifndef TREE_H
#define TREE_H

#include "stack.h"


typedef struct Tree {
    int key;
    node *elmt;
    struct Tree *left;
    struct Tree *right;
} Tree;

Tree *createnode(node *player);
Tree *addABR(Tree *root, node *player, int HashedKey);
Tree *getABR(Tree *root, int key);
int removeABR(Tree **root, char *name);
Tree *findMin(Tree *root);
int isInStack(Tree *root, node *player);


#endif 