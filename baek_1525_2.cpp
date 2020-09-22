#include <stdio.h>
#include <queue>
#include <cmath>
#include <set>
using namespace std;

int puzzle[3][3];
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
int ppnum = 0;
set<int> ss;

int swap(int a, int b){
    int pnum = ppnum;
    int aidx = (int)(pow(10, 8-a));
    int bidx = (int)(pow(10, 8-b));
    int anum = (pnum / aidx) % 10;
    int bnum = (pnum / bidx) % 10;
    pnum -= (anum*aidx + bnum*bidx);
    pnum += (anum*bidx + bnum*aidx);
    return pnum;
}

bool check(int num){
    if(num == 123456789)
        return true;
    else
        return false;
}

void bfs(int num, int sidx){
    queue<pair<int,int>> q;
    int ans = 0, cur = 1, next = 0, x = 0, y = 0;
    q.push(make_pair(num, sidx));
    while(!q.empty()){
        pair<int,int> cp = q.front();
        q.pop();
        ppnum = cp.first;
        cur--;
        if(check(ppnum)){
            printf("%d\n", ans);
            return;
        }
        x = cp.second / 3;
        y = cp.second % 3;
        for(int i=0; i<4; i++){
            int cx = x + dx[i];
            int cy = y + dy[i];
            if(cx>=0 && cx<3 && cy>=0 && cy<3){
                int tmpidx = 3*cx + cy;
                int tmpnum = swap(cp.second, tmpidx);
                if(ss.find(tmpnum)==ss.end()){
                    ss.insert(tmpnum);
                    q.push(make_pair(swap(cp.second, tmpidx), tmpidx));
                    next++;
                }
            }
        }
        if(cur==0){
            ans++;
            cur = next;
            next = 0;
        }
    }
    printf("-1\n");
    return;
}

int main(void){
    int pnum = 0;
    int sidx = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            scanf("%d", &puzzle[i][j]);
            if(puzzle[i][j]==0){
                puzzle[i][j] = 9;
                sidx = 3*i + j;
            }
        }
    }
    int tmp=1;
    for(int i=2; i>=0; i--){
        for(int j=2; j>=0; j--){
            pnum += (puzzle[i][j] * tmp);
            tmp *= 10;
        }
    }
    bfs(pnum, sidx);
    return 0;
}
