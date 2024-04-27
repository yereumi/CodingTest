#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(char *S, int N, char c);
char pop(char *S);
void peek(char *S);
void duplicate(char *S, int N);
void upRotate(char *S, int n);
void downRotate(char *S, int n);
void print(char *S);

int t = -1;
int main() {
    int N, num, n;
    char *S = NULL, func[6], c;

    scanf("%d", &N); getchar();
    S = (char*)malloc(N * sizeof(char));

    scanf("%d", &num); getchar();
    for (int i = 0; i < num; i++) {
        scanf("%s", func); getchar();

        if (strcmp(func, "PUSH") == 0) {
            scanf("%c", &c); getchar();
            push(S, N, c);
        }
        if (strcmp(func, "POP") == 0) {
            pop(S);
        }
        if (strcmp(func, "PEEK") == 0) {
            peek(S);
        }
        if (strcmp(func, "DUP") == 0) {
            duplicate(S, N);
        }
        if (strcmp(func, "UpR") == 0) {
            scanf("%d", &n); getchar();
            upRotate(S, n);
        }
        if (strcmp(func, "DownR") == 0) {
            scanf("%d", &n); getchar();
            downRotate(S, n);
        }
        if (strcmp(func, "PRINT") == 0) {
            print(S);
        }
    }

    return 0;
}

void push(char *S, int N, char c) {
    if (t == N - 1) {
        printf("Stack FULL\n");
        return;
    }
    t++;
    S[t] = c;
}

char pop(char *S) {
    if (t == -1) {
        printf("Stack Empty\n");
        return -1;
    }
    t--;
    return S[t + 1];
}

void peek(char *S) {
    int tmp = t;

    if (tmp == -1) {
        printf("Stack Empty\n");
        return;
    }
    printf("%c\n", S[t]);
}

void duplicate(char *S, int N) {
    char c = pop(S);
    if (c == -1)
        return;
    push(S, N, c);
    push(S, N, c);
}

void upRotate(char *S, int n) {
    char tmp;

    if (n > t + 1)
        return;

    for (int i = t; i > t - n + 1; i--) {
        tmp = S[i];
        S[i] = S[i-1];
        S[i-1] = tmp;
    }
}

void downRotate(char *S, int n) {
    char tmp;

    if (n > t + 1)
        return;

    for (int i = t - n + 1; i < t ; i++) {
        tmp = S[i];
        S[i] = S[i+1];
        S[i+1] = tmp;
    }
}

void print(char *S) {
    int tmp = t;
    while (tmp != -1) {
        printf("%c", S[tmp]);
        tmp--;
    }
    printf("\n");
}
