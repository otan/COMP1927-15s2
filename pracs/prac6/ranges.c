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
//
// To automark: run ./mark

#include <stdio.h>
#include <stdlib.h>

// Print out the ranges in here!
void printRanges(int arr[], int n) {
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
