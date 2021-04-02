#include <stdio.h>
#include <algorithm>
#include <functional>

using namespace std;

int main(void) {
	int n, answer;
	int arr[100000];
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr+n, greater<>());
	answer = arr[0];
	for(int i=1; i<n; i++)
		if(answer<arr[i]*(i+1))
			answer = arr[i]*(i+1);
	printf("%d\n", answer);
    return 0;
}