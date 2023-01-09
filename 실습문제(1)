#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct Node { 
	char elem; // 원소
	struct Node* PrevNode;
	struct Node* NextNode;
}Node;

//Head Tail 생성
Node* Head;
Node* Tail;

Node* CreateNode(char NewData) { // 노드 생성
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->elem = NewData;
	NewNode->NextNode = NULL;
	NewNode->PrevNode = NULL;

	return NewNode;
}

char DestroyNode(Node* NewNode) { // 노드 소멸
	char Data = NewNode->elem; 
	free(NewNode);

	return Data; // 노드에 저장된 값을 반환
}

void LinkHeadTail() { //Head Tail 연결
	Head = (Node*)malloc(sizeof(Node));
	Tail = (Node*)malloc(sizeof(Node));

	Head->NextNode = Tail; // Head와 Tail 연결
	Head->PrevNode = Tail;
	Tail->NextNode = Head;	
	Tail->PrevNode = Head;
}

int add(Node* list, int r, char e) {
	Node* NewNode = CreateNode(e);
	Node* p = list;

	for (int i = 1; i < r; i++) {
		p = p->NextNode;
		if (p == Tail) {
			printf("invalid position\n");
			return -1;
		}
	}

	NewNode->NextNode = p->NextNode;
	p->NextNode = NewNode;
	NewNode->NextNode->PrevNode = NewNode;
	NewNode->PrevNode = p;
}

int delete(Node* list, int r) {
	Node* p = list;

	for (int i = 1; i <= r; i++) {
		p = p->NextNode;
		if (p == Tail) {
			printf("invalid position\n");
			return -1;
		}
	}

	p->PrevNode->NextNode = p->NextNode;
	p->NextNode->PrevNode = p->PrevNode;

	DestroyNode(p);
}

char get(Node* list, int r) {
	Node* p = list;

	for (int i = 1; i <= r; i++) {
		p = p->NextNode;
		if (p == Tail) {
			printf("invalid position\n");
			return -1;
		}
	}
	return p->elem;
}

void print(Node* list) {
	Node* p = list->NextNode;

	while (1) {
		if (p == Tail)
			break;
		
		printf("%c", p->elem);
		p = p->NextNode;
	}

	printf("\n");
}

int main() {
	LinkHeadTail();
	Node* list = Head;

	int num;
	char cal;
	int r;
	char e;
	scanf("%d", &num); getchar();

	for (int i = 0; i < num; i++) {
		scanf("%c", &cal); getchar();

		if (cal == 'A') {
			scanf("%d %c", &r, &e); getchar();
			add(list, r, e);
		}
		else if (cal == 'D') {
			scanf("%d", &r); getchar();
			delete(list, r);
		}
		else if (cal == 'G') {
			scanf("%d", &r); getchar();
			if (get(list, r) != -1)
				printf("%c\n", get(list, r));
		}
		else if (cal == 'P') {
			print(list);
		}
	}

	Node* p = list;
	Node* tmp = NULL;
	while (p != Tail) {
		tmp = p->NextNode;
		DestroyNode(p);
		p = tmp;
	}
}
