#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int answer = 0;
int board[8][8];
bool visit[8][8];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
vector<vector<int>> vec (3, vector<int> (0, 0)); 

void clean_up(){
	int zero_size = vec[0].size();
	int one_size = vec[1].size();
	int two_size = vec[2].size();
	for(int i=0; i<zero_size; i++)
		board[vec[0][i]/M][vec[0][i]%M] = 0;
	for(int i=0; i<two_size; i++)
		board[vec[2][i]/M][vec[2][i]%M] = 2;
	for(int i=0; i<one_size; i++)
		board[vec[1][i]/M][vec[1][i]%M] = 1;
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			visit[i][j] = false;
}

int count_zero(){
	int res = 0;
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			if(board[i][j]==0)
				res++;

	return res;
}

void bfs(int start){
	int x, y, nx, ny;
	int cur;
	queue<int> que;
	que.push(start);
	while(!que.empty()){
		cur = que.front();
		que.pop();
		x = cur/M;
		y = cur%M;
		for(int i=0; i<4; i++){
			nx = x + dx[i];
			ny = y + dy[i];
			if(nx>=0 && nx<N && ny>=0 && ny<M && board[nx][ny]!=1 && !visit[nx][ny]){
				visit[nx][ny] = true;
				board[nx][ny] = 2;
				que.push(nx*M + ny);
			}
		}
	}
}

void permutation(int cnt){
	if(cnt==3){
		for(int i=0; i<N; i++)
			for(int j=0; j<M; j++)
				if(board[i][j]==2 && !visit[i][j])
					bfs(i*M + j);

		int tmp = count_zero();
		if(tmp>answer)
			answer = tmp;
		clean_up();
		return;
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(board[i][j]==0){
				board[i][j] = 1;
				vec[1].push_back(i*M+j);
				permutation(cnt+1);
				vec[1].pop_back();
				board[i][j] = 0;
			}
		}
	}
}

int main(void) {
	scanf("%d %d", &N, &M);
	int count[3] = {0,0,0};

	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			scanf("%d", &board[i][j]);

	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			visit[i][j] = false;
	
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			vec[board[i][j]].push_back(i*M+j);

	permutation(0);


	printf("%d\n", answer);
		
	return 0;
}