/* This is an edited interview question found on glassdoor.
 * There are three parts.
 *
 * Part 1) Do a deep copy of a linked list. You do not have to take care of
 *         the random pointer.
 *         (Deep copy = make a copy of each node into a new list)
 *         IF YOU CAN'T DO THIS AT THIS POINT, YOU **REALLY** NEED TO REVISE.
 *
 * Part 2) Each node in the linked list has a random pointer, which
 *         points to a random node in the new linked list. Extend the first
 *         part such that the deep copied linked list's nodes' random pointer
 *         points to the correct node in the duplicated list.
 *
 *         Note random can point to NULL.
 *
 * Part 3) Make part 2 as efficient as possible. 
 *         - C++ can be used for a efficient solution, but won't produce the one
 *           with most!
 *
 * compile: gcc -Wall -Werror -O -o list list.c testList.c
 * test: ./list
 */

#include <stdio.h>
#include <stdlib.h>

#include <ctype.h>
#include "list.h"

/* do you want the program to work? if so, don't change this */
Node createNode(int i) {
    Node n = malloc(sizeof(struct _node));
    n->next = NULL;
    n->random = NULL;
    n->data = i;
    return n;
}

/* but do change this! */
Node cloneList(Node first) {

    return NULL;
}
