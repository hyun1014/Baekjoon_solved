package com.company;

import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        long[][] dp = new long[2][21];
        int[] num = new int[100];
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int cur = 0;
        for(int i=0; i<n; i++)
            num[i] = sc.nextInt();
        dp[0][num[0]] = 1;
        for(int i=1; i<n-1; i++){
            cur = num[i];
            for(int j=0; j<=20; j++){
                if(dp[(i-1)%2][j]!=0){
                    if(j+cur<=20)
                        dp[i%2][j+cur] += dp[(i-1)%2][j];
                    if(j-cur>=0)
                        dp[i%2][j-cur] += dp[(i-1)%2][j];
                }
            }
            for(int j=0; j<=20; j++)
                dp[(i-1)%2][j] = 0;
        }
        System.out.println(dp[(n-2)%2][num[n-1]]);
    }
}

