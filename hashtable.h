
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "tree.h"
#include "stack.h"


/**
 * @brief Struct to keep the root of hashMap and keep track of the size
 * 
 */
typedef struct HashMap {
    Tree *proot;
    int size;
} HashMap;

/**
 * @brief Add ASCII value for each caracter
 * 
 * @param name name of the player
 * @return int 
 */
int hash(const char *name);

/**
 * @brief Add a player to the HashMap
 * 
 * @param root root of HashMap
 * @param player struct player (couple name/value)
 * @param HashedKey hashed name
 * @return int 1 for success, 0 for fail
 */
int addHM(HashMap *root, node *player, int HashedKey);

/**
 * @brief Look for a player via his name 
 * 
 * @param root root of the HashMap
 * @param name name of the player we are looking for
 * @return node* return the looked player
 */
node *getHM(HashMap *root, char *name);

/**
 * @brief Remove a player in the HashMap using his name
 * 
 * @param root root of the HashMap
 * @param name name of the player we want to delete
 * @return int 1 for success, 0 for fail
 */
int removeHM(HashMap *root, char *name);

/**
 * @brief Look for a player using his name and change his value
 * 
 * @param root root of the HashMap
 * @param name player we want to update
 * @param newValue Value we want to add
 * @return int 1 for success, 0 for fail
 */
int updateHM(HashMap *root, char *name, int newValue);

/**
 * @brief recursive way to display the HashMap
 * 
 * @param root root of the HashMap
 */
void prefixe(Tree *root);

/**
 * @brief Call the prefixe function
 * 
 * @param root root of the HashMap
 */
void prefixeHM(HashMap *root);

/**
 * @brief look in HashMap struct to return size of HashMap
 * 
 * @param root root of the HashMap
 * @return int the size of the HashMap
 */
int sizeHM(HashMap *root);

/**
 * @brief recursive way to free the HM
 * 
 * @param root root of HM
 */
void freeTree(Tree *root);

/**
 * @brief Call freeTree
 * 
 * @param root root of HM
 */
void freeHashMap(HashMap *root);

/**
 * @brief Function which check if the player is part of the ABR (first player of a stack)
 * 
 * @param root root of HM
 * @param player player we we want to check
 * @return int return 1 if the seeked player is a tree node, 0 otherwise
 */
int isTreeNode(HashMap *root, node *player);

#endif /* HASHTABLE_H */
