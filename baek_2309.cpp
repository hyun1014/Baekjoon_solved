#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void){
    int arr[9];
    int sum = 0, i = 0, j = 0, k = 0;
    bool flag = false;
    for(i=0; i<9; i++){
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    sum -= 100;
    sort(arr, arr+9);
    for(i=0; i<8; i++){
        for(j=i+1; j<9; j++){
            if(arr[i]+arr[j] == sum){
                flag = true;
                break;
            }
        }
        if(flag)
            break;
    }
    for(k=0; k<9; k++)
        if(k!=i && k!=j)
            printf("%d\n", arr[k]);
    return 0;
}