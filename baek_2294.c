#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, k, i, j;
	scanf("%d %d", &n, &k);
	int* dp = (int*)malloc(sizeof(int) * (k + 1));
	int* arr = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	dp[0] = 0;
	for (i = 1; i <= k; i++) {
		dp[i] = 0;
		for (j = 0; j < n; j++) {
			if (i == arr[j]) {
				dp[i] = 1;
			}
			else if (i > arr[j]) {
				if (dp[i - arr[j]] != 0) {
					if (dp[i - arr[j]] + 1 < dp[i] || (dp[i] == 0)) {
						dp[i] = dp[i - arr[j]] + 1;
					}
				}
			}
		}
	}
	if (dp[k] == 0)
		printf("-1");
	else
		printf("%d\n", dp[k]);
	free(arr);
	free(dp);
	return 0;
}