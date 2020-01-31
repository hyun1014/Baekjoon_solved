#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#pragma warning(disable : 4996)

using namespace std;
int* parent = new int[10001];

struct Edge {
	int from;
	int to;
	int weight;
};
struct cmp {
	bool operator()(Edge t, Edge u) {
		return t.weight > u.weight;
	}
};

int find(int u) {
	if (u == parent[u])
		return u;
	return parent[u] = find(parent[u]);
}

void merge_k(int a, int b) {
	parent[find(a)] = find(b);
}

int main() {
	Edge ed;
	priority_queue<Edge, vector<Edge>, cmp> que;
	int v, e, a, b, c, i, sum;
	Edge temp;
	sum = 0;
	scanf("%d %d", &v, &e);
	for (i = 1; i <= v; i++)
		parent[i] = i;

	for (i = 0; i < e; i++) {
		scanf("%d %d %d", &a, &b, &c);
		ed.from = a;
		ed.to = b;
		ed.weight = c;
		que.push(ed);
	}
	while (!que.empty()) {
		temp = que.top();
		que.pop();
		if (find(temp.from) != find(temp.to)) {
			sum += temp.weight;
			merge_k(temp.from, temp.to);
		}
	}
	printf("%d\n", sum);
	return 0;
}