#pragma warning(disable : 4996)
#include <iostream>

using namespace std;

int main(void) {
	int n, c, i, j, money;
	double m, p;
	while (1) {
		scanf("%d %lf", &n, &m);
		if ((n == 0) && (m == 0.00))
			break;
		money = (int)(m * 100);
		int* kcal = new int[n + 1];
		int* price = new int[n + 1];
		int* dp = new int[money + 1];
		for (i = 0; i <= money; i++)
			dp[i] = 0;
		for (i = 1; i <= n; i++) {
			scanf("%d %lf", &kcal[i], &p);
			price[i] = (int)(p * 100);
		}
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= money; j++) {
				if (j >= price[i]) {
					if ((dp[j - price[i]] + kcal[i]) > dp[j]) {
						dp[j] = dp[j - price[i]] + kcal[i];
					}
				}
			}
		}
		printf("%d\n", dp[money]);
		delete[] kcal;
		delete[] price;
		delete[] dp;
	}
	return 0;
}