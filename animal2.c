#include "animal.h"

struct treeStruct {
    char *string;
    struct treeStruct *left, *right;
};

struct positionStruct {
    struct treeStruct* node;
};


TreeType InitTree () {
    TreeType tree = calloc(MAXNUMQS,sizeof(char*));
    int i;
    for (i; i < MAXNUMQS; i++){
        char * question = calloc(MAXSTRLEN,sizeof(char));
        tree[i] = question;
    }
    strcpy(tree[0],"Is it furry?");
    strcpy(tree[1],"Does it meow?");
    strcpy(tree[2],"Does it have tusks?");
    strcpy(tree[(2*1)+1],"a cat");
    strcpy(tree[(2*1)+2],"a dog");
    strcpy(tree[(2*2)+1],"a rhino");
    strcpy(tree[(2*2)+2],"a gecko");
    //PrintTree(tree);
    return tree;
}