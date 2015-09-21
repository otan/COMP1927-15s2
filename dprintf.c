#include <stdio.h>

#define DEBUG 1

#ifdef DEBUG
#define dprintf(x...) printf(x)
#else
#define dprintf(x...)
#endif

int main(void) {
    dprintf("hi");
    return 0;
}
