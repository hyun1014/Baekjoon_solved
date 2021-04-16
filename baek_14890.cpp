#include <stdio.h>
#include <math.h>

using namespace std;

int N, L, cur, lv, answer, tmp;
int board[100][100];
int tboard[100][100];
bool xroad[100];
bool yroad[100];
bool pedal[100][100];

void clean_pedal(){
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			pedal[i][j] = false;
}

void spin_board(){
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			tboard[N-1-j][i] = board[i][j];
	
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			board[i][j] = tboard[i][j];
}


void scan_board(){
	for(int i=0; i<N; i++){
		cur = 0;
		lv = board[i][0];
		while(cur<N-1){
			if(board[i][cur+1]==lv){
				cur++;
				continue;
			} else {
				bool flag = true;
				if(lv>board[i][cur+1]){
					if(cur+L>=N || lv-board[i][cur+1]!=1)
						break;
					tmp = board[i][cur+1];
					for(int j=1; j<=L; j++){
						if(board[i][cur+j]!=tmp || pedal[i][cur+j]){
							flag = false;
							break;
						}
					}
					if(!flag)
						break;
					else {
						for(int j=1; j<=L; j++)
							pedal[i][cur+j] = true;
						cur += L;
						lv = tmp;
					}
				} else {
					if(cur-L+1<0 || board[i][cur+1]-lv!=1)
						break;
					tmp = board[i][cur];
					for(int j=1; j<=L-1; j++){
						if(board[i][cur-j]!=tmp || pedal[i][cur-j]){
							flag = false;
							break;
						}
					}
					if(flag && (cur-L==-1 || board[i][cur-L]==tmp || board[i][cur-L]==tmp-1)){
						for(int j=0; j<=L-1; j++)
							pedal[i][cur-j] = true;
						cur++;
						lv = board[i][cur];
					} else {
						break;
					}
				}
			}
		}
		if(cur==N-1){
			answer++;
		}
	}
}

int main(void) {
	answer = 0;
	scanf("%d %d", &N, &L);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%d", &board[i][j]);

	scan_board();
	spin_board();
	clean_pedal();
	scan_board();

	printf("%d\n", answer);
	
	return 0;
}