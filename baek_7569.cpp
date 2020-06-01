#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

queue<long long> q;
vector<vector<vector<int>>> v;
int dx[6] = {0,-1,0,1,0,0};
int dy[6] = {-1,0,1,0,0,0};
int dz[6] = {0,0,0,0,1,-1};
int d[6] = {-1000,-1000000,1000,1000000,1,-1};
int ctr[2] = {0,0};
int cnt = 0;
int tom = 0;

void bfs(int m, int n, int h){
    int cur, x, y, z;
    for(int k=1 ; k<=h ; k++)
        for(int i=1 ; i<=n ; i++)
            for(int j=1 ; j<=m ; j++)
                if(v[i][j][k]==1){
                    q.push(i*1000000+j*1000+k);
                    ctr[cnt%2]++;
                }
    while(!q.empty()){
        cur = q.front();
        q.pop();
        x = cur/1000000;
        y = (cur%1000000)/1000;
        z = cur%1000;
        for(int i=0 ; i<6 ; i++)
            if(v[x+dx[i]][y+dy[i]][z+dz[i]]==0){
                v[x+dx[i]][y+dy[i]][z+dz[i]]++;
                tom--;
                q.push(cur+d[i]);
                ctr[(cnt+1)%2]++;
            }
        ctr[cnt%2]--;
        if(ctr[cnt%2]==0)
            cnt++;
    }
}

int main(void){
    int m, n, h;
    scanf("%d %d %d", &m, &n, &h);
    v.assign(n+2, vector<vector<int>>(m+2, vector<int>(h+2, -1)));
    for(int k=1 ; k<=h ; k++)
        for(int i=1 ; i<=n ; i++)
            for(int j=1 ; j<=m ; j++){
                scanf("%d", &v[i][j][k]);
                if(v[i][j][k]==0)
                    tom++;
            }
    bfs(m,n,h);
    if(tom==0)
        printf("%d\n",cnt-1);
    else
        printf("-1\n");
    return 0;
}