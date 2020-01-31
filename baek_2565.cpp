#pragma warning(disable : 4996)
#include <iostream>
#include <algorithm>
using namespace std;
int node[501];

int main(void) {
	int n, i, j, temp, result, a, idx;
	scanf("%d", &n);
	int* arr = new int[n + 1];
	int* num = new int[n + 1];
	arr[0] = 999;
	for (i = 1; i <= n; i++) {
		scanf("%d %d", &idx, &a);
		node[idx] = a;
	}
	idx = 1;
	for (i = 1; i <= 500; i++)
		if (node[i] != 0)
			arr[idx++] = node[i];
	fill(num, num + n + 1, 1);
	for (i = 1; i <= n; i++) {
		for (j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				temp = num[j] + 1;
				if (num[i] < temp)
					num[i] = temp;
			}
		}
	}
	result = num[0];
	for (i = 0; i <= n; i++)
		if (result < num[i])
			result = num[i];
	result = n - result;
	printf("%d\n", result);
	return 0;
}