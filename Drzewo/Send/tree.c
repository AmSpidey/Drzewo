#include "tree.h"

Tree newTree(int number) {
    Tree newTree = malloc(sizeof(struct TreeStruct));

    newTree->number = number;

    newTree->nextSib = NULL;
    newTree->prevSib = NULL;
    newTree->children = NULL;
    newTree->rightmostChild = NULL;
    newTree->parent = NULL;

    return newTree;
}

void deleteParents(Tree orphan) {
    if (orphan->parent != NULL) {
        if (orphan->parent->children == orphan) { /*If you are LMC*/
            orphan->parent->children = orphan->nextSib; /*Your right sibling will be LMC*/

            if (orphan->nextSib != NULL) {
                orphan->nextSib->parent = orphan->parent;
            }
        }

        if (orphan->parent->rightmostChild == orphan) {
            orphan->parent->rightmostChild = orphan->prevSib;

            if (orphan->prevSib != NULL) {
                orphan->prevSib->parent=orphan->parent;
            }
        }
    }
}

void updateParenthood(Tree toUpdate) {
    if (toUpdate->children == NULL) {
		deleteParents(toUpdate);
	}
	else { /*Give your children new parents.*/
		toUpdate->children->parent = toUpdate->parent;
        toUpdate->rightmostChild->parent = toUpdate->parent;

		if (toUpdate->prevSib != NULL && toUpdate->nextSib != NULL) {
			toUpdate->children->parent = NULL;
			toUpdate->rightmostChild->parent = NULL;
		}
		if (toUpdate->children != toUpdate->rightmostChild) {
			if (toUpdate->prevSib != NULL) {
				toUpdate->children->parent = NULL;
			}
			if (toUpdate->nextSib != NULL) {
				toUpdate->rightmostChild->parent = NULL;
			}
		}

        if (toUpdate->parent != NULL) {
            if (toUpdate->parent->rightmostChild == toUpdate) {
                toUpdate->parent->rightmostChild = toUpdate->rightmostChild;
            }

            if (toUpdate->parent->children == toUpdate) {
                toUpdate->parent->children = toUpdate->children;
            }
        }
    }
}

void deleteBrotherhood(Tree familyOutcast) {
    if (familyOutcast->prevSib != NULL) {
        familyOutcast->prevSib->nextSib = familyOutcast->nextSib;
    }
    if (familyOutcast->nextSib != NULL) {
        familyOutcast->nextSib->prevSib = familyOutcast->prevSib;
    }
}

void updateBrotherhood(Tree toUpdate) {
    if (toUpdate->children == NULL) {
        deleteBrotherhood(toUpdate);
    }
    else {
	if (toUpdate->prevSib == NULL) {
            toUpdate->children->prevSib = NULL;
        }
        else {
            toUpdate->prevSib->nextSib = toUpdate->children;
            toUpdate->children->prevSib = toUpdate->prevSib;
        }

        if (toUpdate->nextSib == NULL) {
			toUpdate->rightmostChild->nextSib = NULL;
        }
        else {
            toUpdate->nextSib->prevSib = toUpdate->rightmostChild;
            toUpdate->rightmostChild->nextSib = toUpdate->nextSib;
        }
    }
}
