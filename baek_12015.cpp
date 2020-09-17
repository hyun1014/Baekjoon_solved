#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int n;
    scanf("%d", &n);
    vector<int> v (n+1, 0);
    vector<int> dp (1, 0);
    for(int i=1; i<=n; i++)
        scanf("%d", &v[i]);
    for(int i=1; i<=n; i++){
        int len = dp.size();
        int idx = lower_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
        if(idx == len)
            dp.push_back(v[i]);
        else
            dp[idx] = v[i];
    }
    printf("%d\n", int(dp.size()) - 1);
    return 0;
}