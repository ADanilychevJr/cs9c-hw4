#include <string.h>
#include <stdlib.h>

#ifndef ANIMAL_H
#define ANIMAL_H 1

#define MAXSTRLEN 80
#define MAXNUMQS 32
typedef int boolean;

typedef struct treeStruct *TreeType;
typedef struct positionStruct *PositionType;

/*
 * Return an animal tree (from file, if specified).
 */
TreeType InitTree ();
void PrintTree (TreeType tree);
PositionType Top (TreeType tree);
boolean IsLeaf (TreeType tree, PositionType pos);
boolean Answer (char *question);
char *Question (TreeType tree, PositionType pos);
char *Guess (TreeType tree, PositionType pos);
PositionType YesNode (TreeType tree, PositionType pos);
PositionType NoNode (TreeType tree, PositionType pos);
void ReplaceNode (TreeType tree, PositionType pos, char *newA, char *newQ);
void GetNewInfo (TreeType tree, PositionType pos, char **newA, char **newQ);
void WriteTree(TreeType tree, char *file);

boolean isInBounds(PositionType pos); //My own helper method

#endif
