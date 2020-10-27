#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int arr[20][20];
bool v[20][20];
vector<pair<int,int>> candidate;
int lv = 2;
int ex = 0;
pair<int,int> cur;
int n;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0,-1, 1, 0};

int bfs(pair<int,int> c){
    int d = 1, prev = 1, next = 0;
    queue<pair<int,int>> q;
    q.push(c);
    v[c.first][c.second] = true;
    while(!q.empty()){
        pair<int,int> current = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int tx = current.first + dx[i];
            int ty = current.second + dy[i];
            if(tx<0 || tx>=n || ty<0 || ty>=n)
                continue;
            if(v[tx][ty])
                continue;
            int tar = arr[tx][ty];
            if(tar<=lv){
                if(tar>0 && tar<lv){
                    candidate.push_back(make_pair(tx, ty));
                }
                else{
                    next++;
                    q.push(make_pair(tx, ty));
                    v[tx][ty] = true;
                }
            }
        }
        prev--;
        if(prev==0){
            if(!candidate.empty())
                return d;
            prev = next;
            next = 0;
            d++;
        }
    }
    return -1;
}

int main(void){
    int ans = 0, dis = 0;
    int tmp;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &tmp);
            if(tmp==9)
                cur = make_pair(i,j);
            arr[i][j] = tmp;
            v[i][j] = false;
        }
    }
    while(true){
        dis = bfs(cur);
        if(dis==-1)
            break;
        ans += dis;
        sort(candidate.begin(), candidate.end());
        arr[cur.first][cur.second] = 0;
        arr[candidate[0].first][candidate[0].second] = 9;
        cur = candidate[0];
        ex++;
        if(ex==lv){
            ex = 0;
            lv++;
        }
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                v[i][j] = false;
        candidate.clear();
    }
    printf("%d\n", ans);
    return 0;
}