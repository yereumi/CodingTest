#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996);

typedef struct Node {
	int e;
	struct Node* NextNode;
}Node;

typedef struct List {
	struct Node* Head;
	struct Node* Tail;
}List;

typedef struct Lists {
	struct List* L1;
	struct List* L2;
}Lists;

Node* createNode();
List* initList();
Lists* initLists();
int isEmpty(List* list);
int get(List* list, int r);
int size(List* list);
void addLast(List* list, int e);
int removeFirst(List* list);
void print();
List* merge(List* L1, List* L2);
Lists* partition(List* list, int k);
List* mergeSort(List* list);

int n;

int main() {
	List* L = initList();
	int e;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &e);
		addLast(L, e);
	}
	
	L = mergeSort(L);

	print(L);
	
	return 0;
}

Node* createNode() {
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->e = NULL;
	newNode->NextNode = NULL;

	return newNode;
}

List* initList() {
	Node* Head = createNode();
	Node* Tail = createNode();

	List* list = (List*)malloc(sizeof(List));

	list->Head = Head;
	list->Tail = Tail;
	list->Head->NextNode = list->Tail;

	return list;
}

Lists* initLists() {
	List* L1 = initList();
	List* L2 = initList();

	Lists* lists = (Lists*)malloc(sizeof(Lists));

	lists->L1 = L1;
	lists->L2 = L2;

	return lists;
}

int isEmpty(List* list) {
	if (list->Head->NextNode == list->Tail)
		return 1;
	return 0;
}

int get(List* list, int r) {
	Node* p = list->Head;

	for (int i = 0; i < r; i++) {
		p = p->NextNode;
	}

	return p->e;
}

int size(List* list) {
	int s = 0;
	Node* p = list->Head->NextNode;

	while (p != list->Tail) {
		s += 1;
		p = p->NextNode;
	}

	return s;
}
void addLast(List* list, int e) {
	Node* p = createNode();
	Node* q = list->Head;
	p->e = e;

	while (q->NextNode != list->Tail) {
		q = q->NextNode;
	}

	p->NextNode = list->Tail;
	q->NextNode = p;

	return;
}

int removeFirst(List* list) {
	Node* p = list->Head->NextNode;
	int e = p->e;

	list->Head->NextNode = p->NextNode;
	free(p);

	return e;
}

void print(List* list) {
	Node* p = list->Head;

	while (p->NextNode != list->Tail) {
		p = p->NextNode;
		printf("%d ", p->e);
	}

	return;
}

List* merge(List* L1, List* L2) {
	List* emptyL = initList();

	while (!isEmpty(L1) && !isEmpty(L2)) {
		if (get(L1, 1) <= get(L2, 1)) {
			addLast(emptyL, removeFirst(L1));
		}
		else {
			addLast(emptyL, removeFirst(L2));
		}
	}

	while (!isEmpty(L1)) {
		addLast(emptyL, removeFirst(L1));
	}
	while (!isEmpty(L2)) {
		addLast(emptyL, removeFirst(L2));
	}

	return emptyL;
}

Lists* partition(List* list, int k) {
	Lists* L1L2 = initLists();
	List* L1 = initList();
	List* L2 = initList();

	Node* p, * q, * r;

	r = list->Head;
	L1->Head->NextNode = r->NextNode;
	
	for (int i = 0; i < k / 2; i++) {
		r = r->NextNode;
	}
	p = r;
	
	for (int i = k / 2; i < k; i++) {
		r = r->NextNode;
	}
	q = r;

	L2->Head->NextNode = p->NextNode;
	p->NextNode = L1->Tail;
	q->NextNode = L2->Tail;

	L1L2->L1 = L1;
	L1L2->L2 = L2;

	return L1L2;
}

List* mergeSort(List* list) {
	Lists* L1L2;
	List* L1;
	List* L2;

	if (size(list) > 1) {
		L1L2 = partition(list, size(list));
		L1L2->L1 = mergeSort(L1L2->L1);
		L1L2->L2 = mergeSort(L1L2->L2);
		list = merge(L1L2->L1, L1L2->L2);
	}

	return list;
}
