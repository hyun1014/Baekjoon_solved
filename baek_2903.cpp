#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int main(void) {
	int i, n, square, result;
	cin >> n;
	square = 1;
	for (i = 0; i < n; i++)
		square *= 2;
	result = (square + 1) * (square + 1);
	cout << result << endl;
	return 0;
}