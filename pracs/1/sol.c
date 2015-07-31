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
    int sorted = 1;
    Node curr = l->first;
    Node prev = NULL;
    for (curr = l->first; curr != NULL; prev = curr, curr = curr->next) {
        if (prev) {
            sorted &= (curr->data >= prev->data);
        }
    }
    return sorted;
}

