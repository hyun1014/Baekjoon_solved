#include <stdio.h>
#include <queue>

using namespace std;

int main(void) {
	priority_queue<int, vector<int>, greater<int>> min_heap;
	priority_queue<int, vector<int>, less<int>> max_heap;
	int N, tar;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &tar);
		if(i%2==1)
			min_heap.push(tar);
		else
			max_heap.push(tar);
		if(!min_heap.empty() && !max_heap.empty() && max_heap.top()>min_heap.top()){
			int tmp0 = min_heap.top();
			int tmp1 = max_heap.top();
			min_heap.pop();
			max_heap.pop();
			min_heap.push(tmp1);
			max_heap.push(tmp0);
		}
		printf("%d\n", max_heap.top());
	}
	return 0;
}