#include <stdio.h>

using namespace std;

int main(void) {
	int sum[500][500];
	int dp[500][500];
	int t, k, tmp;
	scanf("%d", &t);
	for(int tcase=0; tcase<t; tcase++){
		int k;
		scanf("%d", &k);
		
		for(int i=0; i<k; i++)
			scanf("%d", &sum[0][i]);
		tmp = k;
		for(int i=0; i<k-1; i++){
			for(int j=1; j<tmp; j++){
				sum[j][i] = sum[j-1][i] + sum[0][j+i];
			}
			tmp--;
		}

		for(int i=0; i<k; i++)
			dp[0][i] = 0;
		for(int i=0; i<k-1; i++)
			dp[1][i] = sum[1][i];
		for(int i=2; i<k; i++)
			for(int j=0; j<k; j++)
				dp[i][j] = 2147483647;

		tmp = k-2;
		for(int i=2; i<k; i++){
			for(int j=0; j<tmp; j++){
				for(int cnt=0; cnt<i; cnt++){
					dp[i][j] = dp[cnt][j]+dp[i-1-cnt][j+1+cnt] < dp[i][j] ? dp[cnt][j]+dp[i-1-cnt][j+1+cnt] : dp[i][j];
				}
				dp[i][j] += sum[i][j];
			}
		}
		printf("%d\n", dp[k-1][0]);
	}
    return 0;
}