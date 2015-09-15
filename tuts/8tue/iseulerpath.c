int isEulerPath(Graph g, Edge e[], int nE) {
    if (nE != g->nE) {
        return 0;
    }

    // check edge exists
    int i, j;
    for (i = 0; i < nE; i++) {
        if (!isEdge(g, e.v, e.w)) {
            return 0;
        }
    }
    // checking edge is not repeated
    for (i = 0; i < nE; i++) {
        for (j = 0; j < i; j++) {
            if (e[i].v == e[j].v && e[i].w == e[j].w) {
                return 0;
            }
        }
    }
    return 1;
}
