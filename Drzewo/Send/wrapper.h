#include "tree.h"

#define MAX_NUMBER_OF_NODES 500000

typedef struct WrapperStruct* Wrapper;

struct WrapperStruct {
    Tree array[MAX_NUMBER_OF_NODES];
    int numberOfNodes;
    int amount;
};



Wrapper newWrapper();
void deleteWrapper(Wrapper T);
Tree at(Wrapper T, int val);
void change(Wrapper T, int val, Tree target);

void addNode(Wrapper T, int k);
void rightmostChild(Wrapper T, int k);
void deleteNode(Wrapper T, int k);
void splitNode(Wrapper T, int k, int w);
void deleteSubtree(Wrapper T, int k);
