#pragma warning(disable:4996)
#include <stdio.h>

int gcd(int a, int b) {
    int r;

    if (b == 0) {
        return a;
    }
    
    r = a % b;
    a = b;
    b = r;

    return(gcd(a, b));
}

int main() {
    int a, b;

    scanf("%d %d", &a, &b);

    printf("%d", gcd(a, b));

    return 0;
}
