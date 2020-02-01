#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

#pragma warning(disable : 4996)

using namespace std;

int main(void) {
	int n, target, x, y;
	int a = 0, b = 0;
	scanf("%d %d", &n, &target);
	vector<vector<int>> vec (n, vector<int> (n, 0));
	x = n / 2;
	y = n / 2;
	vec[x][y] = 1;
	int dir = 1;
	int num = 2;
	int count = 2;
	while (x != 0 || y != 0) {
		switch (dir) {
			case 1:
				x--;
				for (int i = 0; i < count; i++) {
					vec[x][y] = num;
					if (num == target) {
						a = x, b = y;
					}
					num++;
					if (i != (count - 1))
						y++;
				}
				dir = 2;
				break;
			case 2:
				x++;
				for (int i = 0; i < count; i++) {
					vec[x][y] = num;
					if (num == target) {
						a = x, b = y;
					}
					num++;
					if (i != (count - 1))
						x++;
				}
				dir = 3;
				break;
			case 3:
				y--;
				for (int i = 0; i < count; i++) {
					vec[x][y] = num;
					if (num == target) {
						a = x, b = y;
					}
					num++;
					if (i != (count - 1))
						y--;
				}
				dir = 4;
				break;
			case 4:
				x--;
				for (int i = 0; i < count; i++) {
					vec[x][y] = num;
					if (num == target) {
						a = x, b = y;
					}
					num++;
					if (i != (count - 1))
						x--;
				}
				dir = 1;
				count += 2;
				break;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", vec[i][j]);
		}
		printf("\n");
	}
	printf("%d %d\n", a+1, b+1);
	return 0;
}
