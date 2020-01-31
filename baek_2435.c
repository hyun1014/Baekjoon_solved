#pragma warning(disable : 4996)
#include <stdio.h>

int main(void) {
	int n, k, i, j, cnt, max;
	scanf("%d %d", &n, &k);
	int a = n - k + 1;
	int arr0[n];
	int arr1[a];
	for (i = 0; i < n; i++)
		scanf("%d", &arr0[i]);
	for (i = 0; i < a; i++)
		arr1[i] = 0;
	for (i = 0; i < a; i++) {
		for (cnt = 0; cnt < k; cnt++) {
			arr1[i] += arr0[i + cnt];
		}
	}
	max = arr1[0];
	for (i = 1; i < a; i++) {
		if (arr1[i] > max)
			max = arr1[i];
	}
	printf("%d\n", max);
	return 0;
}