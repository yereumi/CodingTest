#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int mostOnes(int **A, int n){
    int i, j = 0;
    int max_1 = 0, max_row = i;
    // max_1: 최대 1의 개수, max_row: 최대 1행 번호

    for (i = 0; i < n; i++) { // 수직 이동
        //  printf("i: %d\n", i);

        int doUpate = 0;
        if (j < n) {
            while (A[i][j] == 1) {
                doUpate = 1;
                j++;
            }
        }
        // printf("j: %d\n", j);

        if (doUpate) {
            max_row = i;
        }

        // printf("%d %d\n", max_1, max_row);
    }

    return max_row;
}

int main() {
    int **A, n;

    scanf("%d", &n);

    A = (int**)malloc(n * sizeof(int*));
    if (A == NULL)
        return -1;

    for (int i = 0; i < n; i++) {
        A[i] = (int*)malloc(n * sizeof(int));
        if (A[i] == NULL)
            return -1;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            scanf("%d", &A[i][j]);
        }
    }

    printf("%d", mostOnes(A, n));

    for (int i = 0; i < n; i++) {
        free(A[i]);
    }
    free(A);
    
    return 0;
}
