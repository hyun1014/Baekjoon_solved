#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int answer = 0;
int R, C, M;
int r, c, s, d, z;
pair<int, pair<int,int>> board[101][101];
pair<int, pair<int,int>> tboard[101][101];

void init_board(){
	for(int i=1; i<=R; i++){
		for(int j=1; j<=C; j++){
			board[i][j] = make_pair(0, make_pair(0, 0));
			tboard[i][j] = make_pair(0, make_pair(0, 0));
		}
	}
}

void refresh_board(){
	for(int i=1; i<=R; i++){
		for(int j=1; j<=C; j++){
			board[i][j] = tboard[i][j];
			tboard[i][j] = make_pair(0, make_pair(0, 0));
		}
	}
}

void catch_shark(int idx){
	for(int i=1; i<=R; i++){
		if(board[i][idx].first!=0){
			answer += board[i][idx].first;
			board[i][idx] = make_pair(0, make_pair(0, 0));
			break;
		}
	}
}

void shark_move(int x, int y){
	pair<int, pair<int,int>> cur = board[x][y];
	int move_cnt = cur.second.first;
	int dir = cur.second.second;
	int xx = x, yy = y;
	while(move_cnt>0){
		switch(dir){
			case 1:
				if(move_cnt>=xx-1){
					move_cnt -= (xx-1);
					xx = 1;
					dir = 2;
				} else {
					xx -= move_cnt;
					move_cnt = 0;
				}
				break;
			case 2:
				if(move_cnt>=R-xx){
					move_cnt -= (R-xx);
					xx = R;
					dir = 1;
				} else {
					xx += move_cnt;
					move_cnt = 0;
				}
				break;
			case 3:
				if(move_cnt>=C-yy){
					move_cnt -= (C-yy);
					yy = C;
					dir = 4;
				} else {
					yy += move_cnt;
					move_cnt = 0;
				}
				break;
			case 4:
				if(move_cnt>=yy-1){
					move_cnt -= (yy-1);
					yy = 1;
					dir = 3;
				} else {
					yy -= move_cnt;
					move_cnt = 0;
				}
				break;
		}
	}
	if(tboard[xx][yy].first==0 || tboard[xx][yy].first<cur.first){
		tboard[xx][yy] = make_pair(cur.first, make_pair(cur.second.first, dir));
	}
}

void scan_shark(){
	for(int i=1; i<=R; i++)
		for(int j=1; j<=C; j++)
			if(board[i][j].first!=0)
				shark_move(i, j);
}

int main(void) {
	scanf("%d %d %d", &R, &C, &M);
	init_board();

	for(int i=0; i<M; i++){
		scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
		board[r][c] = make_pair(z, make_pair(s, d));
	}

	for(int i=1; i<=C; i++){
		catch_shark(i);
		scan_shark();
		refresh_board();
	}

	printf("%d\n", answer);
	
	return 0;
}