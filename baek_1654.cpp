#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int main(void) {
	int k, i;
	long long n, left, right, mid, max, sum;
	scanf("%d %lld", &k, &n);
	long long* arr = new long long[k];
	for (i = 0; i < k; i++)
		scanf("%lld", &arr[i]);
	max = arr[0];
	for (i = 1; i < k; i++)
		if (arr[i] > max)
			max = arr[i];
	left = 1;
	right = max;
	while (left <= right) {
		sum = 0;
		mid = (left + right) / 2;
		for (i = 0; i < k; i++)
			sum += (arr[i] / mid);
		if (sum < n)
			right = mid - 1;
		else {
			left = mid + 1;
			max = mid;
		}
	}

	printf("%lld\n", max);
	delete[] arr;
	return 0;
}