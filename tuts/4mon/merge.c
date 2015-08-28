Node mergeListNode(Node currA, Node currB) {
    if (currA == NULL) {
        return currB;
    }
    if (currB == NULL) {
        return currA;
    }
    if (currA->data > currB->data) {
        currB->next = mergeListNode(currA, currB->next);
        return currB;
    }
    currA->next = mergeListNode(currA->next, currB);
    return currA;
}

List mergeListR(List l1, List l2) {
    List l3 = createList();
    l3->first = mergeListNode(l1->first, l2->first);
    return l3;
}

List mergeList(List l1, List l2) {
    Node currA = l1->first;
    Node currB = l2->first;

    List l3 = createList();
    Node curr = NULL;

    if (l1->first == NULL) {
        l3->first = l2->first;
    } else if (l2->first == NULL) {
        l3->first = l1->first;
    } else {
        while (currA != NULL && currB != NULL) {
            Node n = currA;
            if (currA->data > currB->data) {
                n = currB;
                currB = currB->next;
            } else {
                currA = currA->next;
            }
            
            if (l3->first == NULL) {
                l3->first = n;
            } else {
                curr->next = n;
            }
            curr = n;
        }

        if (currA == NULL) {
            curr->next = currB;
        } else {
            curr->next = currA;
        }
    }

    return l3;
}
