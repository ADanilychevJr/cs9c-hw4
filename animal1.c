#ifndef ANIMAL_H
    #include "animal.h"
#endif




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
/*This works, ignore "animal1.c:25: warning: statement with no effect"*/
TreeType InitTree (char *file) {
    
    TreeType tree = malloc(sizeof(TreeType));
    int i=0;
    for (i; i < MAXNUMQS; i++){
        char * question = calloc(MAXSTRLEN,1);
        tree->nodes[i] = question;
    }
    if (file == NULL){
        strcpy(tree->nodes[0],"Is it furry?");
        strcpy(tree->nodes[1],"Does it meow?");
        strcpy(tree->nodes[2],"Does it have tusks?");
        strcpy(tree->nodes[(2*1)+1],"a cat");
        strcpy(tree->nodes[(2*1)+2],"a dog");
        strcpy(tree->nodes[(2*2)+1],"a rhino");
        strcpy(tree->nodes[(2*2)+2],"a gecko");
    } else {
        FILE* f = fopen(file, "r");
        if (f == NULL){ printf("Error reading from file\n"); exit(1);}
        char line[256];
        int index;
        printf("Got to here\n");
        while (fscanf(f,"%d %s\n",index, line) != EOF){
            printf("%s\n",line);
            strcpy(tree->nodes[index],line);
        }
    }
    return tree;
}
/*This works, ignore "animal1.c:42: warning: statement with no effect"*/
void PrintTree(TreeType tree){
    int i = 0;
    printf("Tree:\n");
    for (i; i < MAXNUMQS; i++){
        printf("%d: %s\n",i,tree->nodes[i]);
    }
}

PositionType Top (TreeType tree){
    PositionType pos = malloc(sizeof(PositionType)+10);
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
    if (strlen(tree->nodes[pos->nodeIndex]) >0){
        char * question;
        question = tree->nodes[pos->nodeIndex];
        return question;
    } else {
        printf("Tried to get question at position %d but failed\n",pos->nodeIndex);
        PrintTree(tree);
        return NULL;
    }
}

char *Guess (TreeType tree, PositionType pos){
    char *guess = calloc(MAXSTRLEN,sizeof(char));
    if ((strlen(tree->nodes[pos->nodeIndex]) != 0)){
        sprintf(guess, "%s%s%s", "is it ",tree->nodes[pos->nodeIndex],"?");
        return guess;
    } else {
        printf("Called guess on leaf w/ length 0: %s\n", tree->nodes[pos->nodeIndex]);
        return guess;
    }
}

PositionType YesNode (TreeType tree, PositionType pos){
    PositionType newpos = malloc(sizeof(PositionType)+10);;
    newpos->nodeIndex = (2 * pos->nodeIndex) + 1;
    if (newpos->nodeIndex >= MAXNUMQS){
        printf("Tree out of bounds problem for  yes index:%d\n",newpos->nodeIndex);
        exit(0);
    } else {
        return newpos;
    }
}

PositionType NoNode (TreeType tree, PositionType pos){
    PositionType newpos = malloc(sizeof(PositionType)+10);;
    newpos->nodeIndex = (2 * pos->nodeIndex) + 2;
    if (newpos->nodeIndex >= MAXNUMQS){
        printf("Tree out of bounds problem for no index:%d\n",newpos->nodeIndex);
        exit(0);
    } else {
        return newpos;
    }
}

void ReplaceNode (TreeType tree, PositionType pos, char *newA, char *newQ){
    int yesPosition = (pos->nodeIndex * 2) +1;
    int noPosition = (pos->nodeIndex *2) + 2;
    if (!isInBounds(yesPosition)){
        printf("Not enough space to put new yes answer\n");
        return;
    } else if (!isInBounds(noPosition)){
        printf("Not enough space to put new no answer\n");
        return;
    }
    char * old;
    old = tree->nodes[pos->nodeIndex];
    tree->nodes[pos->nodeIndex] = calloc(MAXSTRLEN,sizeof(char));
    strcpy(tree->nodes[pos->nodeIndex],newQ);
    strcpy(tree->nodes[yesPosition],old);//Yes answer is old
    strcpy(tree->nodes[noPosition],newA); //No answer is the newA
    return;
}

void GetNewInfo (TreeType tree, PositionType pos, char **newA, char **newQ){
    char * old;
    printf("I give up. What is it?");
    *newA = getUserInput();
    old = tree->nodes[pos->nodeIndex];
    printf("Provide a question whose answer is yes for %s and no for %s\n",old,*newA);
    *newQ = getUserInput();
    return;
}

void WriteTree(TreeType tree, char *file){
    if (file == NULL){
        printf("Not writing to file (none specified)\n");
        return;}
    FILE *f = fopen(file,"w");
    if (f==NULL){
        printf("Error opening file!\n");
        exit(1);
    }
    printf("Writing to %s\n",file);
    int i = 0;
    for (i; i < MAXNUMQS; i++){
        if (strlen(tree->nodes[i])>0){
            fprintf(f, "%d %s\n",i,tree->nodes[i]);
        }
    }
    fclose(f);
    return;
}
