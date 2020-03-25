#pragma warning(disable : 4996)
#include <iostream>

using namespace std;

int main(void) {
	int n, s, m, i, j;
	scanf("%d %d %d", &n, &s, &m);
	int* v = new int[n + 1];
	int* dp = new int[m + 1];
	for (i = 0; i <= m; i++)
		dp[i] = 0;
	v[0] = s;
	dp[s] = 1;
	for (i = 1; i <= n; i++)
		scanf("%d", &v[i]);
	for (i = 1; i <= n; i++) {
		for (j = 0; j <= m; j++) {
			if (dp[j] % 2 == 1) {
				if (((j - v[i]) >= 0) && ((j - v[i]) <= m)) {
					dp[j - v[i]] += 2;
				}
				if (((j + v[i]) >= 0) && ((j + v[i]) <= m))
					dp[j + v[i]] += 2;
			}
		}
		for (j = 0; j <= m; j++) {
			if (dp[j] >= 2)
				dp[j] = 1;
			else
				dp[j] = 0;
		}
	}
	for (i = m; i >= 0; i--) {
		if (dp[i] == 1)
			break;
	}
	printf("%d\n", i);
	delete[] v;
	delete[] dp;
	return 0;
}