#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int main(void){
    int n, k;
    scanf("%d %d", &n, &k);
    int ctr[2] = {1,0};
    int cnt = 0;
    queue<int> q;
    bool vi[100001] = { false, };
    int his[100001] = { 0, };
    int cur;
    int idx = 0;
    q.push(n);
    vi[n] = true;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        if(cur==k){
            vector<int> v;
            v.push_back(cur);
            while(cur!=n){
                cur = his[cur];
                v.push_back(cur);
            }
            printf("%d\n", cnt);
            for(int i=v.size()-1 ; i>=0 ; i--)
                printf("%d ", v[i]);
            printf("\n");
            return 0;
        }
        if(cur!=100000 && !vi[cur+1]){
            vi[cur+1] = true;
            ctr[(cnt+1)%2]++;
            his[cur+1] = cur;
            q.push(cur+1);
        }
        if(cur!=0 && !vi[cur-1]){
            vi[cur-1] = true;
            ctr[(cnt+1)%2]++;
            his[cur-1] = cur;
            q.push(cur-1);
        }
        if(cur<=50000 && !vi[cur*2]){
            vi[cur*2] = true;
            ctr[(cnt+1)%2]++;
            his[cur*2] = cur;
            q.push(cur*2);
        }
        ctr[cnt%2]--;
        if(ctr[cnt%2]==0)
            cnt++;
    }
    return 0;
}