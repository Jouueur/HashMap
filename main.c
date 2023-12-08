#include "tree.h"
#include "stack.h"
#include "hashtable.h"


/**
 * @mainpage HashMap project
 *
 * Here is my hashMap project, I tried to show everything in the main.
 * 
 *
 * @note Everytime I will talk about a stack, it is just a linked list. 
 * 
 */

int main() {
    HashMap *root = malloc(sizeof(HashMap));  
    if (root == NULL){
        printf("Problem in main, root is NULL");
        exit(1);
    }
    root->proot = NULL; 
    root->size = 0;
    node *seek = NULL;
    
    

    // Let's create some people
    node alexy = {.name="alexy", .value=5, .next=NULL};
    node estelle = {.name="estelle", .value=10, .next=NULL};
    node nathan = {.name="nathan", .value=18, .next=NULL};
    node francois = {.name="francois", .value=10, .next=NULL};
    node alexis = {.name="alexis", .value=10, .next=NULL};
    node romuald = {.name="romuald", .value=10, .next=NULL};
    node mourlad = {.name="mourlad", .value=10, .next=NULL};
    node efe = {.name="efe", .value=10, .next=NULL};
    node fee = {.name="fee", .value=15, .next=NULL};
    node eef = {.name="eef", .value=15, .next=NULL};

    // And add them to my HashMap
    addHM(root, &estelle, hash("estelle"));
    addHM(root, &alexy, hash("alexy"));
    addHM(root, &nathan, hash("nathan"));
    addHM(root, &francois, hash("francois"));
    addHM(root, &alexis, hash("alexis"));
    addHM(root, &romuald, hash("romuald"));
    addHM(root, &efe, hash("efe"));

    // Step 1
    printf("\nLet's add some people in the HashMap and see what it look like\n");
    prefixeHM(root);
    

    // Step 2
    printf("Now let's create some colisions\n");
    addHM(root, &mourlad, hash("mourlad"));
    addHM(root, &fee, hash("fee"));
    addHM(root, &eef, hash("eef"));
    prefixeHM(root);
    printf("Size of HashMap : %d\n",sizeHM(root));
    

    // Step 3
    printf("Try to look for a player\n\n");
    seek = getHM(root,"fee");   // Can use getABR if you want the hashed key

    if(seek != NULL){
        printf("Found it: \e[0;32m%s : \e[0;33m%d\e[0;37m\n",seek->name,seek->value);
    }


    // Step 4
    printf("Let's try to remove different players\n\n");
    printf("Removing fee (Last of stack)\n");
    removeHM(root, "fee");
    prefixeHM(root);
    printf("Size of HashMap : %d\n",sizeHM(root));
    

    printf("Removing alexis (Node of the tree with no next)\n");
    removeHM(root, "alexis");
    prefixeHM(root);
    printf("Size of HashMap : %d\n",sizeHM(root));
    

    printf("Removing efe (Node of tree with next)\n");
    removeHM(root, "efe");
    prefixeHM(root);
    printf("Size of HashMap : %d\n",sizeHM(root));
    

    freeHashMap(root);
    free(root);
    return 0;
}