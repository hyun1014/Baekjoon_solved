#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning(disable : 4996)

using namespace std;

int main(void) {
	int m, n;
	scanf("%d %d", &n, &m);
	vector<string> chess;
	char str[52];
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		string s = str;
		chess.push_back(s);
	}
	int min = 64;
	for (int i = 0; i <= (n - 8); i++) {
		for (int j = 0; j <= (m - 8); j++) {
			int num = 0;
			for (int ii = 0; ii < 8; ii++) {
				for (int jj = 0; jj < 8; jj++) {
					if (ii % 2 == 0) {
						if (jj % 2 == 0 && chess[i + ii][j + jj] == 'B')
							num++;
						else if (jj % 2 == 1 && chess[i + ii][j + jj] == 'W')
							num++;
					}
					else {
						if (jj % 2 == 0 && chess[i + ii][j + jj] == 'W')
							num++;
						else if (jj % 2 == 1 && chess[i + ii][j + jj] == 'B')
							num++;
					}
				}
			}
			if (min > num)
				min = num;
			num = 0;
			for (int ii = 0; ii < 8; ii++) {
				for (int jj = 0; jj < 8; jj++) {
					if (ii % 2 == 0) {
						if (jj % 2 == 0 && chess[i + ii][j + jj] == 'W')
							num++;
						else if (jj % 2 == 1 && chess[i + ii][j + jj] == 'B')
							num++;
					}
					else {
						if (jj % 2 == 0 && chess[i + ii][j + jj] == 'B')
							num++;
						else if (jj % 2 == 1 && chess[i + ii][j + jj] == 'W')
							num++;
					}
				}
			}
			if (min > num)
				min = num;
		}
	}
	printf("%d", min);
	return 0;
}
