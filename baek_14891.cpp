#include <stdio.h>

using namespace std;

char wheel[5][9];

void cycle(int num, int dir){
	int tmp;
	if(dir==1){
		tmp = wheel[num][7];
		for(int i=6; i>=0; i--)
			wheel[num][i+1] = wheel[num][i];
		wheel[num][0] = tmp;
	} else if (dir==-1){
		tmp = wheel[num][0];
		for(int i=1; i<8; i++)
			wheel[num][i-1] = wheel[num][i];
		wheel[num][7] = tmp;
	}
}

int main(void) {
	int K, tar, dir;
	int answer = 0;
	int cyc[5] = {0,0,0,0,0};
	for(int i=1; i<=4; i++)
		scanf("%s", wheel[i]);
	
	scanf("%d", &K);

	for(int i=0; i<K; i++){
		for(int j=1; j<5; j++)
			cyc[j] = 0;
		scanf("%d %d", &tar, &dir);

		cyc[tar] = dir;
		int cur_tar = tar-1;
		int cur_dir = dir;
		while(cur_tar>0){
			if(wheel[cur_tar][2]!=wheel[cur_tar+1][6]){
				cur_dir *= -1;
				cyc[cur_tar] = cur_dir;
				cur_tar--;
			} else {
				break;
			}
		}
		cur_tar = tar+1;
		cur_dir = dir;
		while(cur_tar<5){
			if(wheel[cur_tar][6]!=wheel[cur_tar-1][2]){
				cur_dir *= -1;
				cyc[cur_tar] = cur_dir;
				cur_tar++;
			} else {
				break;
			}
		}
		for(int i=1; i<=4; i++)
			cycle(i, cyc[i]);
	}

	tar = 1;
	for(int i=1; i<=4; i++){
		if(wheel[i][0]=='1')
			answer += tar;
		tar *= 2;
	}

	printf("%d\n", answer);

	return 0;
}