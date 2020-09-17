#include <stdio.h>

using namespace std;

char board[2000][2000];
int n, m;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

bool check(int x, int y){ // 변경 가능?
    char color = board[x][y];
    for(int i=0; i<4; i++){
        int cx = x + dx[i];
        int cy = y + dy[i];
        if(cx>=0 && cx<n && cy>=0 && cy<m){
            if(board[x][y]!=board[cx][cy])
                return false;
        }
    }
    return true;
}

int main(void){
    int answer = 1, cnt = 0;
    scanf("%d %d", &n, &m);
    getchar();
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            scanf("%c", &board[i][j]);
        getchar();
    }
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(check(i, j))
                cnt++;
    for(int i=0; i<cnt; i++)
        answer = (answer * 2) % 1000000007;
    printf("%d\n", answer);
    return 0;
}
