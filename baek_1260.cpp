#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector<bool> visited;
vector<vector<int>> node;
vector<int> idx;

void dfs(int start){
    stack<int> stk;
    int cur, esize;
    visited[start] = true;
    stk.push(start);
    while(!stk.empty()){
        cur = stk.top();
        if(idx[cur]==-1){
            printf("%d ", cur);
            idx[cur]++;
        }
        esize = node[cur].size();
        for( ; idx[cur]<esize; idx[cur]++){
            if(!visited[node[cur][idx[cur]]]){
                visited[node[cur][idx[cur]]] = true;
                stk.push(node[cur][idx[cur]]);
                break;
            }
        }
        if(idx[cur]==esize)
            stk.pop();
    }
}
void bfs(int start){
    queue<int> q;
    int cur, esize;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        printf("%d ", cur);
        esize = node[cur].size();
        for(int i=0; i<esize; i++){
            if(!visited[node[cur][i]]){
                visited[node[cur][i]] = true;
                q.push(node[cur][i]);
            }
        }
    }

}

bool cmp(int a, int b){
    return a > b;
}

int main(void){
    int n, m, v, a, b;
    scanf("%d %d %d", &n, &m, &v);
    visited.assign(n+1, false);
    idx.assign(n+1, -1);
    node.assign(n+1, vector<int>(0, 0));
    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        node[a].push_back(b);
        node[b].push_back(a);
    }
    for(int i=1; i<=n; i++)
        sort(node[i].begin(), node[i].end());
    dfs(v);
    printf("\n");
    for(int i=1; i<=n; i++)
        visited[i] = false;
    bfs(v);
    printf("\n");
    return 0;
}