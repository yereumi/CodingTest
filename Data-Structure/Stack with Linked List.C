#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct Node {
	int data;
	struct Node* NextNode;
}Node;

void emptyStackException() {
	printf("Empty Stack Exception!!\n");
}

void initStack(Node* top) { // top 초기화
	top->NextNode = NULL;
}

void PushStack(int NewData, Node* top) { // 노드 삽입
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->data = NewData;
	NewNode->NextNode = top->NextNode;
	top->NextNode = NewNode;
}

int PopStack(Node* top) { // 노드 삭제
	if (top->NextNode == NULL) { // 스택에 노드가 없으면
		emptyStackException();
		return -1;
	}

	int Data = top->NextNode->data;
	Node* tmp = top->NextNode->NextNode;
	free(top->NextNode);
	top->NextNode = tmp;

	printf("PopStack: %d\n", Data);

	return Data;
}

int CountStack(Node* top) { // 스택에 있는 노드 개수
	int cnt = 0;
	Node* tmp = top->NextNode;

	while (tmp != NULL) { // tmp가 NULL을 가르키지 않으면 반복
		cnt++;
		tmp = tmp->NextNode;
	}

	free(tmp);

	return cnt;
}

void PrintStack(Node* top) { // 스택에 있는 노드 출력
	Node* tmp = top->NextNode;

	while (tmp != NULL) { // tmp가 NULL을 가르키지 않으면 반복
		printf("%d\n", tmp->data);
		tmp = tmp->NextNode;
	}

	free(tmp);
}

int main() {
	int NewData, Pop; 
	// NewData: 입력받을 새로운 데이터, Pop: 삭제할 노드 개수
	Node* top = (Node*)malloc(sizeof(Node));
	initStack(top);

	while (1) {
		scanf("%d", &NewData);

		if (NewData == 0) // 새로운 데이터가 0이면 종료
			break;

		PushStack(NewData, top);
	}

	printf("CountStack: %d\n", CountStack(top));
	PrintStack(top);

	scanf("%d", &Pop); // 삭제할 노드 개수 입력

	for (int i = 0; i < Pop; i++) {
		if (PopStack(top) == -1) // 삭제할 노드가 없으면 종료
			break;
	}

	printf("CountStack: %d\n", CountStack(top));
	PrintStack(top);
	
	Node* p = top->NextNode;
	Node* tmp = p->NextNode;
	while (1) { // 동적할당 해제
		free(p);
		p = tmp;
		if (p == NULL)
			break;
		tmp = p->NextNode;
	}

	free(top);

	return 0;
}
