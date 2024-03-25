#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int push(char* stack, char c, int stack_size, int top) {
	if (top == stack_size) { // 스택이 꽉 차있으면
		printf("Stack FULL\n");
		return -1;
	}

	*(stack + top) = c; // 배열에 원소 저장
	top += 1;

	return top; // 배열 인덱스 반환
}

char pop(char* stack, int stack_size, int top) {
	if (top == 0) { // 스택이 비어있으면
		printf("Stack Empty\n");
		return -1;
	}

	char data = *(stack + top);
	top -= 1;
	
	return data;
}



int main() {
	int stack_size, n, top;
	// stack_size: 스택 크기, n: 연산의 개수, top: 배열 인덱스
	char menu[100]; // 입력받을 연산
	scanf("%d", &stack_size); getchar();
	char* stack = (char*)malloc(n * sizeof(char)); // 배열 동적할당

	for (int i = 0; i < n; i++) {
		scanf("%s", menu); getchar();
	}

	return 0;
}
