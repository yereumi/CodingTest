#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 선언
typedef struct NODE {
    char elem;
    struct NODE* prev;
    struct NODE* next;
} NODE;

// 헤더, 트레일러 전역변수 선언
NODE *Header, *Trailer;

void init();
void ERROR();
NODE* createNode(char e);
char putNode(NODE* p);
int add(NODE* list, int r, char e);
int delete(NODE* list, int r);
char get(NODE* list, int r);
void print(NODE* list);

int main() {
    init();
    int n, r;
    char f, e;
    NODE *list = Header;

    scanf("%d", &n); getchar();

    for (int i = 0; i < n; i++) {
        scanf("%c", &f);
        getchar();

        if (f == 'A') {
            scanf("%d %c", &r, &e); getchar();

            add(list, r, e);
        }

        if (f == 'D') {
            scanf("%d", &r); getchar();

            delete(list, r);
        }

        if (f == 'G') {
            scanf("%d", &r); getchar();

            if (get(list, r) != -1)
                printf("%c\n", get(list, r));
        }

        if (f == 'P')
            print(list);
    }

    // 연결리스트 동적할당 해제
    NODE *p = list->next;
    NODE *tmp = NULL;

    while (p != Trailer) {
        tmp = p->next;
        putNode(p);
        p = tmp;
    }

    putNode(Header);
    putNode(Trailer);

    return 0;
}

void init() { // 연결리스트 초기화
    // 헤더, 트레일러 동적할당
    Header = (NODE*)malloc(sizeof(NODE));
    Trailer = (NODE*)malloc(sizeof(NODE));

    Header->next = Trailer;
    Trailer->prev = Header;
    Header->prev = NULL;
    Trailer->next = NULL;
}

void ERROR() { // 에러 메세지
    printf("invalid position\n");
}

NODE* createNode(char e) { // 노드 생성
    NODE *newNode = (NODE*)malloc(sizeof(NODE));

    newNode->elem = e;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

char putNode(NODE* p) { // 노드 동적할당 해제
    char e = p->elem;
    free(p);

    return e;
}

int add(NODE* list, int r, char e) { // 노드 추가
    NODE *newNode = createNode(e);
    NODE *p = list;

    for (int i = 1; i < r; i++) {
        p = p->next;
        if (p == Trailer){
            ERROR();
            return -1;
        }
    }

    newNode->next = p->next;
    newNode->prev = p;
    newNode->next->prev = newNode;
    p->next = newNode;

    return 0;
}

int delete(NODE* list, int r) { // 노드 제거
    NODE *p = list;

    for (int i = 1; i <= r; i++) {
        p = p->next;
        if (p == Trailer) {
            ERROR();
            return -1;
        }
    }
    p->prev->next = p->next;
    p->next->prev = p->prev;

    putNode(p);

    return 0;
}

char get(NODE* list, int r) { // 노드 찾기
    NODE *p = list;

    for (int i = 1; i <= r; i++) {
        p = p->next;
        if (p == Trailer) {
            ERROR();
            return -1;
        }
    }

    return p->elem;
}

void print(NODE* list) { // 연결리스트 출력
    NODE *p = list->next;

    while (p != Trailer) {
        printf("%c", p->elem);
        p = p->next;
    }
    printf("\n");
}
