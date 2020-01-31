#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#pragma warning(disable : 4996)

using namespace std;

int main(void) {
	int t;
	scanf("%d", &t);
	for (int cnt = 0; cnt < t; cnt++) {
		long long dot_x[4] = { 0, };
		long long dot_y[4] = { 0, };
		long long x, y;
		for (int i = 0; i < 4; i++)
			scanf("%lld %lld", &dot_x[i], &dot_y[i]);
		long long dis[6];
		int idx = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = i + 1; j < 4; j++) {
				dis[idx] = (dot_x[i] - dot_x[j]) * (dot_x[i] - dot_x[j]) + (dot_y[i] - dot_y[j]) * (dot_y[i] - dot_y[j]);
				idx++;
			}
		}
		sort(dis, dis+6);
		if (dis[0] == dis[1] && dis[1] == dis[2] && dis[2] == dis[3]) {
			if (dis[4] == dis[5])
				printf("1\n");
		}
		else
			printf("0\n");
	}
	return 0;
}