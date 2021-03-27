#include <stdio.h>
#include <stack>

using namespace std;

int main(void) {
	int arr[1000000];
	int answer[1000000];
	int n;
	scanf("%d", &n);
	fill_n(answer, n, -1);
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	stack<pair<int,int>> stk;
	stk.push(make_pair(0, arr[0]));
	for(int i=1; i<n; i++){
		while(!stk.empty() && stk.top().second<arr[i]){
			answer[stk.top().first] = arr[i];
			stk.pop();
		}
		stk.push(make_pair(i, arr[i]));
	}
	for(int i=0; i<n; i++)
		printf("%d ", answer[i]);

	return 0;
}