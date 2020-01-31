#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, k, i, j;
	scanf("%d %d", &n, &k);
	int* arr = (int*)malloc(sizeof(int) * n);
	int* dp = (int*)malloc(sizeof(int) * (k + 1));
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for (i = 0; i <= k; i++)
		dp[i] = 0;

	for (int i = 0; i < n; i++) {
		dp[arr[i]]++;
		for (int j = arr[i] + 1; j <= k; j++) {
			dp[j] += dp[j - arr[i]];
		}
	}
	printf("%d\n", dp[k]);
	free(arr);
	free(dp);
	return 0;
}