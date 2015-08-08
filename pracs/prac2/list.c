/* 
 * Complete initList, which, given an array of n numbers
 * initialises a linked list with those elements.
 *
 * e.g. initList({2,3,4}, 3) returns linked list [2]->[3]->[4]->[X]
 * compile: gcc -Wall -Werror -O -o list list.c testList.c
 * test: ./list
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
List initList(int nums[], int n) {
    List l = createList();
    
    return l;
}
