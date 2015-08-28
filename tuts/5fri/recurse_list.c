int countNode(Node n) {
    if (n == NULL) {
        return 0;
    }
    return 1 + countNode(n->next);
}

Node append(Node curr, int n) {
    if (curr == NULL) {
        return createNode(n);
    }
    curr->next = append(curr->next, n);
    return curr;
}
