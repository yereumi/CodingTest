#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#pragma warning(disable:4996);

int* SelectionSort(int* arr, int n) {
	int minIdx, tmp;

	for (int i = 0; i < n; i++) {
		minIdx = findMin(arr, n, i);
		tmp = arr[i];
		arr[i] = arr[minIdx];
		arr[minIdx] = tmp;
	}

	return arr;
}

int findMin(int* arr, int n, int idx) {
	int minNum = arr[idx], minIdx = idx;

	for (int i = idx; i < n; i++) {
		if (arr[i] < minNum) {
			minIdx = i;
			minNum = arr[i];
		}
	}
	return minIdx;
}

int* InsertionSort(int* arr, int n) {
	int num;

	for (int i = 1; i < n; i++) {
		num = arr[i];
		int j = i - 1;
		while (j >= 0 && num < arr[j]) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = num;
	}

	return arr;
}

int main() {
	srand(time(NULL));
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;
	int n, * A, * B, num;
	scanf("%d", &n);

	A = (int*)malloc(n * sizeof(int));
	B = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		num = rand();
		A[i] = num;
		B[i] = num;
	}

	// 선택정렬
	QueryPerformanceFrequency(&ticksPerSec);

	QueryPerformanceCounter(&start);
	SelectionSort(A, n);
	QueryPerformanceCounter(&end);

	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%dms\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

	// 삽입정렬
	QueryPerformanceFrequency(&ticksPerSec);

	QueryPerformanceCounter(&start);
	InsertionSort(B, n);
	QueryPerformanceCounter(&end);

	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%dms\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
	
	free(A);
	free(B);

	return 0;
}

/*

// 문제 3번
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#pragma warning(disable:4996);

/// <summary>
/// 제자리 선택 정렬 method
/// </summary>
/// <param name="ar">배열의 시작 주소</param>
/// <param name="N">배열의 길이</param>
void inPlaceSelectSort(int* ar, int N) {

	int i, j; // 반복문 전용 변수
	int idx, tmp; // idx: 최댓값을 가진 배열 원소의 인덱스 저장, tmp: swap용 변수

	// 배열의 끝부터 인덱스 1 까지 반복
	for (i = N-1; i >0 ; i--) {
		idx = 0; // 최대값 저장 인덱스 초기화
		for (j = 0; j <= i; j++) { // 배열의 인덱스 0부터 i까지 반복
			if (ar[j] > ar[idx]) { // ar[j]가 ar[idx] 보다 크다면
				idx = j; // idx j로 업데이트
			}
		}

		// 최대값과 인덱스 i 번째인 원소와 swap
		tmp = ar[i];
		ar[i] = ar[idx];
		ar[idx] = tmp;
	}

	return;
}

/// <summary>
/// 제자리 삽입정렬 method
/// </summary>
/// <param name="ar">배열의 시작 주소</param>
/// <param name="N">배열의 길이</param>
void inPlaceInsertSort(int* ar, int N) {
	int i, j; // 반복문 전용 변수
	int tmp; //tmp: swap용 변수

	// 배열 인덱스 1부터 끝 까지 반복
	for (i = 1; i <= N - 1; i++) {
		for (j = i; j > 0; j--) { //인덱스 i 부터 인덱스 1 까지 반복
			if (ar[j] < ar[j-1]) { //ar[j] 가 ar[j-1] 보다 작다면
				// ar[j]와 ar[j-1]을 swap
				tmp = ar[j];
				ar[j] = ar[j-1];
				ar[j-1] = tmp;
			}
		}
	}

	return;
}

int main() {
	srand(time(NULL));
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;

	// 필요 변수 선언
	int N,  num; // N: 배열 길이 저장 변수, num:
	int* A = NULL, * B = NULL; // 배열 저장 포인터 선언
	int i; // 반복문 용 변수 선언

	// 배열 길이 N 입력
	scanf("%d", &N);

	// 배열 A, B 동적할당
	A = (int*)malloc(sizeof(int) * N);
	if (A == NULL) return -1;
	B = (int*)malloc(sizeof(int) * N);
	if (B == NULL) return -1;

	//같은 랜덤 값으로 배열 A, B 초기화
	for (i = 0; i < N; i++) {
		num = rand();
		A[i] = num;
		B[i] = num;
	}


	// 배열 A 시간 측정
	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);

	inPlaceSelectSort(A, N); // 배열 A 선택 정렬 실행

	QueryPerformanceCounter(&end); // 시간 측정 종료

	// 측정값으로부터 실행시간 계산
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%.12fms\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart * 1000));

	////////////////////////////////////////////////////////////////////////////////////

	// 배열 B 정렬 소요 시간 측정
	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);

	inPlaceInsertSort(B, N); // 배열 B 삽입 정렬 실행

	QueryPerformanceCounter(&end); // 시간 측정 종료

	// 측정값으로부터 실행시간 계산
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%.12fms\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart * 1000));


	// 배열 A, B 동적핟당 해제
	free(A);
	free(B);

	return 0;
}

*/
