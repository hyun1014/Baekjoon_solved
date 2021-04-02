#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int t, n, a, b, answer, tmp;
	vector<pair<int,int>> arr;
	scanf("%d", &t);
	for(int tcase=0; tcase<t; tcase++){
		arr.clear();
		answer = 1;
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%d %d", &a, &b);
			arr.push_back(make_pair(a,b));
		}
		sort(arr.begin(), arr.end());
		tmp = arr[0].second;
		for(int i=1; i<n; i++){
			if(arr[i].second<tmp){
				tmp = arr[i].second;
				answer++;
				if(tmp==1)
					break;
			}
		}
		printf("%d\n", answer);
	}
    return 0;
}