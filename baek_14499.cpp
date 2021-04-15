#include <stdio.h>

using namespace std;

int N, M, x, y, K, direc;

int board[20][20];
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};

int dice[6] = {0, 0, 0, 0, 0, 0};

void roll_dice(int dir){
	int tmp;
	switch (dir)
	{
		case 1:
			tmp = dice[4];
			dice[4] = dice[1];
			dice[1] = dice[5];
			dice[5] = dice[3];
			dice[3] = tmp;
			break;
		case 2:
			tmp = dice[5];
			dice[5] = dice[1];
			dice[1] = dice[4];
			dice[4] = dice[3];
			dice[3] = tmp;
			break;
		case 3:
			tmp = dice[0];
			for(int i=0; i<3; i++)
				dice[i] = dice[i+1];
			dice[3] = tmp;
			break;
		case 4:
			tmp = dice[3];
			for(int i=3; i>0; i--)
				dice[i] = dice[i-1];
			dice[0] = tmp;
			break;
		default:
			break;
	}
}

bool dir_check(int dir){
	int xx = x + dx[dir];
	int yy = y + dy[dir];
	return (xx>=0 && xx<N && yy>=0 && yy<M);
}



int main(void) {
	scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			scanf("%d", &board[i][j]);
	for(int i=0; i<K; i++){
		scanf("%d", &direc);
		if(dir_check(direc)){
			x += dx[direc];
			y += dy[direc];
			roll_dice(direc);
			if(board[x][y]==0)
				board[x][y] = dice[3];
			else {
				dice[3] = board[x][y];
				board[x][y] = 0;
			}
			printf("%d\n", dice[1]);
		}
	}
	return 0;
}