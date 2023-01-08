#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct Node { 
	int data;
	struct Node* PrevNode;
	struct Node* NextNode;
}Node;

//Head Tail 생성
Node* Head;
Node* Tail;

Node* CreateNode(int NewData) { // 노드 생성
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->data = NewData;
	NewNode->NextNode = NULL;
	NewNode->PrevNode = NULL;

	return NewNode;
}

int DestroyNode(Node* NewNode) { // 노드 소멸
	int Data = NewNode->data; 
	free(NewNode);

	return Data; // 노드에 저장된 값을 반환
}

void LinkHeadTail() { //Head Tail 연결
	Head = (Node*)malloc(sizeof(Node));
	Tail = (Node*)malloc(sizeof(Node));

	Head->NextNode = Tail; // Head와 Tail 연결
	Head->PrevNode = NULL;
	Tail->NextNode = NULL;	
	Tail->PrevNode = Head;
}

void AppendNode(int data) { // 노드 추가
	Node* NewNode = CreateNode(data);

	// Head 다음에 추가할 때 (Tail 전->성공, 중간에 추가하는 것도 해보기->삽입)
	/*
	Node* tmp = Head->NextNode;
	Head->NextNode = NewNode;
	NewNode->NextNode = tmp;
	tmp->PrevNode = NewNode;
	NewNode->PrevNode = Head;
	*/

	// Tail 직전에 추가할 때
	Node* tmp = Tail->PrevNode;
	tmp->NextNode = NewNode;
	NewNode->NextNode = Tail;
	Tail->PrevNode = NewNode;
	NewNode->PrevNode = tmp;
}

Node* FindNode(int data) { // 노드 탐색
	Node* p = Head->NextNode;

	// Head부터 탐색할 때
	while (p != Tail) {
		if (p->data == data) {
			return p; // 노드 반환
		}

		else {
			p = p->NextNode;
		}
	}

	// Tail부터 탐색할 때
	/*
	p = Tail->PrevNode;
	while (p != Head) {
		if (p->data == data) {
			return p; // 노드 반환
		}

		else {
			p = p->PrevNode;
		}
	}
	*/

	printf("Find: Not Found!!\n"); // 예외: 리스트 안에 data가 없을 때
	return -1;
}

int RemoveNode(int data) { // 노드 제거
	Node* p = FindNode(data);

	if (p == -1) {
		printf("Remove: Not Found!!\n"); // 예외: 리스트 안에 data가 없을 때
		return -1;
	}

	Node* tmp_Next = p->NextNode;
	Node* tmp_Prev = p->PrevNode;

	tmp_Next->PrevNode = tmp_Prev;
	tmp_Prev->NextNode = tmp_Next;

	DestroyNode(p);
}

Node* InsertNode(int Current, int data) { // 노드 삽입
	Node* p = FindNode(Current);

	if (p == -1) {
		printf("Insert: Not Found!!\n");
		return -1;
	}

	Node* NewNode = CreateNode(data); 
	// p를 정의한 뒤에 NewNode를 정의해야하는 이유: p가 -1일 경우 새로운 노드를 생성만 하고 프로그램 종료됨

	//NextNode 처리
	NewNode->NextNode = p->NextNode;
	p->NextNode = NewNode;
	//PrevNode 처리
	NewNode->NextNode->PrevNode = NewNode;
	NewNode->PrevNode = p;
	
	return NewNode; // 삽입한 data의 주소값
}

int CountNode(Node* Head) { // 노드 개수 세기
	int cnt = 0;
	Node* Current = Head->NextNode;

	while (Current != Tail) {
		cnt++;
		Current = Current->NextNode;
	}

	return cnt;
}

int main() {
	LinkHeadTail();

	AppendNode(1);
	AppendNode(2);
	AppendNode(3);

	Node* p = Head->NextNode;
	while (p != Tail) {
		printf("Append %d\n", p->data);
		p = p->NextNode;

	}
	p = Tail->PrevNode;
	while (p != Head) {
		printf("Append %d\n", p->data);
		p = p->PrevNode;
	}

	RemoveNode(3);

	p = Head->NextNode;
	while (p != Tail) {
		printf("Remove %d\n", p->data);
		p = p->NextNode;
	}
	p = Tail->PrevNode;
	while (p != Head) {
		printf("Remove %d\n", p->data);
		p = p->PrevNode;
	}

	int cnt = CountNode(Head);
	printf("%d\n", cnt);

	InsertNode(2, 10);

	p = Head->NextNode;
	while (p != Tail) {
		printf("Insert %d\n", p->data);
		p = p->NextNode;
	}
	p = Tail->PrevNode;
	while (p != Head) {
		printf("Insert %d\n", p->data);
		p = p->PrevNode;
	}

	printf("%p\n", FindNode(5));

	p = Head->NextNode;
	Node* tmp = p->NextNode;
	while (p != Tail) { // 동적할당 해제
		DestroyNode(p);
		p = tmp;
		tmp = p->NextNode;
	}
	free(Tail); // Tail부터 동적할당 해제
	free(Head); // Head 동적할당 해제
}
