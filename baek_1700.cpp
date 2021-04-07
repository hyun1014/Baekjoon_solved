#include <stdio.h>

using namespace std;

int main(void) {
	int n, k, next, tar;
	int cnt = 0, ans = 0;
	int plugin[100];
	int arr[100];
	scanf("%d %d", &n, &k);
	for(int i=0; i<k; i++)
		scanf("%d", &arr[i]);
	
	for(int i=0; i<k; i++){
		bool flag = false;
		for(int j=0; j<cnt; j++){
			if(plugin[j]==arr[i]){
				flag = true;
				break;
			}
		}
		if(flag)
			continue;
		else if (cnt<n){
			plugin[cnt] = arr[i];
			cnt++;
		} else {
			tar = -1;
			next = -1;
			for(int j=0; j<n; j++){
				int idx = -1;
				for(idx=i+1; idx<k; idx++){
					if(arr[idx]==plugin[j])
						break;
				}
				if(idx>next){
					tar = j;
					next = idx;
				}
			}
			plugin[tar] = arr[i];
			ans++;
		}
	}

	printf("%d\n", ans);
	return 0;
}