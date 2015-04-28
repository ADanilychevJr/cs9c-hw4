#ifndef ANIMAL_H
    #include "animal.h"
#endif

#include <stdio.h>
#include <stdbool.h>

#define MAXSTRLEN 80
#define MAXNUMQS 32
#define FALSE 0
#define TRUE !FALSE


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
    PositionType pos = malloc(sizeof(PositionType));
    if (strlen(tree->nodes[0]) > 0){
        pos->nodeIndex = 0;
        return pos;
    } else {
        printf("Tree has not been properly initialized\n");
        exit(1);
    }
}

boolean IsLeaf (TreeType tree, PositionType pos) {
    int yes = (2* pos->nodeIndex) + 1;
    int no = (2 * pos->nodeIndex) + 2;
    char * yesChild=NULL; char * noChild=NULL;
    if (isInBounds(yes)){
        yesChild = tree->nodes[yes];
    }
    if (isInBounds(no)){
        noChild = tree->nodes[no];
    }
    if (tree->nodes[pos->nodeIndex] == NULL){
        printf("IsLeaf called on a Null string at pos %d \n",pos->nodeIndex);
        return FALSE;
    } else if (yesChild !=NULL && noChild != NULL){//2 Children
        if ((strlen(yesChild) == 0) && (strlen(noChild) == 0)){
            return TRUE;
        } else {
            return FALSE;
        }
    } else if (yesChild != NULL){
        if (strlen(yesChild) == 0){
            return TRUE;
        } else {
            return FALSE;
        }
    } else if (noChild != NULL){
        if (strlen(noChild) == 0){
            return TRUE;
        } else {
            printf("Is not a leaf?\n");
            return FALSE;
        }
    }
    else { //Children would be out of bounds
        return TRUE;
    }
}

boolean isInBounds(int pos){
    if (pos > MAXNUMQS-1){
        return FALSE;
    } else {
        return TRUE;
    }
}

boolean Answer (char *question){
    return true;
}

char *Question (TreeType tree, PositionType pos){
    char * question = "Hello";
    return question;
}

char *Guess (TreeType tree, PositionType pos){
    char * guess = "guess";
    return guess;
}

PositionType YesNode (TreeType tree, PositionType pos){
    return pos;
}

PositionType NoNode (TreeType tree, PositionType pos){
    return pos;
}

void ReplaceNode (TreeType tree, PositionType pos, char *newA, char *newQ){
    return;
}

void GetNewInfo (TreeType tree, PositionType pos, char **newA, char **newQ){
    return;
}

void WriteTree(TreeType tree, char *file){
    return;
}
