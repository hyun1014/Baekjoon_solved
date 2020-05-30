#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void){
    vector<vector<int>> vec;
    vector<bool> visited;
    queue<int> que;
    int n, m, a, b, t, len;
    int cnt=0;
    scanf("%d %d", &n, &m);
    vec.assign(n+1, vector<int> (0,0));
    visited.assign(n+1, false);
    for(int i=0 ; i<m ; i++){
        scanf("%d %d", &a, &b);
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    que.push(1);
    visited[1] = true;
    while(!que.empty()){
        t = que.front();
        que.pop();
        len = vec[t].size();
        for(int i=0 ; i<len ; i++){
            if(!visited[vec[t][i]]){
                visited[vec[t][i]] = true;
                que.push(vec[t][i]);
                cnt++;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}