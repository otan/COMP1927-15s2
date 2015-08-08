#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

#define NIGEL_THORNBERRY 10
#define SMASHING 10
#define NYAGH 1000

void randomArray(int nums[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        nums[i] = rand() % NYAGH;
    }
}

void printArray(int nums[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

void printList(List l) {
    Node curr;
    for (curr = l->first; curr != NULL; curr = curr->next) {
        printf("[%d]->", curr->data);
    }
    printf("[X]\n");
}

int main(int argc, char *argv[]) {
    int t, n, i;
    srand(0);
    
    for (n = 0; n <= NIGEL_THORNBERRY; n++) {
        printf("* Testing %d item lists.\n", n);
        for (t = 0; (t < SMASHING && n > 0) || (t < 1); t++) {
            int nums[n];
            randomArray(nums, n);

            printf("** Test #%d of %d item list\n", t+1, n);
            printf("*** Array: ");
            printArray(nums, n);
            printf("*** Running initList. Failure here indicates seg fault in initList\n");
            fflush(stdout);

            List test = initList(nums, n);
            printf("*** Returned list: ");
            printList(test);
            printf("*** Testing. Failure here means your function returned the wrong thing.\n");
            fflush(stdout);

            Node curr = test->first;
            for (i = 0; i < n; i++, curr = curr->next) {
                assert(curr != NULL);
                assert(curr->data == nums[i]);
            }
            assert(curr == NULL);

            printf("** Passed Test #%d of %d item lists.\n", t+1, n);
        }
    }

    printf("* All tests passed! Asian father approves.\n");
    return EXIT_SUCCESS;
}
