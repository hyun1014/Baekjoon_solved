#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>

void solution(int arr[], int root, int end) {
	int i;
	int leftLast = root;
	for (i = root + 1; i <= end; i++) {
		if (arr[i] < arr[root])
			leftLast++;
		else
			break;
	}

	if (leftLast != root)
		solution(arr, root + 1, leftLast);

	if (leftLast != end)
		solution(arr, leftLast + 1, end);
	printf("%d\n", arr[root]);
}

int main(void) {
	int node[10000];
	int idx = 0;
	int num;
	while (scanf("%d", &num) != -1)
		node[idx++] = num;
	solution(node, 0, idx - 1);
	return 0;
}