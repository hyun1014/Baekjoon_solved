#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void) {
	int n, k, front, rear, mid, sum, answer;
	scanf("%d %d", &n, &k);
	front = 1, rear = n*n;
	while(front<=rear){
		sum = 0;
		mid = (front+rear)/2;
		for(int i=1; i<=n; i++){
			if(i>mid)
				break;
			sum += min(mid/i, n);
		}
		if(sum<k){
			front = mid+1;
		}
		else {
			answer = mid;
			rear = mid-1;
		}
	}
	printf("%d\n", answer);
    return 0;
}