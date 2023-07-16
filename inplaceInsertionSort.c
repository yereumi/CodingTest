#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996);

int* sort(int* arr, int idx) {
	int num = arr[idx], j = idx - 1;

	for (int i = 0; i < idx; i++) {
		while (j >= 0 && num < arr[j]) {
			arr[j+1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = num;
	}
	return arr;
}

int main() {
	int n, * arr;
	scanf("%d", &n);

	arr = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 1; i < n; i++) {
		arr = sort(arr, i);
	}

	for (int i = 0; i < n; i++)
		printf(" %d", arr[i]);

	return 0;
}
