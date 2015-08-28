#include <stdio.h>

int main(int argc, char *argv[]) {
    int i;
    printf("would you be so kind as to give me a number? ");
    scanf("%d", &i);
    printf("okay, %d\n", i);
    printf("%d\n", argc);
    for (i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
    return 0;
}
