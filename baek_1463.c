#pragma warning(disable : 4996)
#include <stdio.h>

int main(void) {
	int num, i;
	int temp = 0;
	scanf("%d", &num);
	int arr[num + 1];
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;
	for (i = 4; i <= num; i++) {
		arr[i] = arr[i - 1] + 1;
		if (i % 2 == 0) {
			temp = arr[i / 2] + 1;
			if (temp < arr[i])
				arr[i] = temp;
		}
		if (i % 3 == 0) {
			temp = arr[i / 3] + 1;
			if (temp < arr[i])
				arr[i] = temp;
		}
	}
	printf("%d\n", arr[num]);
	return 0;
}