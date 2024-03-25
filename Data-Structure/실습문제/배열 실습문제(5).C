#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M, X[100][100], num = 1, cnt = 0, i, j;

    scanf("%d %d", &N, &M);

    while (cnt <= N + M - 2) {
        if (cnt >= M)
            i = cnt - M + 1;
        else
            i = 0;
        j = cnt - i;
        
        while (i <= N - 1 && j >= 0) {
            X[i][j] = num;
            i++;
            j--;
            num++;
        }
        cnt++;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf(" %d", X[i][j]);
        }
        printf("\n");
    }

    return 0;
}
