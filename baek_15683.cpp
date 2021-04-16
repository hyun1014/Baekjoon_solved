#include <stdio.h>
#include <vector>
#include <algorithm>
#include <unistd.h>

using namespace std;

int answer = 64;
int N, M;
int board[8][8];

vector<pair<int,int>> watch[8];

void scan(int x, int y, int cnt);

void go_up(int x, int y, int cctv){
	for(int i=x-1; i>=0; i--){
		if(board[i][y]==6)
			break;
		else if (board[i][y]<=0) {
			board[i][y]--;
			watch[cctv].push_back(make_pair(i, y));
		}
	}
}

void go_down(int x, int y, int cctv){
	for(int i=x+1; i<N; i++){
		if(board[i][y]==6)
			break;
		else if (board[i][y]<=0) {
			board[i][y]--;
			watch[cctv].push_back(make_pair(i, y));
		}
	}
}

void go_left(int x, int y, int cctv){
	for(int i=y-1; i>=0; i--){
		if(board[x][i]==6)
			break;
		else if (board[x][i]<=0){
			board[x][i]--;
			watch[cctv].push_back(make_pair(x, i));
		}
	}
}

void go_right(int x, int y, int cctv){
	for(int i=y+1; i<M; i++){
		if(board[x][i]==6)
			break;
		else if (board[x][i]<=0){
			board[x][i]--;
			watch[cctv].push_back(make_pair(x, i));
		}
	}
}

void clean_up(int cctv){
	int vec_len = watch[cctv].size();
	for(int i=0; i<vec_len; i++)
		board[watch[cctv][i].first][watch[cctv][i].second]++;
	watch[cctv].clear();
}

void cctv_one(int x, int y, int xx, int yy, int cnt){
	go_up(x, y, cnt);
	scan(xx, yy, cnt+1);
	clean_up(cnt);
	go_down(x, y, cnt);
	scan(xx, yy, cnt+1);
	clean_up(cnt);
	go_left(x, y, cnt);
	scan(xx, yy, cnt+1);
	clean_up(cnt);
	go_right(x, y, cnt);
	scan(xx, yy, cnt+1);
	clean_up(cnt);
}

void cctv_two(int x, int y, int xx, int yy, int cnt){
	go_up(x, y, cnt);
	go_down(x, y, cnt);
	scan(xx, yy, cnt+1);
	clean_up(cnt);
	go_left(x, y, cnt);
	go_right(x, y, cnt);
	scan(xx, yy, cnt+1);
	clean_up(cnt);
}

void cctv_three(int x, int y, int xx, int yy, int cnt){
	go_up(x, y, cnt);
	go_left(x, y, cnt);
	scan(xx, yy, cnt+1);
	clean_up(cnt);
	go_left(x, y, cnt);
	go_down(x, y, cnt);
	scan(xx, yy, cnt+1);
	clean_up(cnt);
	go_down(x, y, cnt);
	go_right(x, y, cnt);
	scan(xx, yy, cnt+1);
	clean_up(cnt);
	go_right(x, y, cnt);
	go_up(x, y, cnt);
	scan(xx, yy, cnt+1);
	clean_up(cnt);
}

void cctv_four(int x, int y, int xx, int yy, int cnt){
	go_up(x, y, cnt);
	go_left(x, y, cnt);
	go_down(x, y, cnt);
	scan(xx, yy, cnt+1);
	clean_up(cnt);
	go_left(x, y, cnt);
	go_down(x, y, cnt);
	go_right(x, y, cnt);
	scan(xx, yy, cnt+1);
	clean_up(cnt);
	go_down(x, y, cnt);
	go_right(x, y, cnt);
	go_up(x, y, cnt);
	scan(xx, yy, cnt+1);
	clean_up(cnt);
	go_right(x, y, cnt);
	go_up(x, y, cnt);
	go_left(x, y, cnt);
	scan(xx, yy, cnt+1);
	clean_up(cnt);
}

void cctv_five(int x, int y, int xx, int yy, int cnt){
	go_up(x, y, cnt);
	go_left(x, y, cnt);
	go_right(x, y, cnt);
	go_down(x, y, cnt);
	scan(xx, yy, cnt+1);
	clean_up(cnt);
}

void scan(int x, int y, int cnt){
	int tmp = 0;
	for(int i=x; i<N; i++){
		int j;
		if(i!=x)
			j = 0;
		else
			j = y;
		for( ; j<M; j++){
			int cctv;
			if(board[i][j]>0 && board[i][j]<6){
				cctv = board[i][j];
				int xx, yy;
				if(j==M-1){
					xx = i+1;
					yy = 0;
				} else {
					xx = i;
					yy = j+1;
				}
				switch(cctv){
					case 1:
						cctv_one(i, j, xx, yy, cnt);
						break;
					case 2:
						cctv_two(i, j, xx, yy, cnt);
						break;
					case 3:
						cctv_three(i, j, xx, yy, cnt);
						break;
					case 4:
						cctv_four(i, j, xx, yy, cnt);
						break;
					case 5:
						cctv_five(i, j, xx, yy, cnt);
						break;
				}
			}
		}
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(board[i][j]==0)
				tmp++;
		}
	}
	if(tmp<answer)
		answer = tmp;
}


int main(void) {
	scanf("%d %d", &N, &M);

	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			scanf("%d", &board[i][j]);

	scan(0, 0, 0);

	printf("%d\n", answer);
	return 0;
}