#pragma warning(disable : 4996)
#include <iostream>
using namespace std;
int main(void) {
	int i, j, l, sum, n, m, k;
	cin >> n >> m;
	int** arr0 = new int* [n];
	for (i = 0; i < n; i++)
		arr0[i] = new int[m];
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			cin >> arr0[i][j];

	cin >> m >> k;
	int** arr1 = new int* [m];
	for (i = 0; i < m; i++)
		arr1[i] = new int[k];
	for (i = 0; i < m; i++)
		for (j = 0; j < k; j++)
			cin >> arr1[i][j];

	int** arr2 = new int* [n];
	for (i = 0; i < n; i++)
		arr2[i] = new int[k];
	for (i = 0; i < n; i++) {
		for (j = 0; j < k; j++) {
			sum = 0;
			for (l = 0; l < m; l++)
				sum += (arr0[i][l] * arr1[l][j]);
			arr2[i][j] = sum;
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < k; j++)
			cout << arr2[i][j] << " ";
		cout << "\n";
	}
	return 0;
}