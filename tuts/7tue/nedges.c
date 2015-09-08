int nEdges(Graph g) {
    int x, y;
    int edges = 0;
    for (y = 0; y < g->nV; y++) {
        for (x = 0; x <= y; x++) {
            if (g->edges[y][x] > 0) {
                edges++;
            }
        }
    }
    return edges;
}
