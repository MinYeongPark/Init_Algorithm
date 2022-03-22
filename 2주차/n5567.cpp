#include <iostream>
using namespace std;
//#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

const int MAX = 501;
int num_ppl; // 동기 수
int num_list; // 리스트 수
int arr[MAX][MAX]; // 인접행렬
bool visited[MAX]; // 방문 여부
bool sFriend[MAX]; // 상근이와 친구 여부
int count_num = 0;     // 초대할 친구 수

void count() {
	// 상근이의 친구
	for (int i = 2; i <= num_ppl; i++) {
		if (arr[1][i] == 1) {
			visited[i] = true; // 방문
			sFriend[i] = true; // 상근이와 친구
		}
	}

	// 상근이의 친구의 친구
	for (int i = 2; i <= num_ppl; i++) {
		if (sFriend[i]) { // 상근이의 친구인 경우
			for (int j = 1; j <= num_ppl; j++) {
				if (arr[i][j]) { // 친구의 친구인 경우
					visited[j] = true;
				}
			}
		}
	}

	// 초대 인원 계산
	for (int i = 2; i <= num_ppl; i++) {
		if (visited[i]) count_num++;
	}
}

int main() {
	scanf("%d", &num_ppl);  // 동기 수
	scanf("%d", &num_list); // 리스트 수
	
	while (num_list--) {
		int f1, f2;
		scanf("%d %d", &f1, &f2);
		//cin >> f1 >> f2;
		arr[f1][f2] = 1;
		arr[f2][f1] = 1;
	}

	count();
	printf("%d", count_num);
	

	return 0;
}