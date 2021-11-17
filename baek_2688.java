package com.company;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        int n;
        long[][] dp = new long[65][10];
        Arrays.fill(dp[1], 1);
        int maxNum = 1;
        for (int tcase = 0; tcase < t; tcase++) {
            n = Integer.parseInt(br.readLine());
            if (n > maxNum) {
                for (int i = maxNum + 1; i<=n; i++) {
                    dp[i][9] = 1;
                    for (int j = 8; j >= 0; j--) {
                        dp[i][j] = dp[i][j+1] + dp[i-1][j];
                    }
                }
                maxNum = n;
            }
            System.out.println(Arrays.stream(dp[n]).sum());
        }

        br.close();
    }
}
