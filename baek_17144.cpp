#include <stdio.h>

using namespace std;

int R, C, T, W;
int before[50][50];
int after[50][50];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

void resetboard(){
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			before[i][j] = after[i][j];
			after[i][j] = 0;
		}
	}
}

void wind(int w){
	int tmpin, tmpout;
	tmpin = 0;

	tmpout = after[w][C-1];
	for(int i=C-1; i>=2; i--)
		after[w][i] = after[w][i-1];
	after[w][1] = tmpin;
	tmpin = tmpout;

	tmpout = after[0][C-1];
	for(int i=0; i<=w-2; i++)
		after[i][C-1] = after[i+1][C-1];
	after[w-1][C-1] = tmpin;
	tmpin = tmpout;

	tmpout = after[0][0];
	for(int i=0; i<=C-3; i++)
		after[0][i] = after[0][i+1];
	after[0][C-2] = tmpin;
	tmpin = tmpout;

	for(int i=w-1; i>=2; i--)
		after[i][0] = after[i-1][0];
	after[1][0] = tmpin;
	
	w++;
	tmpin = 0;

	tmpout = after[w][C-1];
	for(int i=C-1; i>=2; i--)
		after[w][i] = after[w][i-1];
	after[w][1] = tmpin;
	tmpin = tmpout;

	tmpout = after[R-1][C-1];
	for(int i=R-1; i>=w+2; i--)
		after[i][C-1] = after[i-1][C-1];
	after[w+1][C-1] = tmpin;
	tmpin = tmpout;

	tmpout = after[R-1][0];
	for(int i=0; i<=C-3; i++)
		after[R-1][i] = after[R-1][i+1];
	after[R-1][C-2] = tmpin;
	tmpin = tmpout;

	for(int i=w+1; i<=R-3; i++)
		after[i][0] = after[i+1][0];
	after[R-2][0] = tmpout;
}

void spread(){
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			if(before[i][j]==0){
				continue;
			}
			else if(before[i][j] == -1){
				after[i][j] = -1;
			} else {
				int cnt = 0;
				for(int k=0; k<4; k++){
					int x = i + dx[k];
					int y = j + dy[k];
					if(x>=0 && x<R && y>=0 && y<C && before[x][y]!=-1){
						after[x][y] += before[i][j]/5;
						cnt++;
					}
				}
				after[i][j] += (before[i][j] - (before[i][j]/5)*cnt);
			}
		}
	}
}

int main(void) {
	int answer = 0;
	scanf("%d %d %d", &R, &C, &T);

	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			scanf("%d", &after[i][j]);
			if(after[i][j]==-1)
				W = i;
		}
	}
	W--;

	resetboard();

	for(int i=0; i<T; i++){
		spread();
		wind(W);
		resetboard();
	}
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
			answer += before[i][j];

	answer += 2;

	printf("%d\n", answer);

	return 0;
}