// Oliver Tan

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

#define THIS_IS_MADNESS 5
#define SPARTA 100

void printList(Node n) {
    if (n == NULL) {
        printf("[X]\n");
        return;
    }
    printf("[%d]->", n->data);
    printList(n->next);
}

void testIsSorted() {
    // empty list is sorted
    {
        printf("testing empty list\n");
        List l = createList();
        assert(isSorted(l) == TRUE);
        free(l);
        printf("passed empty list!\n");
    }
    // one element lists are sorted
    {
        printf("testing one element list\n");
        List l = createList();
        l->size = 1;

        int i;
        for (i = 0; i < THIS_IS_MADNESS; i++) {
            l->first = l->last = createNode(i);
            printList(l->first);
            assert(isSorted(l) == TRUE);
            free(l->first);
        }
        free(l);
        printf("passed one element list!\n");
    }
    // two element lists!
    {
        printf("testing two element list\n");
        List l = createList();
        l->size = 2;
        int i, j;
        for (i = 0; i < THIS_IS_MADNESS; i++) {
            l->first = createNode(i);
            for (j = 0; j < THIS_IS_MADNESS; j++) {
                l->first->next = l->last = createNode(j);
                printList(l->first);
                assert(isSorted(l) == (i <= j));
                free(l->last);
            }
            free(l->first);
        }
        free(l);
        printf("passed two element list!\n");
    }
    // three element lists
    {
        printf("testing three element list\n");
        List l = createList();
        l->size = 3;
        int i, j, k;
        for (i = 0; i < THIS_IS_MADNESS; i++) {
            l->first = createNode(i);
            for (j = 0; j < THIS_IS_MADNESS; j++) {
                l->first->next = createNode(j);
                for (k = 0; k < THIS_IS_MADNESS; k++) {
                    l->first->next->next = l->last = createNode(k);
                    printList(l->first);
                    assert(isSorted(l) == (i <= j && j <= k));
                    free(l->last);
                }
                free(l->first->next);
            }
            free(l->first);
        }
        free(l);
        printf("passed three element list!\n");
    }
}

int main(void) {
    testIsSorted();
    printf("i am satisifed with your function. congratulations. asian father approves.\n");
    return 0;
}
