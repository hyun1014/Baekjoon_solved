#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

set<vector<char>> s;
pair<set<vector<char>>::iterator, bool> flag;
vector<char> p;
void swap(int a, int b){
    char tmp = p[a];
    p[a] = p[b];
    p[b] = tmp;
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
    int cnt, x, y, idx;
    q.push(make_pair(p, 0));
    s.insert(p);
    while(!q.empty()){
        p = q.front().first;
        cnt = q.front().second;
        q.pop();
        if(cmpans(p))
            return cnt;
        idx = findz(p);
        x = idx % 3;
        y = idx / 3;
        if(x!=0){
            swap(idx, idx-1);
            flag = s.insert(p);
            if(flag.second)
                q.push(make_pair(p, cnt+1));
            swap(idx, idx-1);
        }
        if(x!=2){
            swap(idx, idx+1);
            flag = s.insert(p);
            if(flag.second)
                q.push(make_pair(p, cnt+1));
            swap(idx, idx+1);
        }
        if(y!=0){
            swap(idx, idx-3);
            flag = s.insert(p);
            if(flag.second)
                q.push(make_pair(p, cnt+1));
            swap(idx, idx-3);
        }
        if(y!=2){
            swap(idx, idx+3);
            flag = s.insert(p);
            if(flag.second)
                q.push(make_pair(p, cnt+1));
            swap(idx, idx+3);
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
    printf("%d\n", bfs());
}

