#include <stdio.h>

void printBinary(unsigned int num) {
    int i;
    for (i = 0; i < 32; i++) {
        if (num & (1 << (31 - i))) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    printBinary(atoi(argv[1]));
    return 0;
}
