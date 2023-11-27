#ifndef STACK_H
#define STACK_H


typedef struct Node {
    char *name;
    int value;
    struct Node *next;
} node;

void addStack(node *player, node *playerToAdd);
int displayStack(node *player);
node *getstack(node *firstnode,char *name);
int removeNode(node **player, char *name);

#endif /* STACK_H */
