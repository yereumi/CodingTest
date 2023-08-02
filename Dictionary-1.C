#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996);

int findElementK();
int rfindElementK(int l, int r);

int* D, n, k;

int main() {
	scanf("%d %d", &n, &k);

	D = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		scanf("%d", &D[i]);
	}

	printf(" %d", findElementK());

	return 0;
}

int findElementK() {
	return rfindElementK(0, n - 1);
}

int rfindElementK(int l, int r) {
	if (l > r)
		return -1;

	int mid = (l + r) / 2;
	//printf("%d\n", D[mid]);

	if (k == D[mid]) {
		return mid;
	}
	else if (k < D[mid]) {
		rfindElementK(l, mid - 1);
	}
	else if (k > D[mid]) {
		if (mid == n - 1)
			return n - 1;
		if (k < D[mid + 1])
			return mid;
		rfindElementK(mid + 1, r);
	}
}
