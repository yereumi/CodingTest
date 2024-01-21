#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996);

int* H, n;

void rBuildHeap(int idx);
void buildHeap(int idx);
void downHeap(int idx);
int isExternal(int idx);
void printHeap();
void swap(a, b);
int leftChild(int idx);
int rightChild(int idx);

int main() {
	H = (int*)malloc(100 * sizeof(int));

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &H[i]);
	}

	rBuildHeap(1);
	//buildHeap(1);

	for (int i = 1; i <= n; i++) {
		printf(" %d", H[i]);
	}

	free(H);

	return 0;
}

void rBuildHeap(int idx) {
	if (isExternal(idx))
		return;

	rBuildHeap(leftChild(idx));
	rBuildHeap(rightChild(idx));
	downHeap(idx);

	return;
}

void buildHeap(int idx) {
	for (int i = n / 2; i > 0; i--) {
		downHeap(i);
	}

	return;
}

void downHeap(int idx) {
	int tmpN = idx, bigger;

	if (isExternal(leftChild(tmpN)) && isExternal(rightChild(tmpN)))
		return;

	// left는 무조건 internal 이다.
	bigger = leftChild(tmpN);

	if (!isExternal(rightChild(tmpN))) {
		if (H[rightChild(tmpN)] > H[bigger])
			bigger = rightChild(tmpN);
	}

	if (H[tmpN] > H[bigger])
		return;

	swap(tmpN, bigger);
	downHeap(bigger);
}

int isExternal(int idx) {
	if (idx > n)
		return 1;
	return 0;
}

void printHeap() {
	if (n > 0) {
		for (int i = 1; i <= n; i++) {
			printf(" %d", H[i]);
		}
	}
	printf("\n");
}

void swap(a, b) {
	int tmp;

	tmp = H[a];
	H[a] = H[b];
	H[b] = tmp;
}

int leftChild(int idx) {
	return idx * 2;
}

int rightChild(int idx) {
	return idx * 2 + 1;
}
