int isEulerPath(Graph g, Edge e[], int nE) {
    /*int **visited = malloc(sizeof(int*) * g->nV);
    int y;
    for (y = 0; y < g->nV; y++) {
        visited[y] = calloc(sizeof(int), g->nV);
    }*/
    Graph g2 = cloneGraph(g);
    int i;
    for (i = 0; i < nE; i++) {
        if (isEdge(g, e[i].v, e[i].w)) {
            deleteEdge(g, e[i].v, e[i].w);
        } else {
            freeGraph(g2);
            return 0;
        }
    }
    int numRemaining = g2->nE;
    freeGraph(g2);
    return numRemaining == 0;
}
