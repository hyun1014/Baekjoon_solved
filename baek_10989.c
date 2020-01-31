#pragma warning(disable : 4996)
#include <stdio.h>

int main(void) {
	int number[10000];
	int num, n, i, j;
	for (i = 0; i < 10000; i++)
		number[i] = 0;
	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		scanf("%d", &n);
		number[n - 1]++;
	}
	for (i = 0; i < 10000; i++) {
		if (number[i] != 0) {
			for (j = 0; j < number[i]; j++)
				printf("%d\n", i + 1);
		}
	}
	return 0;
}