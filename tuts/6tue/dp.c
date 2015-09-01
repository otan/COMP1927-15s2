#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NUM_CASH 7

int notes[NUM_CASH] = {1, 2, 5, 10, 20, 50, 100};

int least_amount_of_cash_r(int n) {
    if (n == 0) {
        return 0;
    }
    int i = 0;
    for (i = 0; i < NUM_CASH; i++) {
        if (notes[i] == n) {
            return 1;
        }
    }
    int min = INT_MAX;
    for (i = 0; i < NUM_CASH; i++) {
        if (n - notes[i] < 0) {
            break;
        }
        int curr = 1 + least_amount_of_cash_r(n - notes[i]);
        if (min > curr) {
            min = curr;
        }
    }
    return min;
}

int least_amount_of_cash_dp(int n) {
    int array[n+1];
    array[0] = 0;
    int i;
    for (i = 1; i <= n; i++) {
        int min = INT_MAX;
        int j;
        for (j = 0; j < NUM_CASH; j++) {
            if (i == notes[j]) {
                min = 1;
                break;
            }
            if (i - notes[j] < 0) {
                break;
            }
            int curr = 1 + array[i - notes[j]];
            if (min > curr) {
                min = curr;
            }
        }
        array[i] = min;
    }
    return array[n];
}

int main(int argc, char *argv[]) {
    printf("%d\n", least_amount_of_cash_r(1927));

    return 0;
}
