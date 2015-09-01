#include <stdio.h>
#include <stdlib.h>

int fib(int n) {
    int arr[n+1];
    if (n <= 2) {
        return 1;
    }
    arr[1] = 1;
    arr[2] = 2;
    for (i = 3; i <= n; i++) {
        arr[i] = arr[i-1] - arr[i-2];
    }
    return arr[n];:
}
int main(void) {
    
    return 0;
}
