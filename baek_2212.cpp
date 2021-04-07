#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void) {
	int n, k, ans, cnt;
	int arr[10000];
	int dis[9999];
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr+n);
	ans = arr[n-1] - arr[0];
	for(int i=0; i<n-1; i++)
		dis[i] = arr[i+1] - arr[i];
	sort(dis, dis+n-1);
	cnt = 1;
	for(int i=n-2; i>=0; i--){
		if(cnt==k)
			break;
		ans -= dis[i];
		cnt++;
	}
	printf("%d\n", ans);
}