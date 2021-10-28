package com.company;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[][][] dp = new int[17][17][17];
        int[][] arr = new int[17][17];
        int n = Integer.parseInt(br.readLine());
        for (int i = 1; i <= n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        dp[1][2][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][j]==1 || (i==1 && j==1) || (i==1 && j==2))
                    continue;

                dp[i][j][0] = dp[i][j-1][0] + dp[i][j-1][2];
                dp[i][j][1] = dp[i-1][j][1] + dp[i-1][j][2];
                if (arr[i-1][j]==0 && arr[i][j-1]==0)
                    dp[i][j][2] = Arrays.stream(dp[i-1][j-1]).sum();
            }
        }

        System.out.println(Arrays.stream(dp[n][n]).sum());
    }
}
