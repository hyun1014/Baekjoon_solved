#pragma warning(disable : 4996)
#include <iostream>

using namespace std;

int main(void) {
	int n, m, i, j, k, price;
	scanf("%d %d", &n, &m);
	int** d = new int* [n + 1];
	for (i = 0; i <= n; i++)
		d[i] = new int[n + 1];
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++) {
			if (i == j)
				d[i][j] = 0;
			else
				d[i][j] = 100000;
		}
	for (k = 0; k < m; k++) {
		scanf("%d %d %d", &i, &j, &price);
		if (d[i][j] > price)
			d[i][j] = price;
	}
	for (k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (d[i][j] == 100000)
				d[i][j] = 0;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}
	return 0;
}