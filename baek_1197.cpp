#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> parent;
vector<int> nodeCount;

int find(int x){
    if(parent[x]==x)
        return x;
    else{
        parent[x] = find(parent[x]);
        return parent[x];
    }
}

void union_set(int x, int y){
    int xp = find(x);
    int yp = find(y);
    parent[yp] = xp;
    nodeCount[xp] += nodeCount[yp];
}

bool check(int x, int y){
    return find(x)==find(y);
}

struct cmp {
    bool operator()(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
        if(a.second==b.second){
            return a.first.first > b.first.first;
        }
        else{
            return a.second > b.second;
        }
    }
};

int main(void){
    int v, e, a, b, c;
    int ans = 0;
    priority_queue<pair<pair<int,int>,int>, vector<pair<pair<int,int>,int>>, cmp> q;
    scanf("%d %d", &v, &e);
    for(int i=0; i<=v; i++){
        parent.push_back(i);
        nodeCount.push_back(1);
    }
    for(int i=0; i<e; i++){
        scanf("%d %d %d", &a, &b, &c);
        q.push(make_pair(make_pair(a, b), c));
    }
    while(!q.empty()){
        pair<pair<int,int>,int> cur = q.top();
        q.pop();
        if(!check(cur.first.first, cur.first.second)){
            ans += cur.second;
            union_set(cur.first.first, cur.first.second);
            if(nodeCount[cur.first.first]==v)
                break;
        }
    }
    printf("%d\n", ans);
    return 0;
}