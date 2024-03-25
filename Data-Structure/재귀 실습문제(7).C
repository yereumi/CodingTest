#pragma warning(disable:4996)
#include <stdio.h>

int check(char *x, char find, int cnt) {
    if (*x == 0) {
        return cnt;
    }

    if (*x == find)
        cnt++;
    
    return check(x+1, find, cnt);
}

int main() {
    char x[101], find, cnt = 0;

    scanf("%s", x);
    getchar();
    scanf("%c", &find);

    printf("%d",check(x, find, cnt));

    return 0;
}
