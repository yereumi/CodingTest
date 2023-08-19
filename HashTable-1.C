#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996);

typedef struct Node { // 구조체(키값, 버킷 안의 리스트)
	int e;
	struct Node* next;
}Node;

typedef struct bucket { // 버킷
	Node* Head; // 각 버킷 안에 Head 노드
}bucket;

Node* getNode() { // 노드 생성 함수
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->e = NULL;
	NewNode->next = NULL;

	return NewNode;
}

bucket* H; // 버킷 리스트 정의
int M; // 버킷 크기 전역변수로 정의

void initBucketArray() { // 버킷 리스트 시작 함수
	H = (bucket*)malloc(M * sizeof(bucket));

	for (int i = 0; i < M; i++) { // M개의 버킷의 Head 생성
		H[i].Head = getNode();
	}
}

int hash(int k) { // 해쉬 함수
	return k % M;
}

int findElement(int k) { // 키 찾는 함수
	int v = hash(k); // 키의 해쉬값을 v에 저장
	int cnt = 1; // 우선순위 저장 변수 cnt
	Node* p = H[v].Head->next; // H를 순회할 노드 포인터 p(H[v]의 Head의 next부터 시작)

	while (p != NULL) { // p가 NULL이 아닐 때까지 반복
		if (p->e == k) // p의 키값과 매개변수 k의 값이 같으면
			return cnt; // 우선순위 반환
		// 다르면
		cnt++; // 우선순위 ++
		p = p->next; // p 업데이트
	}

	return 0; // H에 찾는 키값이 없으면 0 반환
}

void insertItem(int k) { // 버킷 리스트의 키 삽입 함수
	int v = hash(k); // 키의 해쉬값을 v에 저장
	Node* NewNode = getNode(); // 새로운 노드 생성
	NewNode->e = k; // 새 노드의 키값에 k 저장

	Node* p = H[v].Head, * tmp; // H를 순회할 노드 포인터 p(H[v]의 Head의 next부터 시작)

	tmp = p->next; // 노드 포인터 tmp에 p의 다음 노드 저장
	p->next = NewNode; // p의 다음 노드에 새 노드 저장
	NewNode->next = tmp; // 새 노드의 다음 노드에 tmp 저장

	return;
}

int removeItem(int k) { // 버킷 리스트에 있는 키 삭제 함수
	int v = hash(k); // 키의 해쉬값을 v에 저장
	int cnt = 1; // 우선순위 저장 변수 cnt
	Node* p = H[v].Head->next, *q, * tmp; // H를 순회할 노드 포인터 p(H[v]의 Head의 next부터 시작)
	q = p; // 노드 포인터 q에 p 저장

	while (p != NULL) { // p가 NULL이 아닐 때까지 반복
		if (p->e == k) { // p의 키값과 배개변수 k의 값이 같으면
			if (p == H[v].Head->next) { // p가 버킷의 Head의 다음 노드이면
				H[v].Head->next = p->next; // 버킷의 Head의 다음 노드에 p의 다음 노드 저장
				free(p); // p 동적할당 해제

				return cnt; // cnt 반환
			}
			// 아니면
			tmp = p->next; // tmp에 p의 다음 노드 저장
			q->next = tmp; // q의 다음 노드에 tmp 저장
			free(p); // p 동적할당 해제

			return cnt; // cnt 반환
		}
		// 다르면 
		cnt++; // 우선순위++
		q = p; // q 업데이트
		p = p->next; // p 업데이트

	}
	
	return 0;
}

void print() { // 버킷 리스트에 있는 모든 노드 출력 함수
	for (int i = 0; i < M; i++) {
		Node* p = H[i].Head->next;
		while (p != NULL) {
			printf(" %d", p->e);
			p = p->next;
		}
	}
	printf("\n");
}

void freeHash() { // 버킷 리스트 동적할당 해제 함수
	Node* p = NULL, * q = NULL;

	for (int i = 0; i < M; i++) {
		p = H[i].Head;
		while (p != NULL) {
			q = p->next;
			free(p);
			p = q;
		}
	}

	free(H);
}

int main() {
	char f;
	int k;

	scanf("%d", &M); getchar();

	initBucketArray();

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
			printf("%d\n", findElement(k));
		}
		if (f == 'd') {
			scanf("%d", &k); getchar();
			printf("%d\n", removeItem(k));
		}
		if (f == 'p') {
			print();
		}
	}

	freeHash();

	return 0;
}
