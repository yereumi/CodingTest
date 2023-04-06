#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

typedef struct Node { // 구조체 정의
	int coef, exp; // 항의 계수, 항의 차수
	struct Node* next; // next 노드
}Node;

Node* createnode();
void destroynode(Node*);
Node* appendTerm(Node*, int, int);
Node* addPoly(Node*, Node*);

int main() {
	int a, b, c, e;
	Node* Head_A = createnode(); // 다항식 A를 저장할 헤더
	Node* Head_B = createnode(); // 다항식 B를 저장할 헤더

	scanf("%d", &a); // A 항의 개수 입력
	Node* tmp_A = Head_A;
	for (int i = 0; i < a; i++) {
		scanf("%d %d", &c, &e);
		tmp_A = appendTerm(tmp_A, c, e); // A의 항 저장
	}

	scanf("%d", &b); // B 항의 개수 입력
	Node* tmp_B = Head_B;
	for (int i = 0; i < b; i++) {
		scanf("%d %d", &c, &e);
		tmp_B = appendTerm(tmp_B, c, e); // B의 항 저장
	}

	Node* result = addPoly(Head_A, Head_B); // 다항식 A, B의 합을 계산한 값을 result 노드에 저장
	Node* tmp = result->next;

	while (tmp != NULL) { // tmp가 NULL이 아닐 때 까지만 반복
		printf(" %d %d", tmp->coef, tmp->exp);
		tmp = tmp->next;
	}

	// 노드 종료(동적할당 해제)
	destroynode(Head_A);
	destroynode(Head_B);
	destroynode(result);
	//printf("END!!!");

	return 0;
}

Node* createnode() { // 노드 생성 함수
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->next = NULL; // next 노드 초기화

	return NewNode; // 생성한 노드 반환
}

void destroynode(Node* x) { // 노드 종료 함수
	Node* tmp1 = x, * tmp2;
	while (tmp1 != NULL) { // NULL 전까지 반복
		tmp2 = tmp1->next;
		free(tmp1);
		tmp1 = tmp2;
	}
}
Node* appendTerm(Node* k, int c, int e) { // 항 추가 함수
	Node* t = createnode(); // 새로운 노드(항) 생성

	t->coef = c; // 항의 계수 저장
	t->exp = e; // 항의 차수 저장
	//t->next = NULL; // next 노드 초기화
	k->next = t; // 이전 노드(k)와 연결

	return t;
}

Node* addPoly(Node* x, Node* y) { // 다항식 연산 함수
	int sum; // 동류항의 합을 저장

	Node* result = createnode(); // result 새로운 노드 생성
	
	Node* i = x->next; // x를 순회
	Node* j = y->next; // y를 순회
	Node* k = result; // result 노드를 저장할 노드 포인터

	while ((i != NULL) && (j != NULL)) { // i, j 모두 NULL이 아닐 때까지 반복
		if (i->exp > j->exp) { // x의 차수가 y의 차수보다 크면
			k = appendTerm(k, i->coef, i->exp); // x의 계수만 k에 저장
			i = i->next; // x의 next 노드로 이동
		}

		else if (i->exp < j->exp) { // x의 차수가 y의 차수보다 작으면
			k = appendTerm(k, j->coef, j->exp); // y의 계수만 k에 저장
			j = j->next; // y의 next 노드로 이동
		}

		else { // x의 차수와 y의 차수가 같으면
			sum = i->coef + j->coef; // sum에 x와 y의 차수의 합을 저장
			if (sum != 0) // sum이 0이 아니면 
				k = appendTerm(k, sum, i->exp); // sum을 k에 저장
			i = i->next; // x의 next 노드로 이동
			j = j->next; // y의 next 노드로 이동
		}
	}
	while (i != NULL) { // i가 NULL이 아니고, j는 NULL일 때
		k = appendTerm(k, i->coef, i->exp); // x의 계수를 k에 저장
		i = i->next;
	}
	while (j != NULL) { // j가 NULL이 아니고, i는 NULL일 때
		k = appendTerm(k, j->coef, j->exp); // y의 계수를 k에 저장
		j = j->next;
	}

	return result; // result 노드 반환
}
