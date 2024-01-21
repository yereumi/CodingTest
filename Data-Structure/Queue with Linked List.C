#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct Node {
    int data;
    struct Node* NextNode;
}Node;

typedef struct QueueData {
    Node* front;
    Node* rear;
    int Queue_size;
}QueueData;

int EmptyQueueException() { // 큐에 아무것도 없을 때
    printf("Empty Queue Exception!!\n");
    return -1;
}

void initQueue(Node* Queue, QueueData* Queue_Data) { // front, rear 초기화
    Queue_Data->front = NULL;
    Queue_Data->rear = NULL;
    Queue_Data->Queue_size = 0;
}

int isEmpty(QueueData* Queue_Data) { // 큐에 비어있는지 확인
    if (Queue_Data->front == NULL) {
        EmptyQueueException();
        return -1;
    }
}

void enqueue(int NewData, Node* Queue, QueueData* Queue_Data) { // 큐에 원소 삽입
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->data = NewData;
    NewNode->NextNode = NULL;

    if (Queue_Data->front == NULL) { // 큐에 원소가 없으면
        Queue_Data->front = NewNode;
        Queue_Data->rear = NewNode;
    }
    else { // 큐에 원소가 있으면
        Queue_Data->rear->NextNode = NewNode;       
        Queue_Data->rear = NewNode;
    }

    Queue_Data->Queue_size++;

    printf("Front: %d\n", Queue_Data->front->data);
    printf("Rear: %d\n", Queue_Data->rear->data);
    printf("\n");
}

int dequeue(Node* Queue, QueueData* Queue_Data) { // 큐에서 원소 삭제
    if (isEmpty(Queue_Data) == -1) {
        return -1;
    }

    int Data = Queue_Data->front->data;
    Node* tmp = Queue_Data->front->NextNode;
    free(Queue_Data->front);
    Queue_Data->front = tmp;
    Queue_Data->Queue_size -= 1;

    printf("Dequeue: %d\n", Data);

    return Data;
}

void PrintQueue(QueueData* Queue_Data) {
    Node* p = Queue_Data->front;
    int i = 1;
    while (p != NULL) {
        printf("Queue %d: %d\n", i, p->data);
        p = p->NextNode;
        i++;
    }

    printf("\n");

    free(p);
}

int main() {
    int NewData, num_dequeue;
    // NewData: 입력받을 새로운 데이터, num_dequeue: 삭제할 노드 개수
    Node* Queue = (Node*)malloc(sizeof(Node));
    QueueData* Queue_Data = (QueueData*)malloc(sizeof(QueueData));
    initQueue(Queue, Queue_Data);

    while (1) {
        printf("Enqueue: ");
        scanf("%d", &NewData);

        if (NewData == 0)
            break;

        enqueue(NewData, Queue, Queue_Data);
    }
    
    printf("CountQueue: %d\n", Queue_Data->Queue_size);
    printf("\n");

    printf("Num Dequeue: ");
    scanf("%d", &num_dequeue); // 삭제할 노드 개수 입력

    PrintQueue(Queue_Data);

    for (int i = 0; i < num_dequeue; i++) {
        if (dequeue(Queue, Queue_Data) == -1) // 삭제할 노드가 없으면
            break; // 종료
    }
    printf("\n");

    printf("CountQueue: %d\n", Queue_Data->Queue_size);
    printf("\n");

    PrintQueue(Queue_Data);

    Node* p = Queue_Data->front;
    Node* tmp;

    for (int i = 0; i < Queue_Data->Queue_size; i++) { // 동적할당 해제
        tmp = p->NextNode;
        free(p);
        p = tmp;
    }

    free(Queue_Data);
    free(Queue);
    
    printf("!!!END!!!");
    return 0;
}
