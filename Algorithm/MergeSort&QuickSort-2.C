#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996);

void print(int* A);
void swap(int* A, int a, int b);
void inPlaceQuickSort(int* A, int l, int r);
int* inPlacePartition(int* A, int l, int r, int k);
int findPivot(int* A, int l, int r);

int* P, n;

int main() {
	int* A, e;

	scanf("%d", &n);

	A = (int*)malloc(n * sizeof(int));
	P = (int*)malloc(2 * sizeof(int)); // inPlacePartition return값

	for (int i = 0; i < n; i++) {
		scanf("%d", &e);
		A[i] = e;
	}

	inPlaceQuickSort(A, 0, n - 1);

	print(A);

	return 0;
}

void print(int* A) {
	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);

	return;
}

void swap(int* A, int a, int b) {
	int tmp;

	tmp = A[a];
	A[a] = A[b];
	A[b] = tmp;

	return;
}

void inPlaceQuickSort(int* A, int l, int r) {
	//printf("QuickSort\n");
	int k, a, b;

	if (l >= r)
		return;

	k = findPivot(A, l, r);

	inPlacePartition(A, l, r, k);
	a = P[0];
	b = P[1];

	inPlaceQuickSort(A, l, a - 1);
	inPlaceQuickSort(A, b + 1, r);

	return;
}

int* inPlacePartition(int* A, int l, int r, int k) {
	//printf("Partition\n");
	int p, i, j;
	p = A[k];

	swap(A, k, r);
	i = l;
	j = r - 1;

	while (i <= j) {
		//printf("%d %d\n", i, j);
		while (i <= j && A[i] <= p)
			i += 1;
		while (j >= i && A[j] >= p)
			j -= 1;
		if (i < j)
			swap(A, i, j);
	}
	swap(A, i, r);

	P[0] = i;
	P[1] = i;

	return;
}

int findPivot(int* A, int l, int r) {
	int num;

	srand(time(NULL));
	num = rand() % (r - l + 1) + l;
	//printf("%d\n", A[num]);
	return num;
}
