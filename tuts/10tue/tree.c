int countNodes(Node n) {
    if (n == NULL) {
        return 0;
    }
    return 1 + countNodes(n->left) + countNodes(n->right);
}

int sumNodes(Node n) {
    if (n == NULL) {
        return 0;
    }
    return n->value + sumNodes(n->left) + sumNodes(n->right);
}

int maxBranchLength(Node n) {
    if (n == NULL) {
        return 0;
    }
    return 1 + max(maxBranchLength(n->left), maxBranchLength(n->right));
}

int width(Node n) {
    return 3 * countNodes(n);
}

Node delete(Node n, int value) {
    if (n == NULL) {
        return NULL;
    }
    if (value > n->value) {
        n->right = delete(n->right, value);
    } else if (value < n->value) {
        n->left = delete(n->left, value);
    } else {
        Node prev = NULL;
        Node next = n->right;
        if (next == NULL) {
            return n->left;
        } else {
            while (next->left != NULL) {
                prev = next;
                next = next->left;
            }
            prev->left = next->right;
            next->left = n->left;
            return next;
        }
    }
    return n;
}
