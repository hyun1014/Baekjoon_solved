#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main(void) {
	int t, n, idx, idx1, answer, tmp;
	int arr[10000];
	int arr1[10000];
	scanf("%d", &t);
	for(int tcase=0; tcase<t; tcase++){
		answer = -1;
		scanf("%d", &n);
		for(int i=0; i<n; i++)
			scanf("%d", &arr[i]);
		sort(arr, arr+n);
		tmp = 0;
		
		for(idx=0; idx<n; idx+=2){
			arr1[tmp] = arr[idx];
			tmp++;
		}
		if(idx==n)
			idx = n-1;
		else
			idx = n-2;
		for( ; idx>0; idx-=2){
			arr1[tmp] = arr[idx];
			tmp++;
		}
		for(int i=0; i<n-1; i++)
			if(abs(arr1[i]-arr1[i+1])>answer)
				answer = abs(arr1[i]-arr1[i+1]);
		printf("%d\n", answer);
	}
    return 0;
}