#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M, X[100][100], cnt, i = 0, j = 0;

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++){
            X[i][j] = 0;
        }
    }

    X[0][0] = 1;
    cnt = 2;

    while (cnt <= N * M) {
        while (j < M - 1 && X[i][j + 1] == 0) {
            j++;
            X[i][j] = cnt;
            cnt++;
        }

        while (i < N - 1 && X[i + 1][j] == 0) {
            i++;
            X[i][j] = cnt;
            cnt++;
        }
        
        while (j > 0 && X[i][j - 1] == 0) {
            j--;
            X[i][j] = cnt;
            cnt++;
        }

        while (i > 0 && X[i - 1][j] == 0) {
            i--;
            X[i][j] = cnt;
            cnt++;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf(" %d", X[i][j]);
        }
        printf("\n");
    }

    return 0;
}
