#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning(disable : 4996)

using namespace std;

int main(void) {
	int n, jari, tmp;
	scanf("%d", &n);
	tmp = n;
	jari = 0;
	while (tmp != 0) {
		tmp /= 10;
		jari++;
	}
	tmp = n - (9 * jari);
	for (int i = tmp; i <= n; i++) {
		int num = i;
		int temp = i;
		while (temp != 0) {
			num += (temp % 10);
			temp /= 10;
		}
		if (num == n) {
			printf("%d", i);
			break;
		}
		if (i == n)
			printf("0");
	}
	return 0;
}
