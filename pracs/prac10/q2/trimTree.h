typedef struct _tree *treelink;
typedef struct _tree {
    int item;
    treelink left;
    treelink right;
} tree;


treelink trimTree(treelink t, int min, int max);