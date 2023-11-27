#include "tree.h"
#include "stack.h"
#include "hashtable.h"


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
    addHM(root, &mourlad, hash("mourlad"));
    addHM(root, &efe, hash("efe"));
    addHM(root, &fee, hash("fee"));
    addHM(root, &eef, hash("eef"));

    // Try to look for a player
    seek = getHM(root,"fee");

    if(seek != NULL){
        printf("Found it: %s : %d\n",seek->name,seek->value);
    }



    prefixeHM(root);
    removeHM(root, "romuald");
    prefixeHM(root);


    // We still have the size of the hashmap
    printf("Size of HashMap : %d\n",sizeHM(root));

    //printf("%s", getHM(root,"estellse")->name);
    //printf("%d", hash("Liam"));

    freeHashMap(root);
    free(root);
    return 0;
}