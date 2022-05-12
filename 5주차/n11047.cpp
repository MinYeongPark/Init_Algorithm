#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	
	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	int count = 0;
	for (int i = N - 1; i >= 0; i--) {
		count += K / arr[i];
		K = K % arr[i];
	}
	printf("%d", count);
	return 0;
}