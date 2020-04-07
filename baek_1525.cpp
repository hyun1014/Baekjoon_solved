#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

set<vector<char>> s;
pair<set<vector<char>>::iterator, bool> flag;
vector<char> p;
vector<char> swap(vector<char> pp, int a, int b){
    vector<char> cpy;
    for(int i=0 ; i<9 ; i++)
        cpy.push_back(pp[i]);
    char tmp = cpy[a];
    cpy[a] = cpy[b];
    cpy[b] = tmp;
    return cpy;
}
int foo(pair<set<vector<char>>::iterator, bool> p){
    if(p.second)
        return 1;
    else
        return 0;
}
bool cmpans(vector<char> v){
    for(int i=0 ; i<9 ; i++)
        if(v[i]!=(49+i))
            return false;
    return true;
}
int findz(vector<char> pu){
    for(int i=0 ; i<9 ; i++)
        if(pu[i]=='9')
            return i;
    return -1;
}
int bfs(){
    queue<pair<vector<char>,int>> q;
    vector<char> cur;
    vector<char> next;
    int cnt, x, y, idx;
    q.push(make_pair(p, 0));
    s.insert(p);
    while(!q.empty()){
        cur = q.front().first;
        cnt = q.front().second;
        q.pop();
        if(cmpans(cur))
            return cnt;
        idx = findz(cur);
        x = idx % 3;
        y = idx / 3;
        if(x!=0){
            next = swap(cur, idx, idx-1);
            flag = s.insert(next);
            if(flag.second)
                q.push(make_pair(next, cnt+1));
        }
        if(x!=2){
            next = swap(cur, idx, idx+1);
            flag = s.insert(next);
            if(flag.second)
                q.push(make_pair(next, cnt+1));
        }
        if(y!=0){
            next = swap(cur, idx, idx-3);
            flag = s.insert(next);
            if(flag.second)
                q.push(make_pair(next, cnt+1));
        }
        if(y!=2){
            next = swap(cur, idx, idx+3);
            flag = s.insert(next);
            if(flag.second)
                q.push(make_pair(next, cnt+1));
        }
    }
    return -1;
}
int main(void){
    int tmp;
    char ch;
    for(int i=0 ; i<9 ; i++){
        scanf("%d", &tmp);
        ch = tmp + ('0' - 0);
        p.push_back(ch);
    }
    for(int i=0 ; i<9 ; i++){
        if(p[i]=='0'){
            p[i] = '9';
            break;
        }
    }
    int ans = bfs();
    printf("%d\n", ans);
}
