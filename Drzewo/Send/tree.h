#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct TreeStruct* Tree;

struct TreeStruct {
    Tree nextSib;
    Tree prevSib;
    Tree children;
    Tree rightmostChild;
    Tree parent; /*Information given for the "left" and "right" children only*/
    int number;
};


Tree newTree(int number);

void deleteParents(Tree batman);
void updateParenthood(Tree toUpdate);

void deleteBrotherhood(Tree familyOutcast);
void updateBrotherhood(Tree toUpdate);
