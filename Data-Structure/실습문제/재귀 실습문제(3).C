#pragma warning(disable:4996)
#include <stdio.h>

void print(int num) {
    if (num >= 10)    
        print(num/10);

    printf("%d\n", num%10);
}

int main() {
    int N;

    scanf("%d", &N);

    print(N);

    return 0;
}
