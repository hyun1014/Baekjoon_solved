#pragma warning(disable : 4996)
#include <iostream>

using namespace std;
int main(void) {
	int n, i;
	scanf("%d", &n);
	long long d0 = 0;
	long long d1 = 1;
	long long d2 = 0;
	if (n == 0)
		printf("%lld\n", d0);
	else if (n == 1)
		printf("%lld\n", d1);
	else {
		for (i = 2; i <= n; i++) {
			d2 = d0 + d1;
			d0 = d1;
			d1 = d2;
		}
		printf("%lld\n", d2);
	}
	return 0;
}