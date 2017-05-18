#include "wrapper.h"

static void input(Wrapper T, bool diag) {
    char line[40];

    while (scanf("%s", line) != EOF) {
        int a;
        scanf("%d", &a);

        if (!strcmp(line, "RIGHTMOST_CHILD")) {
            rightmostChild(T, a);
        }
        else {
            if (!strcmp(line, "SPLIT_NODE")) {
                int b;
                scanf("%d", &b);
                splitNode(T, a, b);
            }
            else if (!strcmp(line, "ADD_NODE")) {
                addNode(T, a);
            }
            else if (!strcmp(line, "DELETE_NODE")) {
                deleteNode(T, a);
            }
            else if (!strcmp(line, "DELETE_SUBTREE")) {
                deleteSubtree(T, a);
            }
            printf("OK\n");
        }
        if (diag) {
            fprintf(stderr, "NODES: %d\n", T->amount);
        }
    }
}

int main(int argc, char * argv[]) {
    bool diag = false;

    if (argc > 1) {
        if ((strcmp(argv[1], "-v")) || argc > 2) {
            fprintf(stdout, "ERROR\n");
            return 1;
        }
        else {
            diag = true;
        }
    }

    Wrapper T = newWrapper();

    input(T, diag);

    deleteWrapper(T);

    return 0;
}
