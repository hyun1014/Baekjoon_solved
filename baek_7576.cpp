#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

queue<int> q;
vector<vector<int>> v;
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
int d[4] = {-1,-10000,1,10000};
int ctr[2] = {0,0};
int cnt = 0;
int tomato = 0;

void bfs(int m, int n){
    int cur, x, y;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            if(v[i][j]==1){
                q.push(i*10000+j);
                ctr[cnt%2]++;
            }
        }
    }
    while(!q.empty()){
        cur = q.front();
        q.pop();
        x = cur/10000;
        y = cur%10000;
        for(int i=0 ; i<4 ; i++){
            if(v[x+dx[i]][y+dy[i]]==0){
                q.push(cur+d[i]);
                v[x+dx[i]][y+dy[i]]++;
                tomato--;
                ctr[(cnt+1)%2]++;
            }
        }
        ctr[cnt%2]--;
        if(ctr[cnt%2]==0)
            cnt++;
    }
}

int main(void){
    int m, n;
    bool flag = true;
    scanf("%d %d", &m, &n);
    v.assign(n+2, vector<int>(m+2, -1));
    for(int i=0 ; i<n+2 ; i++){
        v[i][0] = -1;
        v[i][m+1] = -1;
    }
    for(int i=0 ; i<m+2 ; i++){
        v[0][i] = -1;
        v[n+1][i] = -1;
    }
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            scanf("%d", &v[i][j]);
            if(v[i][j]==0)
                tomato++;
        }
    }
    bfs(m,n);
    if(tomato==0)
        printf("%d\n", cnt-1);
    else
        printf("-1\n");   
    return 0;
}