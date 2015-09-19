/* Graph is an unsymmetric/directed Graph - in other words
 * Vertex "a" can connect to Vertex "b", not not necessarily the
 * other way around.
 * Note: THERE CAN BE MULTIPLE EDGES FROM ONE TO ANOTHER
 *
 * complete "inDegree", which finds how many Vertices in the Graph
 * connect to vertex "to"
 *
 * testGraph: gcc -Wall -Werror -O -o testGraph testGraph.c Graph.c
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "Graph.h"

Graph initGraph(int nV) {
    Graph g = malloc(sizeof(*g));
    g->edges = calloc(sizeof(VNode), nV);
    g->nV = nV;
    return g;
}

void destroyGraph(Graph g) {
    free(g->edges);
    free(g);
}

void printGraph(Graph g) {
    int i;
    for (i = 0; i < g->nV; i++) {
        printf("Edge %d:", i);
        VNode *curr = g->edges[i];
        while (curr != NULL) {
            printf(" [%d]", curr->v);
            curr = curr->next;
        }
        printf("\n");
    }
}

void insertEdge(Graph g, Vertex from, Vertex to) {
    VNode *n = malloc(sizeof(*n));
    n->v = to;
    n->next = g->edges[from];
    g->edges[from] = n;
}

int inDegree(Graph g, Vertex to) {
    int count = 0;
    int i = 0;
    for (i = 0; i < g->nV; i++) { 
        VNode *curr = g->edges[i];
        while (curr != NULL) {
            if (curr->v == to) {
                count++;
            }
            curr = curr->next;
        }
    }
    return count;
}
