#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int main(void) {
	int num, i;
	scanf("%d", &num);
	int* dp = new int[num + 1];
	int* arr = new int[num + 1];
	for (i = 0; i <= num; i++)
		dp[i] = 0;
	for (i = 1; i <= num; i++)
		scanf("%d", &arr[i]);
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	for (i = 3; i <= num; i++) {
		dp[i] = dp[i - 3] + arr[i - 1] + arr[i];
		if (dp[i] < (dp[i - 2] + arr[i]))
			dp[i] = dp[i - 2] + arr[i];
	}
	printf("%d\n", dp[num]);
	delete[] dp;
	delete[] arr;
	return 0;
}