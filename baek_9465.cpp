#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int main(void) {
	int num, i, test, cnt;
	scanf("%d", &test);
	for (cnt = 0; cnt < test; cnt++) {
		scanf("%d", &num);
		int* a = new int[num + 1];
		int* b = new int[num + 1];
		int* dpa = new int[num + 1];
		int* dpb = new int[num + 1];
		for (i = 1; i <= num; i++)
			scanf("%d", &a[i]);
		for (i = 1; i <= num; i++)
			scanf("%d", &b[i]);
		dpa[0] = 0, dpb[0] = 0, a[0] = 0, b[0] = 0;
		dpa[1] = a[1];
		dpb[1] = b[1];
		for (i = 2; i <= num; i++) {
			if (dpb[i - 2] > dpb[i - 1])
				dpa[i] = dpb[i - 2] + a[i];
			else
				dpa[i] = dpb[i - 1] + a[i];
			if (dpa[i - 2] > dpa[i - 1])
				dpb[i] = dpa[i - 2] + b[i];
			else
				dpb[i] = dpa[i - 1] + b[i];
		}
		if (dpa[num] > dpb[num])
			printf("%d\n", dpa[num]);
		else
			printf("%d\n", dpb[num]);
		delete[] a;
		delete[] b;
		delete[] dpa;
		delete[] dpb;
	}
	return 0;
}