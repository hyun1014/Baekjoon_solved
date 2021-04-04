#include <stdio.h>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int main(void) {
	int n, first, second, tar, ans;
	ans = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &tar);
		pq.push(tar);
	}
	while(pq.size()>1){
		first = pq.top();
		pq.pop();
		second = pq.top();
		pq.pop();
		ans += (first+second);
		pq.push(first+second);
	}
	printf("%d\n", ans);
    return 0;
}