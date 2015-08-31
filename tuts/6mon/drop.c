void drop(List l) {
    dropNodes(l->first);
    free(l);
}

void drop2(List l) {
    if (l->first == NULL) {
        free(l);
        return ;
    }
    Node temp = l->first->next;
    free(l->first);
    l->first = temp;
}

Node clone(Node n) {
    if (n == NULL) {
        return NULL;
    }
    Node newNode = createNode(n->data);
    newNode->next = clone(n->next);
    return newNode;
}

int fib(int n) {
    if (n <= 2) {
        return 1;
    }
    int array[n+1];
    array[1] = 1;
    array[2] = 1;
    int i;
    for (i = 3; i <= n; i++) {
        array[i] = array[i-1] + array[i-2];
    }
    return array[n];
}
