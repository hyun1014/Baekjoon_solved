#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int num, i, j, max, result;
	scanf("%d", &num);
	int* arr = (int*)malloc(sizeof(int) * (num + 1));
	for (i = 1; i <= num; i++)
		scanf("%d", &arr[i]);
	int* dp = (int*)malloc(sizeof(int) * (num + 1));
	arr[0] = 0;
	dp[0] = 0;
	for (i = 1; i <= num; i++) {
		max = dp[0];
		for (j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				if (dp[j] > max)
					max = dp[j];
			}
		}
		dp[i] = max + 1;
	}
	result = dp[0];
	for (i = 1; i <= num; i++) {
		if (result < dp[i])
			result = dp[i];
	}
	printf("%d\n", result);
	free(arr);
	free(dp);
	return 0;
}