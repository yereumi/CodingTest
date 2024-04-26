#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int e;
    struct Node* next;
} Node;

Node* createNode();
void destroyNode();
void addElem(Node *N, int e);
int member(Node *N, int e);
int subset(Node *A, Node *B);

Node *A;
Node *B;

int main() {
    int num, elem;

    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        scanf("%d", &elem);
        if (i == 0) {
            A = createNode();
            A->e = elem;
        } else {
            addElem(A, elem);
        }
    }

    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        scanf("%d", &elem);
        if (i == 0) {
            B = createNode();
            B->e = elem;
        } else {
            addElem(B, elem);
        }
    }

    printf("%d", subset(A, B));
    
    destroyNode();

    return 0;
}

Node* createNode() {
    Node *newNode = (Node*)malloc(sizeof(Node));

    newNode->next = NULL;

    return newNode;
}

void destroyNode() {
    Node *p, *tmp;

    p = A;
    while (p != NULL) {
        tmp = p->next;
        free(p);
        p = tmp;
    }

    p = B;
    while (p != NULL) {
        tmp = p->next;
        free(p);
        p = tmp;
    }
}

void addElem(Node *N, int e) {
    Node *newNode = createNode();
    newNode->e = e;

    Node *p = N;

    while (p->next != NULL) {
        p = p->next;
    }

    p->next = newNode;
}

int member(Node *N, int e) {
    Node *p = N;
    int a;

    while (p != NULL) {
        a = p->e;
        if (a < e) {
            p = p->next;
        } else if (a > e) {
            return 0;
        } else
            return 1;
    }
    return 0;
}

int subset(Node *A, Node *B) {
    Node *p = A;

    while (p != NULL) {
        if (member(B, p->e)) {
            p = p->next;
        }
        else
            return p->e;
    }
    return 0;
}
