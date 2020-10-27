#include <stdio.h>
using namespace std;

int b[500][500];
int n, m;

bool check(int x, int y){
    if(x<0 || x>=n || y<0 || y>=m)
        return false;
    else
        return true;
}
int cmp(int x, int y){
    return x>y ? x : y;
}

int main(void){
    int ans = 0;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d", &b[i][j]);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(check(i, j+3)){
                ans = cmp(ans, b[i][j] + b[i][j+1] + b[i][j+2] + b[i][j+3]);
            }
            if(check(i+3, j)){
                ans = cmp(ans, b[i][j] + b[i+1][j] + b[i+2][j] + b[i+3][j]);
            }
            if(check(i+1, j+1)){
                ans = cmp(ans, b[i][j] + b[i+1][j] + b[i][j+1] + b[i+1][j+1]);
            }
            if(check(i+2, j+1)){
                ans = cmp(ans, b[i][j] + b[i+1][j] + b[i+2][j] + b[i+2][j+1]);
                ans = cmp(ans, b[i][j+1] + b[i+1][j+1] + b[i+2][j+1] + b[i+2][j]);
                ans = cmp(ans, b[i][j+1] + b[i][j] + b[i+1][j] + b[i+2][j]);
                ans = cmp(ans, b[i][j] + b[i][j+1] + b[i+1][j+1] + b[i+2][j+1]);
                ans = cmp(ans, b[i][j] + b[i+1][j] + b[i+1][j+1] + b[i+2][j+1]);
                ans = cmp(ans, b[i][j+1] + b[i+1][j+1] + b[i+1][j] + b[i+2][j]);
                ans = cmp(ans, b[i][j] + b[i+1][j] + b[i+2][j] + b[i+1][j+1]);
                ans = cmp(ans, b[i][j+1] + b[i+1][j+1] + b[i+2][j+1] + b[i+1][j]);
            }
            if(check(i+1, j+2)){
                ans = cmp(ans, b[i+1][j] + b[i][j] + b[i][j+1] + b[i][j+2]);
                ans = cmp(ans, b[i][j] + b[i][j+1] + b[i][j+2] + b[i+1][j+2]);
                ans = cmp(ans, b[i][j] + b[i+1][j] + b[i+1][j+1] + b[i+1][j+2]);
                ans = cmp(ans, b[i+1][j] + b[i+1][j+1] + b[i+1][j+2] + b[i][j+2]);
                ans = cmp(ans, b[i][j] + b[i][j+1] + b[i+1][j+1] + b[i+1][j+2]);
                ans = cmp(ans, b[i+1][j] + b[i+1][j+1] + b[i][j+1] + b[i][j+2]);
                ans = cmp(ans, b[i][j] + b[i][j+1] + b[i][j+2] + b[i+1][j+1]);
                ans = cmp(ans, b[i+1][j] + b[i+1][j+1] + b[i+1][j+2] + b[i][j+1]);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}