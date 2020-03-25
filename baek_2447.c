#pragma warning(disable : 4996)
#include <stdio.h>
void function(int x, int y, int num) {
	int cha = num;
	while (cha > 0) {
		if (((x / cha) % 3 == 1) && ((y / cha) % 3 == 1)) {
			putchar(' ');
			break;
		}
		else {
			if (cha == 1)
				putchar('*');
			cha /= 3;
		}
	}
}
int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			function(i, j, n);
		}
		putchar('\n');
	}
	return 0;
}
