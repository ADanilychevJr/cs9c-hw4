#include "animal.h"

struct treeStruct {
    char *string;
    struct treeStruct *left, *right;
};

struct positionStruct {
    struct treeStruct* node;
};