/*
 * Test by Oliveer Tan (otan@cse.unsw.edu.au);
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "Graph.h"

#define VERTICES 30
#define EDGES 40
#define ITERATIONS 20

void testInDegree(void) {
    int i, j;
    for (i = 0; i < ITERATIONS; i++) {
        Graph g = initGraph(VERTICES);
        int tos[VERTICES];
        
        memset(tos, 0, sizeof(int) * VERTICES);
        for (j = 0; j < EDGES; j++) {
            int f = rand() % VERTICES;
            int t = rand() % VERTICES;
            insertEdge(g, f, t);
            tos[t]++;
        }
        
        printf("Graph we are testing on:\n");
        printGraph(g);
        printf("*****************\n");
        for (j = 0; j < VERTICES; j++) {
            printf(" > testing %d has inDegree %d\n", j, tos[j]);
            assert(inDegree(g, j) == tos[j]);
        }
        destroyGraph(g);
        printf("================================================\n");
    }
}

int main(void) {
    srand(1927);
    testInDegree();
    printf("i am satisfied with your function. congratulations. asian father approves.\n");
    return 0;
}
