#pragma warning(disable : 4996)
#include <iostream>

using namespace std;

int main(void) {
	int t, n, i, j;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%d", &n);
		int** dp = new int* [2];
		dp[0] = new int[n + 1];
		dp[1] = new int[n + 1];
		dp[0][0] = 1;
		dp[1][0] = 0;
		dp[0][1] = 0;
		dp[1][1] = 1;
		for (j = 2; j <= n; j++) {
			dp[0][j] = dp[0][j - 2] + dp[0][j - 1];
			dp[1][j] = dp[1][j - 2] + dp[1][j - 1];
		}
		printf("%d %d\n", dp[0][n], dp[1][n]);
		delete[] dp[0];
		delete[] dp[1];
		delete[] dp;
	}
	return 0;
}