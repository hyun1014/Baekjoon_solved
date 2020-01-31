#pragma warning(disable : 4996)
#include <stdio.h>

int main(void) {
	int n, m, i, j;
	scanf("%d %d", &n, &m);
	char arr[m][n];
	char str[m];
	for (i = 0; i < n; i++) {
		scanf("%s", str);
		for (j = (m - 1); j >= 0; j--) {
			if (str[(m - 1) - j] == 45)
				str[(m - 1) - j] = 124;
			else if (str[(m - 1) - j] == 124)
				str[(m - 1) - j] = 45;
			else if (str[(m - 1) - j] == 47)
				str[(m - 1) - j] = 92;
			else if (str[(m - 1) - j] == 92)
				str[(m - 1) - j] = 47;
			else if (str[(m - 1) - j] == 94)
				str[(m - 1) - j] = 60;
			else if (str[(m - 1) - j] == 60)
				str[(m - 1) - j] = 118;
			else if (str[(m - 1) - j] == 118)
				str[(m - 1) - j] = 62;
			else if (str[(m - 1) - j] == 62)
				str[(m - 1) - j] = 94;
			arr[j][i] = str[(m - 1) - j];
		}
	}
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}