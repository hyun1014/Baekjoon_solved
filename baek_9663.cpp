#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int cnt = 0;
int n;
vector<int> stk;
void dfs(int num) {
	stk.push_back(num);
	int stksize = stk.size();
	if (stksize == n)
		cnt++;
	else {
		vector<int>::iterator itr;
		for (int i = 0; i < n; i++) {
			itr = find(stk.begin(), stk.end(), i);
			if (itr == stk.end()) {
				for (int j = 0; j < stksize; j++) {
					if (abs(stk[j] - i) == abs(stksize - j))
						break;
					if (j == (stksize - 1))
						dfs(i);
				}
			}
		}
	}
	stk.pop_back();
}

int main(void) {
	scanf("%d", &n);
	vector<int> s;
	for (int i = 0; i < n; i++)
		dfs(i);
	printf("%d", cnt);
	return 0;
}