#include <stdio.h>

using namespace std;

int binary_search(int arr[], int len, int tar){
    int s = 0;
    int e = len-1;
    int mid;
    while(s<=e){
        mid = (s + e) / 2;
        if(arr[mid]==tar)
            return mid;
        else if (arr[mid]<tar)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return -1;
}
int lower_bound(int arr[], int len, int tar){
    int s = 0, e = len, mid = 0;
    while(s<e){
        mid = (s + e) / 2;
        if(arr[mid]<tar)
            s = mid + 1;
        else
            e = mid;
    }
    return e;
}
int upper_bound(int arr[], int len, int tar){
    int s = 0, e = len, mid = 0;
    while(s<e){
        mid = (s + e) / 2;
        if(arr[mid]<=tar)
            s = mid + 1;
        else
            e = mid;
    }
    return e;
}

int main(void){
    int arr[10] = {1,3,5,7,9,11,13,15,17,19};
    printf("%d\n", binary_search(arr, sizeof(arr)/4, 20));
    printf("%d\n", lower_bound(arr, sizeof(arr)/4, 12));
    printf("%d\n", upper_bound(arr, sizeof(arr)/4, 12));
    return 0;
}

