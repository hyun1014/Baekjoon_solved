#include <stdio.h>
#include <queue>
using namespace std;

void bfs(int n, int k){
    int ctr[2] = {1,0};
    int cnt = 0;
    queue<int> q;
    bool vi[200002] = { false, };
    int cur;
    q.push(n);
    vi[n] = true;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        if(cur==k){
            printf("%d\n", cnt);
            return;
        }
        if(cur!=100000 && !vi[cur+1]){
            vi[cur+1] = true;
            ctr[(cnt+1)%2]++;
            q.push(cur+1);
        }
        if(cur!=0 && !vi[cur-1]){
            vi[cur-1] = true;
            ctr[(cnt+1)%2]++;
            q.push(cur-1);
        }
        if(cur<= 50000 && !vi[cur*2]){
            vi[cur*2] = true;
            ctr[(cnt+1)%2]++;
            q.push(cur*2);
        }
        ctr[cnt%2]--;
        if(ctr[cnt%2]==0)
            cnt++;
    }
}

int main(void){
    int n, k;
    scanf("%d %d", &n, &k);
    bfs(n,k);
    return 0;
}