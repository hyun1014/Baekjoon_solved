#include <stdio.h>

using namespace std;

int M, N;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int arr[500][500];
int dp[500][500];

int dfs(int x, int y){
	if(x==(M-1) && y==(N-1))
		return 1;
	else if (dp[x][y]!=-1)
		return dp[x][y];
	int sum = 0;
	int xx, yy;
	for(int i=0; i<4; i++){
		xx = x + dx[i];
		yy = y + dy[i];
		if(xx>=0 && xx<M && yy>=0 & yy<N && arr[x][y]>arr[xx][yy]){
			sum += dfs(xx, yy);
		}
	}
	dp[x][y] = sum;
	return dp[x][y];
}

int main(void) {
	scanf("%d %d", &M, &N);
	for(int i=0; i<M; i++)
		for(int j=0; j<N; j++)
			dp[i][j] = -1;
	dp[M-1][N-1] = 1;

	for(int i=0; i<M; i++)
		for(int j=0; j<N; j++)
			scanf("%d", &arr[i][j]);

	dfs(0, 0);
	printf("%d\n", dp[0][0]);
	return 0;
}