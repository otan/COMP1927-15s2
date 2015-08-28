int map(int *a, int n, int (*f)(int) f) {
    int i;
    for (i = 0; i < n; i++) {
        a[i] = (*f)(a[i]);
    }
}
