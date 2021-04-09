#include <stdio.h>

using namespace std;

int main(void) {
	int cur[3];
	int min[2][3];
	int max[2][3];
	int N, tmin, tmax;
	scanf("%d", &N);
	for(int i=0; i<3; i++){
		min[0][i] = 0;
		min[1][i] = 99999999;
		max[0][i] = 0;
		max[1][i] = -1;
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<3; j++)
			scanf("%d", &cur[j]);

		for(int j=0; j<3; j++){
			tmax = -1;
			tmin = 99999999;
			for(int k=-1; k<2; k++){
				if(j+k>=0 && j+k<3){
					if(min[i%2][j+k]<tmin)
						tmin = min[i%2][j+k];
					if(max[i%2][j+k]>tmax)
						tmax = max[i%2][j+k];
				}
			}
			min[(i+1)%2][j] = tmin + cur[j];
			max[(i+1)%2][j] = tmax + cur[j];
		}
	}
	tmax = -1;
	tmin = 99999999;
	for(int i=0; i<3; i++){
		if(tmax<max[N%2][i])
			tmax = max[N%2][i];
		if(tmin>min[N%2][i])
			tmin = min[N%2][i];
	}
	printf("%d %d\n", tmax, tmin);
		
	return 0;
}