#pragma warning(disable:4996)
#include <stdio.h>

int max(int *num, int cnt) {
    int max_num = *num;

    if (cnt == 1) {
        return num[0];
    }

    if (max(num, cnt - 1) > num[cnt - 1])
        return max(num, cnt - 1);
    return num[cnt - 1];
}

int main() {
    int N, num[20];

    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d", &num[i]);
    }

    printf("%d", max(num, N));

    return 0;
}
