#include <string.h>
#include <stdlib.h>

#define MAXSTRLEN 80
#define MAXNUMQS 32

typedef struct treeStruct *TreeType;
typedef struct positionStruct *PositionType;

/*
 * Return an animal tree (from file, if specified).
 */
TreeType InitTree (char *file);
void PrintTree (TreeType tree);
PositionType Top (TreeType tree);
int IsLeaf (TreeType tree, PositionType pos);
int Answer (char *question);
char *Question (TreeType tree, PositionType pos);
char *Guess (TreeType tree, PositionType pos);
PositionType YesNode (TreeType tree, PositionType pos);
PositionType NoNode (TreeType tree, PositionType pos);
void ReplaceNode (TreeType tree, PositionType pos, char *newA, char *newQ);
void GetNewInfo (TreeType tree, PositionType pos, char **newA, char **newQ);