#pragma warning(disable : 4996)
#include <iostream>

using namespace std;

int main(void) {
	int n, i, d3;
	int d1 = 1, d2 = 2;
	scanf("%d", &n);
	if (n == 1)
		printf("1\n");
	else if (n == 2)
		printf("2\n");
	else {
		for (i = 3; i <= n; i++) {
			d3 = (d1 + d2) % 15746;
			d1 = d2;
			d2 = d3;
		}
		printf("%d\n", d3);
	}
	return 0;
}