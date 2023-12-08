#include "tree.h"
#include "stack.h"
#include "hashtable.h"

Tree *createnode(node *player){
    Tree* newNode = malloc(sizeof(Tree));    
    if (newNode == NULL){
        printf("\e[0;31mProblem in createnode");
        exit(1);
    }    
        
    newNode->key = hash(player->name);
    newNode->elmt = player;
    newNode->right=NULL;
    newNode->left=NULL;
    return newNode;
}

Tree* addABR(Tree *root, node *player, int HashedKey) { 
    if (root == NULL) {
        return createnode(player);
    }
    else if (HashedKey == root->key){
        addStack(root->elmt,player);    // Add to a stack if hashed key already used
    }
    else if (HashedKey< root->key) {
        root->left = addABR(root->left, player, HashedKey);
    }
    else if (HashedKey > root->key) {
        root->right = addABR(root->right, player, HashedKey);
    }
    return root;
}

Tree *getABR(Tree *root, int key){
    
    if (root == NULL || key == root->key) {
        return root;
    }
    if (key < root->key) {
        return getABR(root->left, key);
    } else {
        return getABR(root->right, key);
    }
}


int removeABR(Tree **root, char *name) {    
    int keyToRemove = hash(name);   
    Tree *PlayerInStack = getABR(*root,keyToRemove); // PlayerInStack is the first player of the stack of the hashed key
    node *Player = NULL;

    Player = getstack(PlayerInStack->elmt,name);    // Player is the exact node in the stack

        if (keyToRemove == (*root)->key) {
            Tree *temp = *root;

            if (temp->elmt->next != NULL){
                (*root)->elmt = temp->elmt->next;
                return 1;

            } else if ((*root)->left == NULL && (*root)->right == NULL) {   // Node with no child
                free(temp);
                *root = NULL;  // Set the pointer to NULL after freeing
                return 1;  
            } else if ((*root)->left == NULL) { // Node with only right child
                *root = (*root)->right;
                free(temp);
                return 1;  
            } else if ((*root)->right == NULL) {    // Node with only left child 
                *root = (*root)->left;
                free(temp);
                return 1;  
            } else {    // Node with 2 childs
                Tree *successor = findMin((*root)->right);  
                (*root)->key = successor->key;
                (*root)->elmt = successor->elmt;
                return removeABR(&(*root)->right, successor->elmt->name);
            }
        } else if (keyToRemove < (*root)->key) {
            return removeABR(&(*root)->left, name);
        } else {
            return removeABR(&(*root)->right, name);
        }
    
}


Tree *findMin(Tree *root) {
    if (root == NULL) {
        return NULL;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

int isInStack(Tree *root, node *player){
    int key = hash(player->name);
    
    if (player == NULL){
        printf("\e[0;31mProblem in isInStack, player is NULL");
        return 0;
    }
    
    if (player->next != NULL) {  // if have a next
        return 1;
    } else {
        return 0;   // if have no next 
    }
}