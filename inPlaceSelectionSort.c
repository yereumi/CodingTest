#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996);

int findMin(int* arr, int n, int idx) {
	int minNum = arr[idx], minIdx = idx;

	for (int i = idx; i < n; i++) {
		if (arr[i] < minNum) {
			minIdx = i;
			minNum = arr[i];
		}
	}
	return minIdx;
}

int main() {
	int n, * arr, minIdx, tmp;
	scanf("%d", &n);

	arr = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n; i++) {
		minIdx = findMin(arr, n, i);
		tmp = arr[i];
		arr[i] = arr[minIdx];
		arr[minIdx] = tmp;
	}

	for (int i = 0; i < n; i++)
		printf(" %d", arr[i]);

	return 0;
}
