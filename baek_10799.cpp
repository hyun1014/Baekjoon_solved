#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#pragma warning(disable : 4996)

using namespace std;

int main(void) {
	char laz[100001];
	scanf("%s", laz);
	string pipe = laz;
	int len = pipe.length();
	vector<int> stk;
	int num = 0, answer = 0;
	for (int i = 0; i < len; i++) {
		if (pipe[i] == '(') {
			num++;
		}
		else {
			if (i > 0 && pipe[i - 1] == '(') {
				num--;
				answer += num;
			}
			else {
				num--;
				answer++;
			}
		}
	}
	printf("%d\n", answer);
	return 0;
}