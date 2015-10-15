#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "heightBalance.h"

static treelink createNode(int item) {
    treelink t = malloc(sizeof (*t));
    t->left = NULL;
    t->right = NULL;
    t->item = item;
    return t;
}


int main(int argc, char **argv) {
    treelink empty = NULL;
    printf("Testing on NULL tree.\n");
    assert(isHeightBalanced(empty));

    printf("one itme tree\n");
    treelink t = createNode(10);
    assert(isHeightBalanced(t));
    printf("two item tree\n");
    t->left = createNode(5);
    assert(isHeightBalanced(t));
    printf("three item tree\n");
    t->left->left = createNode(3);
    assert(!isHeightBalanced(t));

    printf("all tests passed! but will you pass the final tests...\n");
    return EXIT_SUCCESS;
}