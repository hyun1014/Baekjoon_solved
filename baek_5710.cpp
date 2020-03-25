#pragma warning(disable : 4996)
#include <iostream>

using namespace std;

int foo(int price) {
	int result;
	if (price >= 0 && price <= 200)
		result = price / 2;
	else if (price > 200 && price <= 29900)
		result = 100 + (price - 200) / 3;
	else if (price > 29900 && price <= 4979900)
		result = 100 + 9900 + (price - 29900) / 5;
	else
		result = 100 + 9900 + 990000 + (price - 4979900) / 7;
	return result;
}
int fooo(int elec) {
	int result;
	if (elec >= 1 && elec <= 100)
		result = elec * 2;
	else if (elec >= 101 && elec <= 10000)
		result = 200 + (elec - 100) * 3;
	else if (elec >= 10001 && elec <= 1000000)
		result = 200 + 29700 + (elec - 10000) * 5;
	else
		result = 200 + 29700 + 4950000 + (elec - 1000000) * 7;
	return result;
}

int main(void) {
	int a, b, elecsum, cha, sang;
	while (1) {
		scanf("%d %d", &a, &b);
		if (a == 0 && b == 0)
			break;
		elecsum = foo(a);
		sang = elecsum / 2;

		while (1) {
			if (fooo(elecsum - sang) - fooo(sang) == b)
				break;
			else
				sang--;
		}
		printf("%d\n", fooo(sang));
	}
	return 0;
}