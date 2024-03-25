#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, ** X;

    scanf("%d", &N);

    X = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++)
        X[i] = (int*)malloc(N * sizeof(int));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i % 2 == 0) { // 인덱스가 짝수 행이면
                X[i][j] = i * N + j + 1;
            }
            else { // 인덱스가 홀수 행이면
                X[i][N - j - 1] = i * N + j + 1;
            }
        }

        for (int j = 0; j < N; j++)
            printf(" %d", X[i][j]);
        printf("\n");
    }

    for (int i = 0; i < N; i++)
        free(X[i]);
    free(X);

    return 0;
}
