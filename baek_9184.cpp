#include <stdio.h>

using namespace std;
int main(void) {
	int w[21][21][21];
	for(int i=0; i<=20; i++){
		for(int j=0; j<=20; j++){
			for(int k=0; k<=20; k++){
				if(i==0 || j==0 || k==0)
					w[i][j][k] = 1;
				else if(i<j && j<k)
					w[i][j][k] = w[i][j][k-1] + w[i][j-1][k-1] - w[i][j-1][k];
				else
					w[i][j][k] = w[i-1][j][k] + w[i-1][j-1][k] + w[i-1][j][k-1] - w[i-1][j-1][k-1];
			}
		}
	}


	int a, b, c;
	while(true){
		scanf("%d %d %d", &a, &b, &c);
		if(a==-1 && b==-1 && c==-1)
			break;
		printf("w(%d, %d, %d) = ", a, b, c);
		if(a<=0 || b<=0 || c<=0)
			printf("1\n");
		else if (a>20 || b>20 || c>20)
			printf("%d\n", w[20][20][20]);
		else
			printf("%d\n", w[a][b][c]);
	}

	return 0;
}