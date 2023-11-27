
#include "hashtable.h"
#include "stack.h"

int hash(const char *name) { // Hash a key
    int hash = 0;

    while (*name) {     // Add ascii value of each char
        hash += *name;
        name++;
    }
    return hash;
}



int addHM(HashMap *root, node *player, int HashedKey) { // Add in HM using hashed key
    if (root == NULL){
        printf("\e[0;31mProblem in addHM, root is NULL\e[0;37m\n");
        return 0;
    }
    if (player == NULL){
        printf("\e[0;31mProblem in addHM, player is NULL\e[0;37m\n");
        return 0;
    }

    root->proot = addABR(root->proot, player, HashedKey);   // Call the recursive function to add in the tree
    root->size++;   // increase size of the HM
    return 1;
}





node *getHM(HashMap *root, char *name) {    // Get a plaer (node) from a name
    Tree *seekedPlayer = NULL;
    node *seek = NULL;

    if (root == NULL){
        printf("\e[0;31mProblem in getHM, root is NULL\e[0;37m\n");
        exit(1);
    }
    
    seekedPlayer = getABR(root->proot, hash(name));   // Get to the good hashed key (first player of the stack)

    if (seekedPlayer == NULL) { // Just in case
        return NULL;
    }
    
    seek = getstack(seekedPlayer->elmt,name);   // Find the exact player in the stack 
    return seek;    // return a node
}


int removeHM(HashMap *root, char *name){    // Delete a player
    node *playerDelete = NULL;
    Tree *firstOfStack = NULL;

    if (root == NULL){
        printf("\e[0;31mProblem in removeHM, root is NULL\e[0;37m\n");
        return 0;
    } else if (name == NULL){
        printf("\e[0;31mProblem in removeHM, name is NULL\e[0;37mn");
        return 0;
    }

    firstOfStack = getABR(root->proot,hash(name));
    playerDelete = getHM(root,name);    // Seek the player to delete
    

    // Divide in three cases
    if (playerDelete == NULL || firstOfStack == NULL){      // Be sure that the player is here 
        printf("You want to delete a player but he isn't in the Hashmap\n");
        return -1;
    }
    if (isInStack(root->proot,playerDelete) == 1){ // If have next in stack -> easy delete
        printf("next\n");
        return removeNode(&(firstOfStack->elmt),name);

    } else if(isTreeNode(root, playerDelete) == 0){    // If isn't tree node (no next) -> easy delete
        printf("no node no next\n");
        return removeNode(&(firstOfStack->elmt),name);

    } else if(isTreeNode(root, playerDelete) == 1){    // If is tree node (no next) -> hard delete (recursive delete for tree node)
        printf("node no next\n");
        return removeABR(&(root->proot),name);
    }
    
}

int updateHM(HashMap *root, char *name, int newValue){ // Update values using getHM()
    node * seekedPlayer = NULL;
    if (root == NULL){
        printf("\e[0;31mProblem in updateHM, root is NULL\e[0;37m\n");
        return 0;
    }
    if (name == NULL){
        printf("\e[0;31mProblem in updateHM, name is NULL\e[0;37m\n");
        return 0;
    }
    
    seekedPlayer = getHM(root,name);    // Find the player 

    if (seekedPlayer == NULL){
        printf("You want to update a player but he isn't in the hashmap");
        return -1;
    }
    
    seekedPlayer->value = newValue;     // Change the value of the player
    return 1;
}



void prefixe(Tree *root) {  // recursive call to print Tree
    if (root != NULL) {
        prefixe(root->left);
        displayStack(root->elmt);  
        prefixe(root->right);
    }
}

void prefixeHM(HashMap *root){  //  Print the tree

    printf("\n\e[0;34mVisualisation de la hashmap: \e[0;37m\n");
    if (root == NULL){
        printf("\e[0;31mProblem in prefixeHM, root is NULL\e[0;37m\n");
        exit(1);
    }
    prefixe(root->proot);
    printf("\n\n");
}


int sizeHM(HashMap *root){  // Return HM size
    return root->size;
}

void freeTree(Tree *root) { // free TREE
    if (root != NULL){
        freeTree(root->left);
        free(root);
        freeTree(root->right);
    }
}

void freeHashMap(HashMap *root) {   // Free HM
    if (root != NULL) {
        freeTree(root->proot);
    }
}

int isTreeNode(HashMap *root, node *player){    // To check if the player is a Tree node (first player of a stack)
    if (root == NULL){
        printf("\e[0;31mProblem in isTreeNode, root is NULL\e[0;37m\n");
        return 0;
    } else if (player == NULL){
        printf("\e[0;31mProblem in isTreeNode, player is NULL\e[0;37m\n");
        return 0;
    }
    Tree *treeNode = NULL;

    treeNode = getABR(root->proot,hash(player->name)); // get to the first player of the stack 

    if (strcmp(treeNode->elmt->name,player->name) == 0){    // Compare first player of the stack with actual player
        return 1;   // return 1 if the seeked player is a tree node
    }
    return 0;
}

