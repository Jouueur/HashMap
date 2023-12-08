#include "stack.h"
#include "hashtable.h"
#include "tree.h"

/**
 * @brief adzazdazd
 * 
 * @param player 
 * @param playerToAdd 
 */
void addStack(node * player, node *playerToAdd) {   
    if (player == NULL || playerToAdd == NULL) {
        printf("\e[0;31mProblem in addStack function, root or playerToAdd is NULL \e[0;37m");
        exit(2);
    }

    // Go to the end of the stack
    while (player->next != NULL) {
        player = player->next;
    }

    // Add the player
    player->next = playerToAdd;
}

node *getstack(node *firstnode,char *name){ 
    node *tmp = firstnode;
    while(tmp != NULL){
        if (strcmp(name,tmp->name) == 0){
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}


int displayStack(node *player){
    if (player == NULL){
        printf("\e[0;31mProblem in displayStack, player is NULL\e[0;37m");
        return 0;
    }
    printf("%d | ",hash(player->name));
    while (player != NULL){
        
        printf("\e[0;32m%s\e[0;37m : ",player->name);
        printf("\e[0;33m%d\e[0;37m  -> ",player->value);
        player = player->next;
    }
    printf("\n");
    return 1;
}

int removeNode(node **player, char *name) {     
    if (*player == NULL || name == NULL) {
        printf("\e[0;31mProblem in removeNode, player or name is NULL\e[0;37m\n");
        return 0;
    }

    node *current = *player;
    node *prev = NULL;

    while (current != NULL && strcmp(current->name, name) != 0) {   // Find the player
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        return 0;
    }

    if (prev == NULL) {
        *player = current->next;    
    } else {
        prev->next = current->next;     
    }
    return 1;
}

