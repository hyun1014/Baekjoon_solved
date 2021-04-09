package com.company;

import java.util.*;

public class Main {
    public static int lower_bound(int[] arr, int len, int tar){
        int front, rear, mid;
        front = 0;
        rear = len;
        while(front<rear){
            mid = (front+rear)/2;
            if(arr[mid]<tar)
                front = mid+1;
            else
                rear = mid;
        }
        return rear;
    }
    public static void main(String[] args) throws Exception {
        int N, num, ans, idx;
        int[] dp = new int[201];
        ans = 0;
        Arrays.fill(dp, 1, 201, 999);
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        for(int i=0; i<N; i++){
            num = sc.nextInt();
            idx = lower_bound(dp,ans+1, num);
            dp[idx] = num;
            if(idx==ans+1)
                ans++;
        }
        System.out.println(N-ans);
    }
}
