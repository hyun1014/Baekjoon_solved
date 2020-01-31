#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> vec[101];
bool checked[101];
int dist[101];

void bfs(int start) {
	int cur, i, veclen, temp;
	queue<int> que;
	que.push(start);
	checked[start] = true;
	dist[start] = 0;
	while (!que.empty()) {
		cur = que.front();
		que.pop();
		veclen = vec[cur].size();
		checked[cur] = true;
		for (i = 0; i < veclen; i++) {
			temp = vec[cur][i];
			if (checked[temp] == false) {
				dist[temp] = dist[cur] + 1;
				que.push(temp);
			}
		}
	}
}

int main() {
	int n, a, b, m, i, x, y;
	scanf("%d", &n);
	scanf("%d %d", &a, &b);
	scanf("%d", &m);
	for (x = 0; x <= n; x++) {
		checked[x] = false;
		dist[x] = 0;
	}
	for (i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	bfs(a);
	if (dist[b] == 0)
		printf("-1\n");
	else
		printf("%d\n", dist[b]);
	return 0;
}