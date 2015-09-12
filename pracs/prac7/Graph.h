#ifndef _GRAPH_H_
#define _GRAPH_H_

typedef int Vertex;

typedef struct _VNode *VList;

typedef struct _VNode {
    Vertex v;
    struct _VNode *next;
} VNode;

typedef struct _graph *Graph;

typedef struct _graph {
    VList *edges;
    int nV;
} graph;

Graph initGraph(int nV);
void destroyGraph(Graph g);
void printGraph(Graph g);
void insertEdge(Graph g, Vertex from, Vertex to);
int inDegree(Graph g, Vertex to);

#endif
