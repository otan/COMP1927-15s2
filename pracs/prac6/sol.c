// Interview question seen before on glassdoor.
//
// Complete "printRanges", which, given a sorted array of numbers, print them, 
//    line by line, as ranges. 
//
// Example 1: given {1,2,3,5,7,8,9,11}, print:
// 1-3
// 5
// 7-9
// 11
//
// Example 2: given {1,5,11}, print:
// 1
// 5
// 11
//
// Example 3: given {1,2,3,4,5,6,7,8,9,10}, print:
// 1-10
//
// Test cases are in tests/, with *.in meaning input, and *.out the corresponding output.
//     In input, the first number is the number of elements, followed by all the elements.
//     e.g., for {1,5,11,14}, the file is structured 4 1 5 11 14

#include <stdio.h>
#include <stdlib.h>

// Print out the ranges in here!
void output(int start, int curr) {
    printf("%d", start);
    if (curr - start > 0) {
        printf("-%d", curr);
    }
    printf("\n");
}

void printRanges(int arr[], int n) {
    int i;
    if (n <= 0) {
        return;
    }
    int start = arr[0];
    int curr = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] != curr + 1) {
            output(start, curr);
            start = arr[i];
        }
        curr = arr[i];
    }
    output(start, curr);
}

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    int i;
    int arr[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printRanges(arr, n);
    return EXIT_SUCCESS;
}
