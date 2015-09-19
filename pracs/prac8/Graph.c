// Graph.c ... implementation of Graph ADT
// Written by John Shepherd, May 2013

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "Graph.h"
#include "Queue.h"

// graph representation (adjacency matrix)
typedef struct GraphRep {
	int    nV;    // #vertices
	int    nE;    // #edges
	int  **edges; // matrix of weights (0 == no edge)
} GraphRep;

// check validity of Vertex
int validV(Graph g, Vertex v)
{
	return (g != NULL && v >= 0 && v < g->nV);
}

// make an edge
Edge mkEdge(Graph g, Vertex v, Vertex w)
{
	assert(g != NULL && validV(g,v) && validV(g,w));
	Edge new = {v,w}; // struct assignment
	return new;
}

// insert an Edge
// - sets (v,w) and (w,v)
void insertEdge(Graph g, Vertex v, Vertex w, int wt)
{
	assert(g != NULL && validV(g,v) && validV(g,w));
	if (g->edges[v][w] == 0) {
		g->edges[v][w] = wt;
		g->edges[w][v] = wt;
		g->nE++;
	}
}

// remove an Edge
// - unsets (v,w) and (w,v)
void removeEdge(Graph g, Vertex v, Vertex w)
{
	assert(g != NULL && validV(g,v) && validV(g,w));
	if (g->edges[v][w] != 0) {
		g->edges[v][w] = 0;
		g->edges[w][v] = 0;
		g->nE--;
	}
}

// create an empty graph
Graph newGraph(int nV)
{
    Graph g = malloc(sizeof(*g));
    g->nV = nV;
    g->nE = 0;
    g->edges = malloc(sizeof(int*) * nV);
    int i;
    for (i = 0; i < g->nV; i++) {
        g->edges[i] = calloc(nV, sizeof(int));
    }
    return g; // dummy ... doesn't create an empty graph
}

// free memory associated with graph
void dropGraph(Graph g)
{
	assert(g != NULL);
    int i;
    for (i = 0; i < g->nV; i++) {
        free(g->edges[i]);
    }
    free(g->edges);
    free(g);
}

// display graph, using names for vertices
void showGraph(Graph g, char **names)
{
	assert(g != NULL);
	printf("#vertices=%d, #edges=%d\n\n",g->nV,g->nE);
	int v, w;
	for (v = 0; v < g->nV; v++) {
		printf("%d %s\n",v,names[v]);
		for (w = 0; w < g->nV; w++) {
			if (g->edges[v][w]) {
				printf("\t%s (%d)\n",names[w],g->edges[v][w]);
			}
		}
		printf("\n");
	}
}


void populateSt(Graph g, Vertex src, int max, int *st)
{
	assert(g != NULL && validV(g,src));

    Edge e = mkEdge(g, src, src);
    int i;
    for (i = 0; i < g->nV; i++)
    { st[i] = -1; }
    Queue q = newQueue();
    QueueJoin(q,e);
    while (!QueueIsEmpty(q)) {
        Edge e = QueueLeave(q);
        st[e.w] = e.v;
        Vertex v;
        for (v = 0; v < g->nV; v++) {
            if (g->edges[e.w][v] <= 0 || g->edges[e.w][v] >= max) continue;
            if (st[v] == -1) {
                QueueJoin(q, mkEdge(g,e.w,v));
            }
        }
    }
    dropQueue(q);
}
