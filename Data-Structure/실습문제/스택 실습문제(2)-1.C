#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(char *S, char c);
char pop(char *S);
void peek(char *S);

int t = -1;
int main() {
    int N, i, cnt = 0, isWrong = 0;
    char sen[1001], S[1001];

    gets(sen);

    i = 0;
    while (sen[i] != '\0') {
        if (sen[i] == '(' || sen[i] == '[' || sen[i] == '{') {
            cnt++;
            push(S, sen[i]);
        }
        if (sen[i] == ')') {
            cnt++;
            if (pop(S) != '(')
                isWrong = 1;
        }
        if (sen[i] == ']') {
            cnt++;
            if (pop(S) != '[')
                isWrong = 1;
        }
        if (sen[i] == '}') {
            cnt++;
            if (pop(S) != '{')
                isWrong = 1;
        }
        i++;
    }

    if (isWrong == 0 & t == -1) {
        printf("OK_%d", cnt);
    } else {
        printf("Wrong_%d", cnt);
    }

    return 0;
}

void push(char *S, char c) {
    t++;
    S[t] = c;
}

char pop(char *S) {
    if (t == -1) {
        return -1;
    }
    t--;
    return S[t + 1];
}

void peek(char *S) {
    int tmp = t;

    if (tmp == -1) {
        return;
    }
    printf("%c\n", S[t]);
}
