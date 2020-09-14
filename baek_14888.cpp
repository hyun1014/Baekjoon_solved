#include <stdio.h>

using namespace std;

int opr[4];
int num[11];
int n, result, min, max;
void solution(int idx){
    if (idx==n){
        if(result>max)
            max = result;
        if(result<min)
            min = result;
        return;
    }
    if(opr[0]!=0){
        result += num[idx];
        opr[0]--;
        solution(idx+1);
        opr[0]++;
        result -= num[idx];
    }
    if(opr[1]!=0){
        result -= num[idx];
        opr[1]--;
        solution(idx+1);
        opr[1]++;
        result += num[idx];
    }
    if(opr[2]!=0){
        result *= num[idx];
        opr[2]--;
        solution(idx+1);
        opr[2]++;
        result /= num[idx];
    }
    if(opr[3]!=0){
        int tmp = result % num[idx];
        result /= num[idx];
        opr[3]--;
        solution(idx+1);
        opr[3]++;
        result *= num[idx];
        result += tmp;
    }
}

int main(void){
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &num[i]);
    for(int i=0; i<4; i++)
        scanf("%d", &opr[i]);
    max = -1000000000;
    min = 1000000000;
    result = num[0];
    solution(1);
    printf("%d\n%d\n", max, min);
    return 0;
}