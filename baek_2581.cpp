#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning(disable : 4996)

using namespace std;

int main(void) {
	int m, n, min;
	scanf("%d %d", &m, &n);
	bool flag = false;
	int sum = 0;
	for (int i = m; i <= n; i++) {
		if (i == 2)
			printf("%d\n", i);
		for (int j = 2; j <= (i - 1); j++) {
			if (i % j == 0)
				break;
			if (j == (i - 1))
				printf("%d\n", i);
		}
	}
}
