#include "animal.h"

struct treeStruct {
    char *nodes[MAXNUMQS];
};

struct positionStruct {
    int nodeIndex;
};

TreeType InitTree () {
    TreeType tree = malloc(sizeof(TreeType));
    int i;
    for (i; i < MAXNUMQS; i++){
        char * question = calloc(MAXSTRLEN,sizeof(char));
        (tree->nodes)[i] = question;
    }
    strcpy(tree->nodes[0],"Is it furry?");
    strcpy(tree->nodes[1],"Does it meow?");
    strcpy(tree->nodes[2],"Does it have tusks?");
    strcpy(tree->nodes[(2*1)+1],"a cat");
    strcpy(tree->nodes[(2*1)+2],"a dog");
    strcpy(tree->nodes[(2*2)+1],"a rhino");
    strcpy(tree->nodes[(2*2)+2],"a gecko");
    return tree;
}

void PrintTree(TreeType tree){
    int i = 0;
    printf("Tree:\n");
    for (i; i < MAXNUMQS; i++){
        printf("%d: %s\n",i,tree->nodes[i]);
    }
}

PositionType Top (TreeType tree){
    PositionType pos;
    if (strlen(tree->nodes[0]) > 0){
        pos->nodeIndex = 0;
        return pos;
    } else {
        printf("Tree has not been properly initialized\n");
        exit(1);
    }
}
