#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;
int origin_board[20][20];
int board[20][20];
int tboard[20][20];
vector<int> dir_vec;
vector<pair<int,bool>> stk;
int N;

void ready_board(){
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			board[i][j] = origin_board[i][j];
}

void refresh_board(){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			board[i][j] = tboard[i][j];
			tboard[i][j] = 0;
		}
	}
}

void make_stk(int num){
	if(num!=0){
		if(stk.empty() || stk.back().first!=num || stk.back().second){
			stk.push_back(make_pair(num, false));
		} else {
			stk.back().first *= 2;
			stk.back().second = true;
		}
	}
}

void move(){
	ready_board();
	for(int i=0; i<5; i++){
		int dir = dir_vec[i];
		switch(dir){
			case 1:
				for(int j=0; j<N; j++){
					for(int k=0; k<N; k++)
						make_stk(board[j][k]);

					int stk_size = stk.size();
					for(int k=0; k<stk_size; k++)
						tboard[j][k] = stk[k].first;
					stk.clear();
				}
				break;
			case 2:
				for(int j=0; j<N; j++){
					for(int k=N-1; k>=0; k--)
						make_stk(board[j][k]);

					int stk_size = stk.size();
					for(int k=0; k<stk_size; k++)
						tboard[j][N-1-k] = stk[k].first;
					stk.clear();
				}
				break;
			case 3:
				for(int j=0; j<N; j++){
					for(int k=0; k<N; k++)
						make_stk(board[k][j]);

					int stk_size = stk.size();
					for(int k=0; k<stk_size; k++)
						tboard[k][j] = stk[k].first;
					stk.clear();
				}
				break;
			case 4:
				for(int j=0; j<N; j++){
					for(int k=N-1; k>=0; k--)
						make_stk(board[k][j]);

					int stk_size = stk.size();
					for(int k=0; k<stk_size; k++)
						tboard[N-1-k][j] = stk[k].first;
					stk.clear();
				}
				break;
		}
		refresh_board();
	}
}

void get_max(){
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			if(answer<board[i][j])
				answer = board[i][j];
}

void dfs(int dir){
	dir_vec.push_back(dir);
	if(dir_vec.size()==5){
		move();
		get_max();
	} else {
		for(int i=1; i<=4; i++){
			dfs(i);
		}
	}
	dir_vec.pop_back();
	return;
}

int main(void) {
	scanf("%d", &N);

	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%d", &origin_board[i][j]);

	for(int i=1; i<=4; i++)
		dfs(i);
	printf("%d\n", answer);

	return 0;
}