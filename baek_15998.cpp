#include <stdio.h>

using namespace std;

long long gcd(long long a, long long b){
    long long c;
    while(b!=0){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main(void){
    int n;
    long long a, b, need, up, mini, ans, maxmini, tmp;
    long long cur = 0;
    bool charged = false;
    bool logerr = false;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%lld %lld", &a, &b);
        if(logerr)
            continue;
        if(cur + a == b){ // 정상
            cur = b;
            continue;
        }
        if(a>0){ // 충전 안했는데 b가 다르다 -> 모순
            logerr = true;
            continue;
        }
        need = b - a;
        up = need - cur;
        mini = b;
        if(!charged){
            if(up > mini){
                ans = up;
                maxmini = mini;
                charged = true;
            }
            else{
                logerr = true;
                continue;
            }
        }
        else{
            tmp = gcd(ans, up);
            if(tmp>mini && tmp>maxmini){
                ans = tmp;
                if(maxmini<mini)
                    maxmini = mini;
            }
            else{
                logerr = true;
                continue;
            }
        }
        cur = b;
    }
    if(logerr)
        printf("-1\n");
    else if(charged)
        printf("%lld\n", ans);
    else
        printf("1\n");
    return 0;
}
