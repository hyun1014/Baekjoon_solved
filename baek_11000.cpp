#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp {
	bool operator()(pair<int,int> a, pair<int,int> b){
		if(a.first==b.first)
			return a.second > b.second;
		else
			return a.first > b.first;
	}
};

int main(void) {
	priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
	pair<int,int> cur;
	int n, start, finish, cnt, ans;
	cnt = 0;
	ans = 0;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d %d", &start, &finish);
		pq.push(make_pair(start, 1));
		pq.push(make_pair(finish, 0));
	}
	while(!pq.empty()){
		cur = pq.top();
		pq.pop();
		if(cur.second)
			cnt++;
		else
			cnt--;
		if(cnt>ans)
			ans = cnt;
	}
	printf("%d\n", ans);
}