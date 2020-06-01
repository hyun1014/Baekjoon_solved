#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

queue<int> q;
char ch[102][102]; // 1인가 0인가
bool v[102][102]; // visited?
int n, m;
int cnt = 0; // 지나온 횟수
int dx[4] = {0,-1,0,1}; // 좌표 이동
int dy[4] = {-1,0,1,0}; // 좌표 이동
int d[4] = {-1,-1000,1,1000}; // 좌표 이동
int ctr[2] = {1,0}; // 길이 cur짜리가 queue에 몇개 남아있는가

void bfs(int tar){
    q.push(1001);
    while(!q.empty()){
        int cur = q.front();
        int x = cur/1000;
        int y = cur%1000;
        q.pop();
        if(cur==tar){ // 찾음
            printf("%d\n", cnt+1);
            return;
        }
        for(int i=0 ; i<4 ; i++){
            if(!v[x+dx[i]][y+dy[i]] && ch[x+dx[i]][y+dy[i]]=='1'){
                v[x+dx[i]][y+dy[i]] = true;
                q.push(cur+d[i]);
                ctr[(cnt+1)%2]++;
            }
        }
        ctr[cnt%2]--;
        if(ctr[cnt%2]==0) // cnt짜리 경로 탐색 완료 (cnt 길이의 경로는 없음)
            cnt++;
    }
}

int main(void){
    scanf("%d %d", &n, &m);
    for(int i=1 ; i<=n ; i++)
        scanf("%s", ch[i]+1);
    int tar = n*1000 + m;
    bfs(tar);
    return 0;
}