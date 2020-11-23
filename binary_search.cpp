#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int binary_search(int* arr, int start, int end, int tar){
    int mid;
    while(start<=end){
        mid = (start + end) / 2;
        if(arr[mid]==tar)
            return mid;
        else if (arr[mid]<tar)
            start = mid+1;
        else
            end = mid-1;
    }
    return -1;
}
int upperBound(int* arr, int len, int tar){
    int start = 0, end = len;
    int mid;
    while(start<end){
        mid = (start + end) / 2;
        if(arr[mid]<=tar)
            start = mid + 1;
        else
            end = mid;
    }
    return start;
}
int lowerBound(int* arr, int len, int tar){
    int start = 0, end = len;
    int mid;
    while(start<end){
        mid = (start + end) / 2;
        if(arr[mid]<tar)
            start = mid + 1;
        else
            end = mid;
    }
    return start;
}


int main(void){
    int arr[12] = {1,1,3,3,5,5,7,7,7,7,9,9};
    // int arr[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
    printf("%d\n", upperBound(arr, 12, 7));
    printf("%d\n", lowerBound(arr, 12, 7));
    return 0;
}