#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void EmptyQueueException() { // 큐에 아무것도 없을 때
	printf("Empty Queue Exception!!\n");
	return -1;
}

int* initQueue(int* Queue, int N, int* pf, int* pr) {
	Queue = (int*)malloc(N * sizeof(int)); // 포인터 배열 동적할당
	*pf = 0; // front 0으로 초기화
	*pr = N - 1; // rear N-1로 초기화

	for (int i = 0; i < N; i++)
		*(Queue + i) = 0;

	return Queue;
}

int enqueue(int* Queue, int N, int* pf, int* pr, int data) { // 큐에 삽입
	*pr = (*pr + 1) % N; // r 이동
	int idx = *pr; // r위치 idx에 저장
	*(Queue + idx) = data; // data 배열에 저장
}

int dequeue(int* Queue, int N, int* pf, int* pr) { // 큐에서 삭제
	if ((*pr + 1) % N == pf) {// 큐가 비어있으면
		EmptyQueueException();
		return -1;
	}

	int idx = *pf; // f위치 idx에 저장
	int data = *(Queue + idx); // data 변수에 값 저장
	*pf = (*pf + 1) % N; // f 이동

	return data; // 삭제한 원소 반환
}

int size(int N, int* pf, int* pr) { // 큐에 있는 원소의 크기 반환
	int QueueSize = (N - *pf + *pr + 1) % N;
	return QueueSize;
}

int datafront(int* Queue, int N, int* pf, int* pr) { // 큐의 front에 위치한 원소 반환
	if ((*pr + 1) % N == *pf) { // 큐가 비어있으면
		EmptyQueueException();
		return -1;
	}
	int idx = *pf; // f위치 idx에 저장
	return *(Queue + idx);
}

void print(int* Queue, int QueueSize, int* pf, int* pr) {
	int idx = *pf;

	for (int i = idx; i < idx + QueueSize; i++) { // 배열 크기만큼 반복
		if (idx == QueueSize) // idx가 QueueSize보다 크면(배열의 범위를 초과하면)
			idx -= QueueSize;
		else
			printf("%d ", *(Queue + i));
	}
	printf("\n");
}

int main() {
	int* Queue = NULL;
	int num_enqueue, num_dequeue, N, f, r;
	// num_enqueue: 입력받을 원소 수, num_dequeue: 삭제할 원소 수, N: 배열의 크기(빈 방 포함)
	int e; // 입력받을 원소
	int e_dequeue; // 삭제한 원소
	int QueueSize; // 큐에 있는 원소 개수
	int front_data; // front에 있는 원소
	int* pf = &f, * pr = &r;

	printf("num_enqueue: ");
	scanf("%d", &num_enqueue);
	printf("num_dequeue: ");
	scanf("%d", &num_dequeue);
	N = num_enqueue + 1;

	printf("START\n");
	Queue = initQueue(Queue, N, pf, pr);

	for (int i = 0; i < num_enqueue; i++) { // 원소 입력
		printf("element: ");
		scanf("%d", &e);
		enqueue(Queue, N, pf, pr, e);
	}

	printf("\n");
	printf("After Enqueue\n");
	QueueSize = size(N, pf, pr);
	print(Queue, QueueSize, pf, pr);
	printf("QueueSize: %d\n", QueueSize);

	front_data = datafront(Queue, N, pf, pr);
	if (front_data != -1)
		printf("datafront: %d\n", front_data);

	printf("\n");
	for (int i = 0; i < num_dequeue; i++) {
		e_dequeue = dequeue(Queue, N, pf, pr);
		if (e_dequeue == -1)
			break;
		else if (e_dequeue != 0)
			printf("dequeue: %d\n", e_dequeue);
	}


	printf("\n");
	printf("After Dequeue\n");
	QueueSize = size(N, pf, pr);
	print(Queue, QueueSize, pf, pr);
	printf("QueueSize: %d\n", size(N, pf, pr));

	front_data = datafront(Queue, N, pf, pr);
	if (front_data != -1)
		printf("datafront: %d\n", front_data);

	free(Queue);

	return 0;
}
