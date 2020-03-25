#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int v;
bool graph[1001][1001];

void bfs(int start, bool checked[]) {
	int temp, i;
	queue<int> que;
	que.push(start);
	checked[start] = true;
	while (!que.empty()) {
		temp = que.front();
		que.pop();
		printf("%d ", temp);
		for (i = 1; i <= v; i++) {
			if ((checked[i] == false) && (graph[temp][i] == true)) {
				que.push(i);
				checked[i] = true;
			}
		}
	}
}
void dfs(int start, bool checked[]) {
	int i;
	if (checked[start] == true)
		return;
	checked[start] = true;
	printf("%d ", start);
	for (i = 1; i <= v; i++) {
		if ((checked[i] == false) && (graph[start][i] == true)) {
			dfs(i, checked);
		}
	}
}
int main(void) {
	int i, m, start, a, b;
	scanf("%d %d %d", &v, &m, &start);
	bool* checked = new bool[v + 1];
	fill(checked, checked + v + 1, false);
	for (i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		graph[a][b] = true;
		graph[b][a] = true;
	}
	dfs(start, checked);
	printf("\n");
	fill(checked, checked + v + 1, false);
	bfs(start, checked);
	printf("\n");
	delete[] checked;
	return 0;
}