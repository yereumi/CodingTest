#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996);

int* H, n;

void insertItem(int k);
int removeMax();
void upHeap();
void downHeap(int idx);
int isExternal(int idx);
void printHeap();
void swap(a, b);
int leftChild(int idx);
int rightChild(int idx);

int main() {
	int k;
	char order;

	H = (int*)malloc(100 * sizeof(int));

	while (1) {
		scanf("%c", &order); getchar();

		if (order == 'i') {
			scanf("%d", &k); getchar();
			insertItem(k);
		}
		if (order == 'd') {
			printf("%d\n", removeMax());
		}
		if (order == 'p') {
			printHeap();
		}
		if (order == 'q')
			break;
	}

	free(H);

	return 0;
}

void insertItem(int k) {
	n += 1;
	H[n] = k;
	upHeap();
	printf("0\n");
	return;
}

int removeMax() {
	int key;
	key = H[1];
	H[1] = H[n];
	n -= 1;
	downHeap(1);

	return key;
}

void upHeap() {
	int tmpN = n, upN = tmpN / 2, tmp;

	while (upN > 0) {
		if (H[tmpN] > H[upN]) {
			swap(tmpN, upN);
		}
		tmpN /= 2;
		upN = tmpN / 2;
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
