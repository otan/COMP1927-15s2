#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "trimTree.h"

static treelink createNode(int item) {
    treelink t = malloc(sizeof (*t));
    t->left = NULL;
    t->right = NULL;
    t->item = item;
    return t;
}

static void freeTree(treelink t) {
    if (t == NULL) return;
    freeTree(t->left);
    freeTree(t->right);
    free(t);
}

int main(int argc, char **argv) {
    treelink empty = NULL;
    printf("Testing on NULL tree.\n");
    empty = trimTree(empty,0,100);
    assert(empty == NULL);

    printf("Testing on a one item tree\n");
    treelink oneitem = createNode(5);
    oneitem = trimTree(oneitem,0,6);
    assert(oneitem->item == 5);
    oneitem = trimTree(oneitem,1,5);
    assert(oneitem == NULL);

    printf("Testing on a two item tree\n");
    treelink twoitem = createNode(10);
    twoitem->left = createNode(8);
    twoitem = trimTree(twoitem,9,12);
    assert(twoitem->item == 10);
    assert(twoitem->left == NULL);
    freeTree(twoitem);

    printf("three item tree\n");
    treelink threeitem = createNode(10);
    threeitem->left = createNode(8);
    threeitem->left->right = createNode(9);
    threeitem = trimTree(threeitem,8,12);
    assert(threeitem->left->item == 9);
    freeTree(threeitem);

    printf("all tests passed! but will you pass the final tests...\n");
    return EXIT_SUCCESS;
}