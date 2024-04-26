#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int e;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* Header;
} LinkedList;

LinkedList *A;
LinkedList *B;

void init();
Node* createNode();
void destroyNode();
void addElem(LinkedList *L, int e);
int member(LinkedList *L, int e);
LinkedList* Union(Node *n, Node *m);
LinkedList* Intersect(Node *n, Node *m);

int main() {
    int num, elem;
    LinkedList *U, *I;
    Node *p;

    init();

    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        scanf("%d", &elem);
        addElem(A, elem);
    }

    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        scanf("%d", &elem);
        addElem(B, elem);
    }

    U = Union(A->Header, B->Header);
    I = Intersect(A->Header, B->Header);

    p = U->Header->next;
    if (p == NULL) {
        printf(" 0");
    }
    while (p != NULL) {
        printf(" %d", p->e);
        p = p->next;
    }
    printf("\n");

    p = I->Header->next;
    if (p == NULL) {
        printf(" 0");
    }
    while (p != NULL) {
        printf(" %d", p->e);
        p = p->next;
    }

    destroyNode();

    return 0;
}

void init() {
    Node *Header1 = (Node*)malloc(sizeof(Node));
    Header1->next = NULL;
    A = (LinkedList*) malloc(sizeof(LinkedList));

    A->Header = Header1;

    Node *Header2 = (Node*)malloc(sizeof(Node));
    Header2->next = NULL;
    B = (LinkedList*)malloc(sizeof(LinkedList));

    B->Header = Header2;
}

Node* createNode() {
    Node *newNode = (Node*)malloc(sizeof(Node));

    newNode->next = NULL;

    return newNode;
}

void destroyNode() {
    Node *p, *tmp;

    p = A->Header;
    while (p != NULL) {
        tmp = p->next;
        free(p);
        p = tmp;
    }
    free(A);

    p = B->Header;
    while (p != NULL) {
        tmp = p->next;
        free(p);
        p = tmp;
    }
    free(B);
}

void addElem(LinkedList *L, int e) {
    Node *newNode = createNode();
    newNode->e = e;
    Node *p = L->Header;

    while (p->next != NULL) {
        p = p->next;
    }

    p->next = newNode;
}

LinkedList* Union(Node *n, Node *m) {
    LinkedList *U = (LinkedList *)malloc(sizeof(LinkedList));
    U->Header = createNode();

    Node *p1, *p2;
    int a, b;

    p1 = n->next;
    p2 = m->next;

    while (p1 != NULL && p2 != NULL) {
        a = p1->e;
        b = p2->e;

        if (a < b) {
            addElem(U, a);
            p1 = p1->next;
        } else if (a > b) {
            addElem(U, b);
            p2 = p2->next;
        } else {
            addElem(U, a);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        a = p1->e;
        addElem(U, a);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        b = p2->e;
        addElem(U, b);
        p2 = p2->next;
    }

    return U;
}

LinkedList* Intersect(Node *n, Node *m) {
    LinkedList *I = (LinkedList *) malloc(sizeof(LinkedList));
    I->Header = createNode();

    Node *p1, *p2;
    int a, b;

    p1 = n->next;
    p2 = m->next;

    while (p1 != NULL && p2 != NULL) {
        a = p1->e;
        b = p2->e;

        if (a < b) {
            p1 = p1->next;
        } else if (a > b) {
            p2 = p2->next;
        } else {
            addElem(I, a);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    return I;
}
