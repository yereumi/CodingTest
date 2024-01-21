#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void emptyStackException() {
	printf("Empty Stack Exception!!");
}

void fullStackException() {
	printf("Full Stack Exception!!");
}

int push(int* S, int N, int t, int e) { // 원소 e 삽입
	if (t == N - 1) { // 스택에 가득 차있으면
		fullStackException();
		return -1;
	}

	t += 1; // t 초기화
	*(S + t) = e; // 스택에 e 삽입

	return t; // t 반환
}

int pop(int* S, int N, int t) { // 가장 나중에 삽입된 원소를 삭제하여 반환
	if (t == -1) { // 스택에 아무것도 없으면
		emptyStackException();
		return -1;
	}

	int tmp_e = *(S + t);
	t -= 1; // t 초기화
	return t; // t 반환
}

int top(int* S, int t) { // 가장 나중에 삽입된 원소를 삭제하지 않고 반환
	if (t == -1) { // 스택에 아무것도 없으면
		emptyStackException();
		return -1;
	}

	return *(S + t);
}

int size(int t) { // 저장된 원소의 수 반환
	return t + 1;
}

void iterator_elements(int* S, int size) { // 스택 원소 맨 위에서부터 전체 출력
	for (int* p = S + size - 1; p >= S; p--) {
		printf("iterator_elements: %d\n", *p);
	}
}

int main() {
	int S[10] = { 0 }; // 0으로 초기화
	int N = 10, t = -1;
	int top_elem; // 스택 맨 위에 있는 원소
	int num; // 입력받을 원소
	int S_size; // 배열에 저장된 원소의 수

	while (1) {
		scanf("%d", &num); 
		
		if (num == 0) // 0을 입력받으면 종료
			break;
		t = push(S, N, t, num);
	}

	t = pop(S, N, t); // 맨 위에 원소 삭제
	
	top_elem = top(S, t); // 맨 위에 원소
	printf("top: %d\n", top_elem);

	S_size = size(t); // 배열에 저장된 원소 개수
	printf("size: %d\n", S_size);

	iterator_elements(S, S_size); // 배열에 저장된 전체 원소 출력
}
