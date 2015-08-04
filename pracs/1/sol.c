/* 
 * COMP1927 13s2 prac exam question! so you should be able to do it!
 * Test files by Oliver Tan (otan@cse.unsw.edu.au)
 *
 * complete isSorted, which checks whether a linked list is sorted in
 *    ascending order. Note "1 1" is considered sorted (so really, >= prev).
 *
 * note there is createNode/createList to help you (do they help?)
 *
 * Compile: gcc -Wall -Werror -O -o testList testList.c list.c
 * Run: ./testList
*     
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* do you want the program to work? if so, don't change this */
Node createNode(int i) {
    Node n = malloc(sizeof(struct _node));
    n->next = NULL;
    n->data = i;
    return n;
}

/* ... or this */
List createList(void) {
    List l = malloc(sizeof(*l));
    l->first = NULL;
    return l;
}

/* but do change this! */
int isSorted(List l) {
    // 0-1 item lists always sorted
    if (l->first == NULL || l->first->next == NULL) {
        return 1;
    }
    Node curr = l->first->next, prev = l->first;
    while (curr != NULL) {
        // make sure it is bigger than previous
        if (curr->data < prev->data) {
            return 0;
        }
        prev = curr;
        curr = curr->next;
    }
    return 1;
}

