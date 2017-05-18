#include "wrapper.h"

Wrapper newWrapper() {
    Wrapper newWrapper = malloc(sizeof(struct WrapperStruct));

    newWrapper->array[0] = newTree(0);
    newWrapper->numberOfNodes = 0;
    newWrapper->amount = 1;
    return newWrapper;
}

void deleteWrapper(Wrapper T) {
    for (int i = 0; i <= T->numberOfNodes; ++i) {
        if(T->array[i] != NULL) {
            free(T->array[i]);
        }
    }
    free(T);
}

void addNode(Wrapper T, int k) {
    T->numberOfNodes++;
    T->amount++;

    Tree father = T->array[k];

    Tree newNode = newTree(T->numberOfNodes);
    T->array[T->numberOfNodes] = newNode;

    newNode->parent = father;

    if (father->rightmostChild != NULL) { /*If the root had children, it will have a new RMC*/
        father->rightmostChild->parent = NULL;
        father->rightmostChild->nextSib = newNode;
    }
    else { /*Else - it has a new LMC*/
        father->children = newNode;
    }

    newNode->prevSib = father->rightmostChild; /*newNode will always be RMC.*/
    father->rightmostChild = newNode;

    father->children->parent = father; /*LMC - father "reminder"*/
}


void rightmostChild(Wrapper T, int k) {
    if (T->array[k]->children == NULL) {
        printf("-1\n");
    }
    else {
        printf("%d\n", T->array[k]->rightmostChild->number);
    }
    return;
}

void deleteNode(Wrapper T, int k) {
    Tree delete = T->array[k];
    updateBrotherhood(delete);
    updateParenthood(delete);

    free(delete);
    T->array[k] = NULL;
    T->amount--;
}

void deleteSubtree(Wrapper T, int k) {
    Tree delete = T->array[k];

    if(delete == NULL) {
        return;
    }

    deleteParents(delete);
    deleteBrotherhood(delete);

    while (delete->children != NULL) {
        deleteNode(T, delete->children->number); /*Delete the children*/
    }

    deleteNode(T, k);
}


void splitNode(Wrapper T, int k, int w) {
    T->numberOfNodes++;
    T->amount++;
    Tree father = T->array[k];
    Tree son = T->array[w];

    Tree newNode = newTree(T->numberOfNodes);

    newNode->children = son->nextSib;
    newNode->rightmostChild = NULL;

    if (newNode->children != NULL) {  /*If you have children, become their parent and correct LMC and RMC*/
        newNode->children->parent = newNode;
        newNode->children->prevSib = NULL;

        newNode->rightmostChild = father->rightmostChild;
        newNode->rightmostChild->parent = newNode;
    }

    son->nextSib = newNode;
    father->rightmostChild = newNode;

    if (son != father->children) {
        son->parent = NULL;
    }
    newNode->parent = father;
    newNode->nextSib = NULL;
    newNode->prevSib = son;

    T->array[T->numberOfNodes] = newNode;
}
