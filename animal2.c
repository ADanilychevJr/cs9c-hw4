#ifndef ANIMAL_H
#include "animal.h"
#endif

#define MAXSTRLEN 80
#define MAXNUMQS 32
#define FALSE 0
#define TRUE !FALSE

struct treeStruct {
    char *string;
    struct treeStruct *left, *right;
};

struct positionStruct {
    struct treeStruct* node;
};

TreeType addNode(TreeType parent, char *str, boolean left){
    TreeType child = malloc(sizeof(TreeType));
    child->string = calloc(MAXSTRLEN,1);
    strcpy(child->string,str);
    if (left){
        parent->left = child;
    } else{
        parent->right = child;
    }
    return child;
}


TreeType InitTree (char *file) {
    TreeType tree = malloc(sizeof(TreeType));
    tree->string = calloc(MAXSTRLEN,1);
    strcpy(tree->string,"Is it furry?");
    
    TreeType one = addNode(tree,"Does it meow?", true);
    TreeType two = addNode(tree,"Does it have tusks?", false);
    addNode(one,"a cat", true);
    addNode(one,"a dog", false);
    addNode(two,"a rhino", true);
    addNode(two,"a gecko", false);
    return tree;
}

void PrintTree(TreeType tree){
    printf("Tree:\n");
    char * str = tree->string;
    printf("%s\n",str);
    if (tree->left){
        PrintTree(tree->left);
    }
    if (tree->right){
        PrintTree(tree->right);
    }
}

PositionType Top (TreeType tree){
    PositionType pos = malloc(sizeof(PositionType));
    pos->node = tree;
    return pos;
}

boolean IsLeaf(TreeType tree, PositionType pos){
    if (!(pos->node->left || pos->node->right)){
        return true;
    } else {
        return false;
    }
}

boolean Answer (char *question){
    if (question != NULL){
        printf("%s\n",question);
        char * answer;
        answer = getUserInput();
        if (answer[0] == 'y'){
            return TRUE;
        } else {
            return FALSE;
        }
    } else {
        printf("Passed in a null question! Returning False\n");
        return FALSE;
    }
}

char * getUserInput(){
    char * str = calloc(MAXSTRLEN,sizeof(char));
    int i = 0; int c;
    while ((c = getchar())!= '\n'){
        str[i] = c;
        i++;
    }
    return str;
}

char *Question (TreeType tree, PositionType pos){
    if (strlen(pos->node->string) >0){
        char * question;
        question = pos->node->string;
        return question;
    } else {
        printf("Tried to get question but failed\n");
        PrintTree(tree);
        return NULL;
    }
}

char *Guess (TreeType tree, PositionType pos){
    char *guess = calloc(MAXSTRLEN,sizeof(char));
    if ((strlen(pos->node->string) != 0)){
        sprintf(guess, "%s%s%s", "is it ",pos->node->string,"?");
        return guess;
    } else {
        printf("Called guess on leaf w/ length 0\n");
        return guess;
    }
}

PositionType YesNode (TreeType tree, PositionType pos){
    PositionType newpos = malloc(sizeof(PositionType));
    newpos->node = pos->node->left;
    return newpos;
}

PositionType NoNode (TreeType tree, PositionType pos){
    PositionType newpos = malloc(sizeof(PositionType));
    newpos->node = pos->node->right;
    return newpos;
}

void ReplaceNode (TreeType tree, PositionType pos, char *newA, char *newQ){
    char * old = pos->node->string;
//tree->nodes[pos->nodeIndex] = calloc(MAXSTRLEN,sizeof(char));
    
    pos->node->string = newQ;
    addNode(pos->node, old, true);
    addNode(pos->node, newA, false);
    return;
}

void GetNewInfo (TreeType tree, PositionType pos, char **newA, char **newQ){
    char * old;
    printf("I give up. What is it?");
    *newA = getUserInput();
    old = pos->node->string;//tree->nodes[pos->nodeIndex];
    printf("Provide a question whose answer is yes for %s and no for %s\n",old,*newA);
    *newQ = getUserInput();
    return;
}

void WriteTree(TreeType tree, char *file){
    return;
}
