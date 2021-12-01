package com.company;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int s = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        boolean[][] volume = new boolean[n+1][m+1];
        int[] volumeDiff = new int[n+1];

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n ; i++) {
            volumeDiff[i] = Integer.parseInt(st.nextToken());
        }

        volume[0][s] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (volume[i-1][j]) {
                    if (j - volumeDiff[i] >= 0) {
                        volume[i][j - volumeDiff[i]] = true;
                    }
                    if (j + volumeDiff[i] <= m) {
                        volume[i][j + volumeDiff[i]] = true;
                    }
                }
            }
        }

        for (int i = m; i >= 0; i--) {
            if (volume[n][i]) {
                System.out.println(i);
                break;
            }
            if (i == 0) {
                System.out.println(-1);
            }
        }

        br.close();
    }
}
