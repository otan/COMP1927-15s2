Node append(Node first, int n) {
    if (first == NULL) {
        return createNode(n);
    }
    first->next = append(first->next, n);
    return first;
}
