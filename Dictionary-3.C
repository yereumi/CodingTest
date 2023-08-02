#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996);

int findElementK();

int main() {
	int a, b, n, mid;
	char t;
	scanf("%d %d %d", &a, &b, &n); getchar();

	for (int i = 0; i < n; i++) {
		scanf("%c", &t);
		mid = (a + b) / 2;
		if (t == 'Y') {
			a = mid + 1;
		}
		else if (t == 'N') {
			b = mid;
		}
	}

	printf("%d", a);

	return 0;
}
