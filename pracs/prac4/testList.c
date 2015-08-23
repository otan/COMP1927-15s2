#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

#define FRY 10
#define BENDER 5
#define LEELA 1927
#define HERMES 1000

Node createList(int *arr, int num) {
    Node first = NULL;
    Node curr = NULL;
    
    Node arrayOrder[num];

    int i;
    for (i = 0; i < num; i++) {
        Node n = createNode(arr[i]);
        if (first == NULL) {
            first = n;
        } else {
            curr->next = n;
        }
        curr = n;
        arrayOrder[i] = curr;
    }

    for (curr = first; curr != NULL; curr = curr->next) {
        int r = rand() % (num + 1);
        if (r != num) {
            curr->random = arrayOrder[r];
        }
    }

    return first;
}

void printList(Node n) {
    for (; n != NULL; n = n->next) {
        printf("[%d]->", n->data);
    }
    printf("[X]\n");
}

void testList(int *arr, int num, int partTwo) {
    Node n = createList(arr, num);
    printf("*** Testing List:                            ");
    printList(n);

    printf("**** Applying function...failure here = seg fault in your code.\n");
    fflush(stdout);
    Node copy = cloneList(n);

    printf("**** Existing List, after your pass through: ");
    printList(n);
    fflush(stdout);

    printf("**** New List, after your pass through:      ");
    printList(copy);
    fflush(stdout);

    printf("**** Testing existing list is still the same.\n");
    Node curr = n;
    int i;
    for (i = 0; i < num; i++) {
        assert(curr != NULL);
        assert(curr->data == arr[i]);
        curr = curr->next;
    }
    assert(curr == NULL);

    printf("**** Testing new list copied successfully.\n");
    Node newCurr = copy;
    curr = n;
    for (i = 0; i < num; i++) {
        assert(newCurr != NULL);
        assert(newCurr != curr);
        assert(newCurr->data = arr[i]);
        if (partTwo) {
            if (curr->random == NULL) {
                assert(newCurr->random == NULL);
            } else {
                assert(curr->random != newCurr->random);
                assert(curr->random->data == newCurr->random->data);
            }
        }
        curr = curr->next;
        newCurr = newCurr->next;
    }
    assert(curr == NULL);
    assert(newCurr == NULL);
    
    printf("*** Test passed.\n");
}

void runTests(int partTwo) {
    printf("** Testing no item list.\n");
    testList(NULL, 0, partTwo);

    int num;
    int t;
    for (num = 1; num < FRY; num++) {
        printf("** Testing %d item lists.\n", num);
        for (t = 0; t < BENDER; t++) {
            int arr[num];
            int i;
            for (i = 0; i < num; i++) {
                arr[i] = rand() % HERMES;
            }
            testList(arr, num, partTwo);
        }
        printf("** Passed all tests for %d item lists.\n", num);
    }
}

int main(int argc, char *argv[]) {
    srand(LEELA);

    printf("* Testing part one...\n");
    runTests(FALSE);
    printf("* Passed part one! That's meh for me.\n");

    printf("* Testing part two...\n");
    runTests(TRUE);
    
    printf("* All tests passed! Asian father approves if your solution is efficient.\n");
    return EXIT_SUCCESS;
}
