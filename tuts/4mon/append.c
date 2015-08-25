Node append(Node n, int num) {
    if (n == NULL) {
        return createNode(num);
    }
    n->next = append(n->next, num);
    return n;
}
