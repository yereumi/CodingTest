#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, * X, change, * C, a, b, tmp;

    scanf("%d", &N);

    X = (int*)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
        scanf("%d", X + i);

    scanf("%d", &change);

    C = (int*)malloc(change * sizeof(int));

    for (int i = 0; i < change; i++)
        scanf("%d", C + i);

     for (int j = change - 1; j > 1; j--) {
            a = C[j];
            b = C[j - 1];

            tmp = X[a];
            X[a] = X[b];
            X[b] = tmp;
    }

    for (int i = 0; i < N; i++)
        printf(" %d", X[i]);
    printf("\n");

    free(X);
    free(C);

    return 0;
}
