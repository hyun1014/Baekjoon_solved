#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int,int>>> v (1, vector<pair<int,int>> (1, make_pair(0,0)));
vector<vector<bool>> visited (1, vector<bool> (1, false));
int n, m, t, num, x, d, k, ans;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool checka(int a){
    if(a<1 || a>n)
        return false;
    else
        return true;
}
int checkb(int b){
    if(b==-1)
        return m-1;
    else if(b==m)
        return 0;
    else
        return b;
}


void spin(int dir, int idx, int cnt){
    int d =  dir==0 ? 1 : -1;
    cnt *= d;
    for(int i=0; i<m; i++){
        v[idx][i].first = (v[idx][i].first + cnt) % m;
        if(v[idx][i].first<0)
            v[idx][i].first = m + v[idx][i].first;
    }
}

void bfs(int a, int b){
    for(int i=1; i<=n; i++)
        for(int j=0; j<m; j++)
            visited[i][j] = false;
    queue<pair<int,int>> q;
    q.push(make_pair(a,b));
    visited[a][b] = true;
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int da = cur.first + dx[i];
            int db = checkb(cur.second + dy[i]);
            if(checka(da) && v[da][db].second==v[a][b].second && !visited[da][db]){
                q.push(make_pair(da,db));
                visited[da][db] = true;
                v[da][db].second = 0;
            }
        }
    }
    v[a][b].second = 0;
}

int main(void){
    ans = 0;
    scanf("%d %d %d", &n, &m, &t);
    for(int i=1; i<=n; i++){
        vector<pair<int,int>> vv;
        vector<bool> vvv;
        v.push_back(vv);
        visited.push_back(vvv);
        for(int j=0; j<m; j++){
            scanf("%d", &num);
            v[i].push_back(make_pair(j, num));
            visited[i].push_back(false);
        }
    }
    for(int i=0; i<t; i++){
        bool samenum = false;
        scanf("%d %d %d", &x, &d, &k);
        for(int j=1; j<=n; j++){
            if(j%x==0){
                spin(d, j, k);
                sort(v[j].begin(), v[j].end());
            }
        }
        for(int a=1; a<=n; a++){
            for(int b=0; b<m; b++){
                if(v[a][b].second!=0){
                    for(int c=0; c<4; c++){
                        int da = a + dx[c];
                        int db = checkb(b + dy[c]);
                        if(checka(da) && v[a][b].second!=0 && v[a][b].second==v[da][db].second){
                            bfs(a,b);
                            samenum = true;
                        }
                    }
                }
            }
        }
        if(!samenum){
            int total = 0;
            int cnt = 0;
            double aver = 0;
            for(int a=1; a<=n; a++){
                for(int b=0; b<m; b++){
                    if(v[a][b].second!=0){
                        total += v[a][b].second;
                        cnt++;
                    }
                }
            }
            if(cnt!=0){
                aver = (double)total / (double)cnt;
            }
            for(int a=1; a<=n; a++){
                for(int b=0; b<m; b++){
                    if(v[a][b].second!=0){
                        if(aver>(double)v[a][b].second)
                            v[a][b].second++;
                        else if(aver<(double)v[a][b].second)
                            v[a][b].second--;
                    }
                }
            }
        }
    }
    for(int i=1; i<=n; i++)
        for(int j=0; j<m; j++)
            ans += v[i][j].second;
    printf("%d\n", ans);
    return 0;
}