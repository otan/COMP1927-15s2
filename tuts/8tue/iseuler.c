int hasEulerTour(Graph g) {
    int i;
    for (i = 0; i < g->nV; i++) {
        VLink curr = g->edges[i];
        int count = 0;
        while (curr != NULL) {
            count++;
            curr = curr->next;
        }
        if (count % 2 != 0) {
            return 0;
        }
    }
    return 1;
}

int hasEulerPath(Graph g) {
    int i;
    int counter = 0;
    for (i = 0; i < g->nV && counter <= 2; i++) {
        VLink curr = g->edges[i];
        int count = 0;
        while (curr != NULL) {
            count++;
            curr = curr->next;
        }
        if (count % 2 != 0) {
            counter++;
        }
    }
    return (counter == 2) || (counter == 0);
}
