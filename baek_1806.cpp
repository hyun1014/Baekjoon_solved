#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main(void) {
	int N, S, left, right, total;
	int answer[2];
	int arr[100000];
	scanf("%d %d", &N, &S);
	for(int i=0; i<N; i++)
		scanf("%d", &arr[i]);
	answer[0] = 0;
	answer[1] = N;
	left = 0;
	right = -1;
	total = 0;
	while(true){
		if(total>=S){
			if(right-left<answer[1]-answer[0]){
				answer[0] = left;
				answer[1] = right;
			}
			total -= arr[left];
			left++;
			if(left==N)
				break;
		} else {
			right++;
			if(right==N)
				break;
			total += arr[right];
		}
	}
	if(answer[0]==0 && answer[1]==N)
		answer[1] = -1;
	printf("%d\n", answer[1]-answer[0]+1);
	return 0;
}