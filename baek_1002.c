#define _USE_MATH_DEFINES
#pragma warning(disable : 4996)
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main(void) {
	int t, x0, y0, r0, x1, y1, r1, result;
	double distance;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d %d %d %d %d", &x0, &y0, &r0, &x1, &y1, &r1);
		if ((x0 == x1) && (y0 == y1) && (r0 == r1))
			result = -1;
		else if ((x0 == x1) && (y0 == y1) && (r0 != r1))
			result = 0;
		else {
			distance = sqrt((double)((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0)));
			if ((double)(r0 + r1) < distance)
				result = 0;
			else if ((double)(r0 + r1) == distance)
				result = 1;
			else {
				if ((double)(abs(r0 - r1)) == distance)
					result = 1;
				else if ((double)(abs(r0 - r1)) > distance)
					result = 0;
				else
					result = 2;
			}
		}
		printf("%d\n", result);
	}
	return 0;
}