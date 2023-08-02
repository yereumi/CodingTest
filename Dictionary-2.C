#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996);

int findElementK(int l, int r);

int* D, n, k;

int main() {
	scanf("%d %d", &n, &k);

	D = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		scanf("%d", &D[i]);
	}

	printf(" %d", findElementK(0, n - 1));

	return 0;
}

int findElementK(int l, int r) {
	int mid;

	while (l <= r) {
		mid = (l + r) / 2;

		if (k == D[mid]) {
			return mid;
		}
		else if (k > D[mid]) {
			l = mid + 1;
		}
		else if (k < D[mid]) {
			if (mid == 0) {
				return 0;
			}
			if (k > D[mid - 1])
				return mid;
			r = mid - 1;
		}
	}

	return n;
}
