#include "animal.h"

struct treeStruct {
    char *nodes[MAXNUMQS];
};

struct positionStruct {
    int nodeIndex;
};

TreeType InitTree () {
    TreeType tree = malloc(sizeof(TreeType));
    return tree;
}
