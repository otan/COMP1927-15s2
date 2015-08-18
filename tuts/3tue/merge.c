Node mergeListNodes(Node n1, Node n2) {
    if (n1 == NULL) {
        return n2;
    }
    if (n2 == NULL) {
        return n1;
    }

    if (n1->data < n2->data) {
        n1->next = mergeListNodes(n1->next, n2);
        return n1;
    } else {
        n2->next = mergeListNodes(n1, n2->next);
        return n2;
    }
}

List mergeListR(List l1, List l2) {
    List l3 = createList();
    l3->first = mergeListNodes(l1->first, l2->first);
    return l3;
}

Node merge = mergeListNodes(n1, n2);

List mergeList(List l1, List l2) {

    List l3 = createList();
    Node currA = l1->first;
    Node currB = l2->first;
    Node curr = NULL;    
    
    if (currA == NULL) {
        l3->first = l2->first;
    } else if (currB == NULL) {
        l3->first = l1->first;
    } else {
        while (currA != NULL && currB != NULL) {
            Node n;

            if (currA->data < currB->data) {
                n = currA;
                currA = currA->next;
            } else {
                n = currB;
                currB = currB->next;
            }

            if (curr == NULL) {
                l3->first = n;
            } else {
                curr->next = n;
            }
            curr = n;
        }

        if (currA != NULL) {
            curr->next = currA;
        } else {
            curr->next = currB;
        }
    }

    return l3;
}
