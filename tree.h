#ifndef TREE_H
#define TREE_H

#include "stack.h"

/**
 * @brief Tree with hashed key as int 
 * 
 */
typedef struct Tree {
    int key;
    node *elmt;
    struct Tree *left;
    struct Tree *right;
} Tree;

/**
 * @brief create a node from a player
 * 
 * @param player couple name/value
 * @return Tree* The ABR node is done
 */
Tree *createnode(node *player);

/**
 * @brief Add a player to the ABR
 * 
 * @param root root of HM
 * @param player player to add
 * @param HashedKey hashed name of the player
 * @return Tree* root of the tree
 */
Tree *addABR(Tree *root, node *player, int HashedKey);

/**
 * @brief Get to the right hashed ked
 * 
 * @param root root of HM
 * @param key key to seek
 * @return Tree* return the node of the tree
 */
Tree *getABR(Tree *root, int key);

/**
 * @brief Remove a player from the hashmap
 * 
 * @param root root of HM
 * @param name name of player to delete
 * @return int 1 for success, 0 for fail
 */
int removeABR(Tree **root, char *name);

/**
 * @brief find the node furthest to the left to help remove
 * 
 * @param root root of HM
 * @return Tree* return the node furthest to the left
 */
Tree *findMin(Tree *root);

/**
 * @brief check if the player have a next 
 * 
 * @param root first in the stack
 * @param player player to check
 * @return int 1 if have a next, 0 otherwise
 */
int isInStack(Tree *root, node *player);


#endif 