#include <stdio.h>
#include <stdlib.h>

int main(void) {
    double a = 0.0001;
    double b = 1.0;
    b -= 0.9999;
    printf("%lf %lf ? %d\n", a, b, a == b);
    return 0;
}
