package com.company;

import java.util.*;

public class Main {
    static long[][] dp = new long[500][500];
    static long[][] sum = new long[500][500];
    static long[] fileSize = new long[500];
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        int k, bp;
        for(int test=0; test<t; test++){
            k = sc.nextInt();
            for(int i=0; i<k; i++){
                Arrays.fill(dp[i], Long.MAX_VALUE);
                dp[i][i] = 0;
            }
            for(int i=0; i<k; i++){
                fileSize[i] = sc.nextLong();
                sum[i][i] = fileSize[i];
            }
            for(int i=0; i<k; i++)
                for(int j=i+1; j<k; j++)
                    sum[i][j] = sum[i][j-1] + fileSize[j];

            for(int i=0; i<k-1; i++)
                dp[i][i+1] = fileSize[i] + fileSize[i+1];

            for(int len=3; len<=k; len++)
                for(int i=0; i<k-len+1; i++)
                    for(int j=i; j<i+len-1; j++)
                        if(dp[i][i+len-1]>dp[i][j]+dp[j+1][i+len-1]+sum[i][j]+sum[j+1][i+len-1])
                            dp[i][i+len-1] = dp[i][j]+dp[j+1][i+len-1]+sum[i][j]+sum[j+1][i+len-1];
            System.out.println(dp[0][k-1]);
        }
    }
}

