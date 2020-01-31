#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
	int i, num, a, b, temp, idx, max;
	scanf("%d", &num);
	int* dp = new int[num + 1];
	fill(dp, dp + num + 1, 0);
	pair<int, int> p;
	vector<pair<int, int>> vec;
	vector<int> arr;
	vector<int> fans;
	vec.push_back(make_pair(0, 0));
	arr.push_back(0);
	for (i = 1; i <= 100000; i++) {
		arr.push_back(999999);
	}
	for (i = 1; i <= num; i++) {
		scanf("%d %d", &a, &b);
		p = make_pair(a, b);
		vec.push_back(p);
	}
	sort(vec.begin(), vec.end());
	max = dp[0];
	for (i = 1; i <= num; i++) {
		temp = vec[i].second;
		vector<int>::iterator itr = lower_bound(arr.begin(), arr.end(), temp);
		idx = itr - arr.begin() - 1;
		dp[i] = idx + 1;
		if (dp[i] > max)
			max = dp[i];
		if (arr[dp[i]] > temp) {
			arr[dp[i]] = vec[i].second;
		}
	}
	printf("%d\n", num - max);
	for (i = num; i > 0; i--) {
		if (dp[i] != max) {
			fans.push_back(vec[i].first);
		}
		else {
			max--;
		}
	}
	sort(fans.begin(), fans.end());
	for (i = fans.size() - 1; i >= 0; i--)
		printf("%d\n", fans[i]);

	return 0;
}