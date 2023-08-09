#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996);

typedef struct Node {
	int key;
	struct Node* parent;
	struct Node* leftChild;
	struct Node* rightChild;
}Node;

Node* Root;

Node* getNode() {
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->parent = NULL;
	NewNode->leftChild = NULL;
	NewNode->rightChild = NULL;

	return NewNode;
}

Node* init() {
	Node* root = getNode();
	
	return root;
}

int isRoot(Node* p) {
	if (p->parent == NULL)
		return 1;
	return 0;
}

int isExternal(Node* p) {
	if (p->leftChild == NULL && p->rightChild == NULL)
		return 1;
	return 0;
}

int isInternal(Node* p) {
	if (p->leftChild != NULL || p->rightChild != NULL)
		return 1;
	return 0;
}

void invalidNodeException() {
	return;
}

Node* treeSearch(Node* v, int k) {
	if (isExternal(v))
		return v;
	if (k == v->key)
		return v;
	else if (k < v->key)
		return treeSearch(v->leftChild, k);
	else if (k > v->key)
		return treeSearch(v->rightChild, k);
}

int findElement(int k) {
	Node* w = treeSearch(Root, k);

	if (isExternal(w))
		return -1;
	return w->key;
}

void expandExternal(Node* v) {
	v->leftChild = getNode();
	v->rightChild = getNode();
	v->leftChild->parent = v;
	v->rightChild->parent = v;
}

Node* sibling(Node* w) {
	if (isRoot(w))
		invalidNodeException();
	if (w->parent->leftChild == w)
		return w->parent->rightChild;
	else
		return w->parent->leftChild;
}

Node* reduceExternal(Node* z) {
	Node* w, * zs, * g;

	w = z->parent;
	zs = sibling(z);

	if (isRoot(w)) {
		Root = zs;
		zs->parent = NULL;
	}
	else {
		g = w->parent;
		zs->parent = g;
		
		if (w == g->leftChild)
			g->leftChild = zs;
		else
			g->rightChild = zs;
	}

	free(z);
	free(w);

	return zs;
}

void insertItem(int k) {
	Node* w = treeSearch(Root, k);

	if (isInternal(w))
		return;
	w->key = k;
	expandExternal(w);	
}

Node* inOrderSucc(Node* w) {
	w = w->rightChild;

	if (isExternal(w))
		invalidNodeException();
	while (isInternal(w->leftChild))
		w = w->leftChild;

	return w;
}

int removeElement(int k) {
	Node* w, * z, * y;
	int e;

	w = treeSearch(Root, k);

	if (isExternal(w)) {
		printf("X\n");
		return;
	}

	e = w->key;
	z = w->leftChild;

	if (!isExternal(z))
		z = w->rightChild;
	if (isExternal(z))
		reduceExternal(z);
	else {
		y = inOrderSucc(w);
		z = y->leftChild;
		w->key = y->key;
		reduceExternal(z);
	}

	return e;
}

void printTree(Node* v) {
	if (isInternal(v)) {
		printf(" %d", v->key);
		printTree(v->leftChild);
		printTree(v->rightChild);
	}

	return;
}

void freeTree() {
	Node* p = Root;

	if (isExternal(p)) {
		free(p);
		return;
	}
	else {
		freeTree(p->leftChild);
		freeTree(p->rightChild);
		free(p);
	}
}

int main() {
	Root = init();

	char f;
	int k;

	while (1) {
		scanf("%c", &f); getchar();

		if (f == 'i') {
			scanf("%d", &k); getchar();
			insertItem(k);
		}
		else if (f == 'd') {
			scanf("%d", &k); getchar();
			if (removeElement(k) == k)
				printf("%d\n", k);\
		}
		else if (f == 's') {
			scanf("%d", &k); getchar();
			if (findElement(k) == k)
				printf("%d\n", k);
			else
				printf("X\n");
		}
		else if (f == 'p') {
			printTree(Root);
			printf("\n");
		}
		else if (f == 'q')
			break;
	}

	freeTree();

	return 0;
}
