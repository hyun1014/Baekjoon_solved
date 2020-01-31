#pragma warning(disable : 4996)
#include <iostream>

using namespace std;
int arr[52][52];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
void dfs(int x, int y) {
	if (arr[x][y] == 0)
		return;
	arr[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		if (arr[x + dx[i]][y + dy[i]] == 1)
			dfs(x + dx[i], y + dy[i]);
	}
}

int main(void) {
	int t, m, n, k, i, j, cnt, x, y, jir;
	scanf("%d", &t);
	for (cnt = 0; cnt < t; cnt++) {
		jir = 0;
		for (i = 0; i < 52; i++)
			for (j = 0; j < 52; j++)
				arr[i][j] = 0;
		scanf("%d %d %d", &m, &n, &k);
		for (i = 0; i < k; i++) {
			scanf("%d %d", &x, &y);
			arr[x + 1][y + 1] = 1;
		}
		for (i = 0; i < 52; i++) {
			for (j = 0; j < 52; j++) {
				if (arr[i][j] == 1) {
					dfs(i, j);
					jir++;
				}
			}
		}
		printf("%d\n", jir);
	}
	return 0;
}