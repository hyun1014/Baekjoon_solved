#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void) {
	int N, ans, idx;
	int arr[200];
	int dp[201];
	dp[0] = 0;
	ans = 0;
	for(int i=1; i<=200; i++)
		dp[i] = 999;
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", &arr[i]);
	for(int i=0; i<N; i++){
		idx = lower_bound(dp, dp+ans+1, arr[i]) - dp;
		dp[idx] = arr[i];
		if(idx==ans+1)
			ans++;
	}
	printf("%d\n", N-ans);
	return 0;
}