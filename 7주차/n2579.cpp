#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int* dp;
int* stairs;

int max_count(int n) {
	dp[0] = stairs[0];
	if (n > 1)
		dp[1] = stairs[1] + stairs[0];
	if (n > 2) {
		dp[2] = (stairs[0] < stairs[1]) ? stairs[1] + stairs[2] : stairs[0] + stairs[2];
	}
	if (n > 3) {
		for (int i = 3; i < n; i++) {
			int a = dp[i - 2] + stairs[i];
			int b = dp[i - 3] + stairs[i - 1] + stairs[i];
			if (a > b)
				dp[i] = a;
			else
				dp[i] = b;
		}
	}
	return dp[n-1];
}

int main() {
	int n;
	scanf("%d\n", &n);
	stairs = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d\n", &stairs[i]);
	}

	dp = new int[n];
	printf("%d", max_count(n));

	delete[] dp;
	delete[] stairs;
}