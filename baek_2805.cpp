#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void) {
	int n, m, front, rear, mid;
	long long sum;
	int tree[1000000];
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++)
		scanf("%d", &tree[i]);
	sort(tree, tree+n);
	front = 0, rear = tree[n-1];
	while(front<=rear){
		sum = 0;
		mid = (front+rear)/2;
		for(int i=0; i<n; i++)
			if(tree[i]>mid)
				sum += (long long)(tree[i]-mid);
		if(sum<(long long)m)
			rear = mid-1;
		else
			front = mid+1;
	}
	printf("%d\n", rear);
    return 0;
}