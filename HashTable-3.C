#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996);

int* H; // 해시 테이블 정의
int M, q; 
// 버킷 크기 전역변수로 정의, M보다 조금 작은 소수(두 번쨰 해시 함수에서 사용) 

int hash(int k) { // 첫 번째 해시 함수
	return k % M;
}

int hash2(int k) { // 두 번째 해시 함수
	return q - (k % q);
}

void findElement(int k) { // 키값이 k인 버킷을 찾는 함수
	for (int i = 0; i < M; i++) { // 배열 H 순회
		if (H[i] == k) { 
			printf("%d %d\n", i, k);
			return;
		}
	}

	printf("-1\n");
	return;
}

void insertItem(int k) { // 배열 H에 키 k를 삽입하는 함수
	int h = hash(k); // 해시값 h에 저장

	if (H[h] == 0) { // 첫 번째 해시함수 사용
		H[h] = k;
		printf("%d\n", h);
		return;
	}

	// 두 번쨰 해시함수 사용
	while (H[h] != 0) { // 빈 버킷이 아닐 때까지 순회
		printf("C");
		h = (h + hash2(k)) % M; // h값 업데이트
	}

	H[h] = k;
	printf("%d\n", h);

	return;
}

void print() { // 배열 H에 있는 모든 원소를 출력하는 함수
	for (int i = 0; i < M; i++) {
		printf(" %d", H[i]);
	}
	printf("\n");

	return;
}

int main() {
	char f;
	int n, k;

	scanf("%d %d %d", &M, &n, &q); getchar();

	H = (int*)malloc(M * sizeof(int)); // 배열 H 동적할당
	for (int i = 0; i < M; i++) { // 배열 H의 키값 0으로 초기화
		H[i] = 0;
	}

	while (1) {
		scanf("%c", &f); getchar();

		if (f == 'e') {
			print();
			break;
		}
		if (f == 'i') {
			scanf("%d", &k); getchar();
			insertItem(k);
		}
		if (f == 's') {
			scanf("%d", &k); getchar();
			findElement(k);
		}
		if (f == 'p') {
			print();
		}
	}

	return 0;
}
