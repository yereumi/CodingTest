#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int* prefixAverages1(int* X, int n) {
    int* A = (int*)malloc(n * sizeof(int));
    if (A == NULL)
        return -1;

    int sum;

    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = 0; j <= i; j++) {
            sum += X[j];
        }
        A[i] = (float)sum / (i + 1) + 0.5;
        
    }

    return A;
}

int* prefixAverages2(int* X, int n) {
    int* A = (int*)malloc(n * sizeof(int));
    if (A == NULL)
        return -1;

    int sum = X[0];

    A[0] = X[0];

    for (int i = 1; i < n; i++) {
        sum += X[i];
        A[i] = (float)sum / (i + 1) + 0.5;
    }

    return A;
}

int main() {
    int *X, n;
    int *A1, *A2;
    
    scanf("%d", &n);

    X = (int*)malloc(n * sizeof(int));
    if (X == NULL)
        return -1;

    for (int i = 0; i < n; i++){
        scanf("%d", &X[i]);
    }

    A1 = prefixAverages1(X, n);
    A2 = prefixAverages2(X, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", A1[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A2[i]);
    }

    free(X);
    free(A1);
    free(A2);

    return 0;
}

/* 3-2

#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int* prefixAverages1(int* X, int n) {
    int* A = (int*)malloc(n * sizeof(int));
    if (A == NULL)
        return -1;

    int sum;

    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = 0; j <= i; j++) {
            sum += X[j];
        }
        A[i] = (float)sum / (i + 1) + 0.5;

    }

    return A;
}

int* prefixAverages2(int* X, int n) {
    int* A = (int*)malloc(n * sizeof(int));
    if (A == NULL)
        return -1;

    int sum = X[0];

    A[0] = X[0];

    for (int i = 1; i < n; i++) {
        sum += X[i];
        A[i] = (float)sum / (i + 1) + 0.5;
    }

    return A;
}

int main() {
    int* X, n;
    int* A1, * A2;

    LARGE_INTEGER ticksPerSec;
    LARGE_INTEGER start, end, diff;

    scanf("%d", &n);

    X = (int*)malloc(n * sizeof(int));
    if (X == NULL)
        return -1;

    for (int i = 0; i < n; i++) {
        X[i] = rand() % 10000 + 1;
        //printf("%d\n", X[i]);
    }


    // A1
    QueryPerformanceFrequency(&ticksPerSec);
    QueryPerformanceCounter(&start);
    A1 = prefixAverages1(X, n);
    QueryPerformanceCounter(&end);

    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("time: %.12f sec\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
    
    // A2
    QueryPerformanceFrequency(&ticksPerSec);
    QueryPerformanceCounter(&start);
    A2 = prefixAverages2(X, n);
    QueryPerformanceCounter(&end);

    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("time: %.12f sec\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

    free(X);
    free(A1);
    free(A2);

    return 0;
}
*/
