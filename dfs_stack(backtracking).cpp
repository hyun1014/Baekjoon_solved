#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> vec;
vector<bool> visited;
vector<int> cur;
vector<int> stk;
vector<int> dr;
void dfs(int tar){
    stk.push_back(tar);
    while(!stk.empty()){
        int from = stk.back();
        stk.pop_back();
        if (cur[from]==0){ //처음 방문했다
            dr.push_back(from); // 경로에 삽입
            int len = vec[from].size();
            for(int i=0 ; i<len ; i++){
                if(cur[vec[from][i]]==0){ //처음 방문하는 곳이 있는가?
                    stk.push_back(from);
                    stk.push_back(vec[from][i]);
                    cur[from]++;
                }
            }
            if (cur[from]==0){ // 여기가 마지막이다.
                    for(int i=0 ; i<dr.size() ; i++)
                        printf("%d ", dr[i]); // 경로 print
                    printf("\n");
                    dr.pop_back(); // 마지막 노드 제거
                }
        }
        else if (cur[from]==1){ //탐색 다 끝났다
            dr.pop_back();
            cur[from] = 0;
        }
	else
	    cur[from]--;
    }
}

int main(void){
    int n, m, v;
    scanf("%d %d %d", &n, &m, &v);
    vec.assign(n+1, vector<int>(0,0));
    visited.assign(n+1, false);
    cur.assign(n+1, 0);
    for(int i=0 ; i<m ; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    for(int i=1 ; i<=n ; i++)
        sort(vec[i].begin(), vec[i].end(), greater<int>());
    dfs(v);
    return 0;
}
