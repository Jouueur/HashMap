#ifndef STACK_H
#define STACK_H

/**
 * @brief struct to keep a player, his value and the next in stack
 * 
 */
typedef struct Node {
    char *name;
    int value;
    struct Node *next;
} node;

/**
 * @brief Add a player to the end of the stack
 * 
 * @param player first of the stack
 * @param playerToAdd player we want to add
 */
void addStack(node *player, node *playerToAdd);

/**
 * @brief Get a player (node) from his name
 * 
 * @param firstnode first of the stack
 * @param name name to seek
 * @return node* return the seeked player
 */
node *getstack(node *firstnode,char *name);

/**
 * @brief Display a stack (colision on the same key)
 * 
 * @param player first of the stack
 * @return int 1 for success, 0 for fail
 */
int displayStack(node *player);

/**
 * @brief  Remove a player without touching the tree 
 * 
 * @param player first of the stack 
 * @param name player to delete
 * @return int 1 for success, 0 for fail 
 */
int removeNode(node **player, char *name);

#endif /* STACK_H */
