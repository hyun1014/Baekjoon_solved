#include <stdio.h>
bool xline[15];
bool yline[15];
bool aline[29];
bool bline[29];
int y = 0, n = 0, sum = 0;
void backtracking(int y){
    for(int i=0; i<n; i++){
        if(xline[i] && yline[y] && aline[i+y] && bline[y-i+(n-1)]){
            xline[i] = false;
            yline[y] = false;
            aline[i+y] = false;
            bline[y-i+(n-1)] = false;
            
            if(y==(n-1))
                sum++;
            else
                backtracking(y+1);
            
            bline[y-i+(n-1)] = true;
            aline[i+y] = true;
            yline[y] = true;
            xline[i] = true;
        }
    }
    return;
}

int main(void){
    for(int i=0; i<15; i++){
        xline[i] = true;
        yline[i] = true;
    }
    for(int i=0; i<29; i++){
        aline[i] = true;
        bline[i] = true;
    }
    scanf("%d", &n);
    backtracking(0);
    printf("%d\n", sum);
    return 0;
}