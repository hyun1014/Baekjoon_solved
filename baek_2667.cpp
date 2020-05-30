#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool v[25][25];
bool visit[25][25];
queue<int> q;
int n;
int bfs(int tar){
    if(visit[tar/100][tar%100] || !v[tar/100][tar%100]){
        return 0;
    }
    int cnt=1;
    q.push(tar);
    visit[tar/100][tar%100] = true;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        int x=t/100, y=t%100;
        if(x!=0){
            if(v[x-1][y] && !visit[x-1][y]){
                cnt++;
                q.push(t-100);
                visit[x-1][y] = true;
            }
        }
        if(x!=(n-1)){
            if(v[x+1][y] && !visit[x+1][y]){
                cnt++;
                q.push(t+100);
                visit[x+1][y] = true;
            }
        }
        if(y!=0){
            if(v[x][y-1] && !visit[x][y-1]){
                cnt++;
                q.push(t-1);
                visit[x][y-1] = true;
            }
        }
        if(y!=(n-1)){
            if(v[x][y+1] && !visit[x][y+1]){
                cnt++;
                q.push(t+1);
                visit[x][y+1] = true;
            }
        }
    }
    return cnt;
}

int main(void){
    char s[26];
    int re = 0;
    vector<int> vec;
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++){
        scanf("%s", s);
        for(int j=0 ; j<n ; j++){
            if(s[j]=='1')
                v[i][j] = true;
            else
                v[i][j] = false;
            visit[i][j] = false;
        }
    }
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            int re = bfs(i*100+j);
            if(re!=0)
                vec.push_back(re);
        }
    }
    int len = vec.size();
    sort(vec.begin(), vec.end());
    printf("%d\n", len);
    for(int i=0 ; i<len ; i++)
        printf("%d\n", vec[i]);
    return 0;
}