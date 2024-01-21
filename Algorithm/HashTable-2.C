#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996);

int* H; // 해쉬 테이블 정의
int M; // 버킷 크기 전역변수로 정의

int hash(int k) { // 해쉬 함수
	return k % M;
}

void findElement(int k) { // 키값이 k인 버킷을 찾는 함수
	for (int i = 0; i < M; i++) { // 배열 H 순회
		if (H[i] == k) { 
			printf("%d %d\n", i, k);
			return;
		}
	}

	printf("-1");
	return;
}

void insertItem(int k) { // 배열 H에 키 k를 삽입하는 함수
	int h = hash(k); // 해쉬값 h에 저장

	while (H[h] != 0) { // 빈 버킷이 아닐 때까지 순회
		printf("C");
		h = (h + 1) % M; // h값 업데이트
	}

	H[h] = k;
	printf("%d\n", h);

	return;
}

int main() {
	char f;
	int n, k;

	scanf("%d %d", &M, &n); getchar();

	H = (int*)malloc(M * sizeof(int));
	for (int i = 0; i < M; i++) {
		H[i] = 0;
	}

	while (1) {
		scanf("%c", &f); getchar();

		if (f == 'e')
			break;
		if (f == 'i') {
			scanf("%d", &k); getchar();
			insertItem(k);
		}
		if (f == 's') {
			scanf("%d", &k); getchar();
			findElement(k);
		}
	}

	return 0;
}
