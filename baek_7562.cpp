#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int chess[300][300];
bool checked[300][300];
int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };
vector<pair<int, int>> vec;
void bfs(pair<int, int> start, int length) {
	int a;
	int tx, ty;
	queue<pair<int, int>> que;
	pair<int, int> st;
	que.push(start);

	while (!que.empty()) {
		st = que.front();
		checked[st.first][st.second] = true;
		que.pop();
		for (a = 0; a < 8; a++) {
			tx = st.second + dx[a];
			ty = st.first + dy[a];
			if ((ty >= 0) && (ty < length) && (tx >= 0) && (tx < length)) {
				if (checked[ty][tx] == false) {
					chess[ty][tx] = chess[st.first][st.second] + 1;
					checked[ty][tx] = true;
					que.push(make_pair(ty, tx));
				}
			}
		}
	}
}

int main() {
	int test, cnt, i, j, sx, sy, tarx, tary, len;
	pair<int, int> startxy;
	scanf("%d", &test);
	for (cnt = 0; cnt < test; cnt++) {
		scanf("%d", &len);
		for (i = 0; i < len; i++)
			for (j = 0; j < len; j++) {
				chess[i][j] = 0;
				checked[i][j] = false;
			}
		scanf("%d %d", &sx, &sy);
		scanf("%d %d", &tarx, &tary);
		startxy = make_pair(sy, sx);
		bfs(startxy, len);
		printf("%d\n", chess[tary][tarx]);
	}
	return 0;
}