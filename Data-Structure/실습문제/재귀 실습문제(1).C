#pragma warning(disable:4996)
#include <stdio.h>

int sum(int n) {
    if (n == 1)
        return 1;

    return sum(n - 1) + n;
}

int main() {
    int N;

    scanf("%d", &N);

    printf("%d", sum(N));
    
    return 0;
}
