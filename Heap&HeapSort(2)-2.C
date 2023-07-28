#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996);

int* H, n;

void inPlaceHeapSort();
void insertItem(int idx, int k);
void upHeap(int idx);
void downHeap(int idx, int last);
int isExternal(int idx);
void printHeap();
void swap(a, b);
int parent(int idx);
int leftChild(int idx);
int rightChild(int idx);

int main() {
	// 삽입식
	int num;
	scanf("%d", &n);

	H = (int*)malloc((n + 1) * sizeof(int));

	for (int i = 1; i <= n; i++) {
		scanf("%d", &num);
		// 1기
		insertItem(i, num);
	}	

	inPlaceHeapSort();

	printHeap();

	free(H);

	return 0;
}

void insertItem(int idx, int k) {
	H[idx] = k;
	upHeap(idx);
	return;
}

void upHeap(int idx) {
	if (idx <= 1)
		return;

	if (H[idx] < H[parent(idx)])
		return;

	swap(idx, parent(idx));
	upHeap(parent(idx));

	return;
}

void inPlaceHeapSort() {
	// 2기
	for (int i = n; i > 1; i--) {
		swap(1, i);
		downHeap(1, i - 1);
	}

	return;
}

void downHeap(int idx, int last) {
	int tmpN = idx, greater;

	if (leftChild(tmpN) > last)
		return;

	// left는 무조건 internal 이다.
	greater = leftChild(tmpN);

	if (rightChild(tmpN) <= last) {
		if (H[rightChild(tmpN)] >= H[greater])
			greater = rightChild(tmpN);
	}

	if (H[tmpN] >= H[greater])
		return;

	swap(tmpN, greater);
	downHeap(greater, last);
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

int parent(int idx) {
	return idx / 2;
}

int leftChild(int idx) {
	return idx * 2;
}

int rightChild(int idx) {
	return idx * 2 + 1;
}
