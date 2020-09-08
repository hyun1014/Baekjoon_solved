#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int len = 0, n = 0, m = 0;
vector<int> vec;
void backtracking(int num){
    vec.push_back(num);
    len++;
    if(len==m){
        for(int i=0; i<len; i++)
            printf("%d ", vec[i]);
        printf("\n");
    }
    else
        for(int i=num; i<=n; i++)
            backtracking(i);
    vec.pop_back();
    len--;
    return;
}

int main(void){
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++)
        backtracking(i);
    return 0;
}