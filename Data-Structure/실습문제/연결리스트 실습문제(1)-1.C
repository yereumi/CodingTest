#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 선언
typedef struct NODE {
    int coef;
    int exp;
    struct NODE* next;
} NODE;

// 헤더 전역변수 선언
NODE *Header1, *Header2, *Header3;

void init();
NODE* createNode(int c, int e);
void destroyNode(NODE* x);
NODE* appendTerm(NODE* k, int c, int e);
NODE* addPoly(NODE* x, NODE* y);

int main() {
    init();
    int n1, n2, c, e;
    NODE* p = Header1;
    NODE* result;

    scanf("%d", &n1); // 첫 번째 다항식
    for (int i = 0; i < n1; i++) {
        scanf("%d %d", &c, &e);
        p = appendTerm(p, c, e);
    }

    p = Header2;
    scanf("%d", &n2); // 두 번째 다항식
    for (int i = 0; i < n2; i++) {
        scanf("%d %d", &c, &e);
        p = appendTerm(p, c, e);
    }

    result = addPoly(Header1, Header2)->next;

    while (result != NULL) {
        printf(" %d %d", result->coef, result->exp);
        result = result->next;
    }

    destroyNode(Header1);
    destroyNode(Header2);
    destroyNode(Header3);
    free(Header1);
    free(Header2);
    free(Header3);

    return 0;
}

void init() {
    Header1 = (NODE*)malloc(sizeof(NODE));
    Header2 = (NODE*)malloc(sizeof(NODE));
    Header3 = (NODE*)malloc(sizeof(NODE));

    Header1->next = NULL;
    Header2->next = NULL;
    Header3->next = NULL;
}

NODE* createNode(int c, int e) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));

    newNode->coef = c;
    newNode->exp = e;

    return newNode;
}

void destroyNode(NODE* x) {
    NODE* p1 = x, * p2;
    while (p1 != NULL) {
        p2 = p1->next;
        free(p1);
        p1 = p2;
    }
}

NODE* appendTerm(NODE* k, int c, int e) {
    NODE* t = createNode(c, e);
    t->next = NULL;
    k->next = t;
    k = t;

    return k;
}

NODE* addPoly(NODE* x, NODE* y) {
    NODE *i, *j;
    int sum;

    NODE* result = Header3;

    i = x->next;
    j = y->next;

    while (i != NULL && j != NULL) {
        if (i->exp > j->exp) {
            result = appendTerm(result, i->coef, i->exp);
            i = i->next;
        }
        else if (i->exp < j->exp) {
            result = appendTerm(result, j->coef, j->exp);
            j = j->next;
        }
        else {
            sum = i->coef+ j->coef;
            if (sum != 0)
                result = appendTerm(result, sum, i->exp);
            i = i->next;
            j = j->next;
        }
    }

    while (i != NULL) {
        result = appendTerm(result, i->coef, i->exp);
        i = i->next;
    }

    while (j != NULL) {
        result = appendTerm(result, j->coef, j->exp);
        j = j->next;
    }

    return Header3;
}
