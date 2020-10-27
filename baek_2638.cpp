#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int arr[102][102];
bool v[102][102];
int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool rotten(int x, int y){
    return (arr[x-1][y] + arr[x][y-1] + arr[x+1][y] + arr[x][y+1] < -10) ? true : false;
}

void bfs(){
    for(int i=0; i<=n+1; i++)
        for(int j=0; j<=m+1; j++)
            v[i][j] = false;
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    v[0][0] = true;
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        arr[cur.first][cur.second] = -10;
        for(int i=0; i<4; i++){
            int tx = cur.first + dx[i];
            int ty = cur.second + dy[i];
            if(tx<0 || tx>=n || ty<0 || ty>=m)
                continue;
            if((arr[tx][ty]==0 || arr[tx][ty]==-10) && !v[tx][ty]){
                q.push(make_pair(tx, ty));
                arr[tx][ty] = -10;
                v[tx][ty] = true;
            }
        }
    }
}

int main(void){
    bool flag = true;
    int ans = 0;
    for(int i=0; i<102; i++)
        for(int j=0; j<102; j++)
            arr[i][j] = 0;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d", &arr[i][j]);
    while(1){
        flag = false;
        bfs();
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(arr[i][j]==1 && rotten(i, j)){
                    arr[i][j] = 0;
                    flag = true;
                }
            }
        }
        if(flag)
            ans++;
        else
            break;
    }
    printf("%d\n", ans);
    return 0;
}