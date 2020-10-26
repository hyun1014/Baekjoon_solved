#include <stdio.h>
#include <algorithm>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int main(void){
    pair<int,bool> arr[50][50];
    // d는 방향
    int n, m, r, c, d, tmp, dz, x, y;
    int ans = 0;
    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &r, &c, &d);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &tmp);
            if(tmp)
                arr[i][j] = make_pair(1, true); 
            else
                arr[i][j] = make_pair(0, false);
        }
    }
    arr[r][c].second = true;
    ans++;
    while(true){
        bool flag = false; // 청소할 공간이 있는가
        for(int i=0; i<4; i++){
            dz = i - d; // 방향
            if(dz<0)
                dz += 4;
            // 임시 방향
            x = r + dx[dz]; 
            y = c + dy[dz];
            if(x<0 || x>=n || y<0 || y>=m || arr[x][y].first==1) // 이동 위치가 벽
                continue;
            if(!arr[x][y].second){
                d -= (i+1);
                if(d<0)
                    d += 4;
                r = x;
                c = y;
                arr[r][c].second = true;
                ans++;
                flag = true;
                break;
            }
        }
        if(!flag){
            if(d%2)
                dz = d-1;
            else
                dz = d+1;
            x = r + dx[dz];
            y = c + dy[dz];
            if(x<0 || x>=n || y<0 || y>=m || arr[x][y].first==1)
                break;
            else{
                r = x;
                c = y;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}