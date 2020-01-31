#pragma warning(disable : 4996)
#include <iostream>

using namespace std;
int arr[52][52];
int dx[8] = { -1,0,1,1,1,0,-1,-1 };
int dy[8] = { 1,1,1,0,-1,-1,-1,0 };
void dfs(int x, int y) {
	if (arr[x][y] == 0)
		return;
	arr[x][y] = 0;
	for (int i = 0; i < 8; i++) {
		if (arr[x + dx[i]][y + dy[i]] == 1)
			dfs(x + dx[i], y + dy[i]);
	}
}

int main(void) {
	int w, h, i, j, cnt;
	while (1) {
		cnt = 0;
		for (i = 0; i < 52; i++)
			for (j = 0; j < 52; j++)
				arr[i][j] = 0;
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0)
			break;
		for (i = 1; i <= h; i++)
			for (j = 1; j <= w; j++)
				scanf("%d", &arr[i][j]);
		for (i = 1; i <= h; i++) {
			for (j = 1; j <= w; j++) {
				if (arr[i][j] == 1) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}