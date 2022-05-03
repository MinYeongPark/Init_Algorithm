#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;

void merge(int arr[], int sorted[], int left, int mid, int right) {
	int i, j, k, l;
	i = left;     // 왼쪽 부분의 포인터 인덱스
	j = mid + 1;  // 오른쪽 부분의 포인터 인덱스
	k = left;     // 정렬된 배열에 넣을 인덱스

	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) // 왼쪽 부분의 맨 앞쪽 값 <= 오른쪽 부분의 맨 앞쪽 값
			sorted[k++] = arr[i++];
		else
			sorted[k++] = arr[j++];
	}
	if (i > mid)
		for (l = j; l <= right; l++)
			sorted[k++] = arr[l];
	else
		for (l = i; l <= mid; l++)
			sorted[k++] = arr[l];

	for (l = left; l <= right; l++)
		arr[l] = sorted[l];
}

void merge_sort(int arr[], int sorted[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		// 분할
		merge_sort(arr, sorted, left, mid);
		merge_sort(arr, sorted, mid + 1, right);

		// 병합하며 정렬
		merge(arr, sorted, left, mid, right);
	}
}

int main() {
	int N;
	scanf("%d", &N);
	int* arr = new int[N];
	int* sorted = new int[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	if (N == 1) {
		printf("%d", arr[0]);
		return 0;
	}
	merge_sort(arr, sorted, 0, N - 1);

	for (int i = 0; i < N; i++) {
		printf("%d\n", sorted[i]);
	}

	return 0;
}
