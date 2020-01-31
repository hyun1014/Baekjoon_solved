#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<pair<int, int>> graph[20001];

vector<int> dijkstra(int start, int vertex) {
	int i = 0;
	int cost, vert, neigh_cost, neigh_vert, adjnum;
	vector<int> distance(vertex + 1, 999999);
	distance[start] = 0;
	priority_queue<pair<int, int>> que;
	que.push(make_pair(0, start));
	while (!que.empty()) {
		cost = -(que.top().first);
		vert = que.top().second;
		que.pop();
		adjnum = graph[vert].size();
		for (i = 0; i < adjnum; i++) {
			neigh_cost = cost + graph[vert][i].first;
			neigh_vert = graph[vert][i].second;
			if (distance[neigh_vert] > neigh_cost) {
				distance[neigh_vert] = neigh_cost;
				que.push(make_pair(-neigh_cost, neigh_vert));
			}
		}
	}
	return distance;
}

int main(void) {
	int v, e, i, start, from, to, dis;
	scanf("%d %d", &v, &e);
	scanf("%d", &start);
	for (i = 0; i < e; i++) {
		scanf("%d %d %d", &from, &to, &dis);
		graph[from].push_back(make_pair(dis, to));
	}
	vector<int> dist;
	dist = dijkstra(start, v);
	for (i = 1; i <= v; i++) {
		if (dist[i] == 999999)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}
	return 0;
}