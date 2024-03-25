#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, * X, change, a, b, tmp;

    scanf("%d", &N);

    X = (int*)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
        scanf("%d", X + i);

    scanf("%d", &change);

    for (int i = 0; i < change; i++){
        scanf("%d %d", &a, &b);

        for (int j = 0; j < (b - a + 1) / 2; j++) {
            tmp = X[a + j];
            X[a + j] = X[b - j];
            X[b - j] = tmp;
        }
    }

    for (int i = 0; i < N; i++)
        printf(" %d", X[i]);

    free(X);
    
    return 0;
}
