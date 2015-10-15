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
    printf("four item tree\n");
    t->right = createNode(4);
    assert(isHeightBalanced(t));
    t->right->left = createNode(4);
    assert(isHeightBalanced(t));
    t->right->right = createNode(4);
    assert(isHeightBalanced(t));
    t->right->right->right = createNode(4);
    assert(isHeightBalanced(t));
    t->right->right->right->left = createNode(4);
    assert(!isHeightBalanced(t));

    printf("all tests passed! asian father approves\n");
    return EXIT_SUCCESS;
}
