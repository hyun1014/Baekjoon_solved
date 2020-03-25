#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning(disable : 4996)

using namespace std;

int main(void) {
	int n, w, h;
	scanf("%d", &n);
	vector<pair<pair<int, int>, int>> v;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &w, &h);
		v.push_back(make_pair(make_pair(w, h), 1));
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i].first.first < v[j].first.first && v[i].first.second < v[j].first.second)
				v[i].second++;
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d\n", v[i].second);
	return 0;
}
