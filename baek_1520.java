package com.company;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int M;
    static int N;
    static int[] dx = new int[] {0, -1, 0, 1};
    static int[] dy = new int[] {-1, 0, 1, 0};
    static int[][] board = new int[500][500];
    static int[][] dp = new int[500][500];

    static int dfs(int x, int y) {
        if(x==(M-1) && y==(N-1))
            return 1;
        else if (dp[x][y]!=-1)
            return dp[x][y];
        int sum = 0;
        int xx, yy;
        for(int i=0; i<4; i++){
            xx = x + dx[i];
            yy = y + dy[i];
            if(xx>=0 && xx<M && yy>=0 & yy<N && board[x][y]>board[xx][yy]){
                sum += dfs(xx, yy);
            }
        }
        dp[x][y] = sum;
        return dp[x][y];
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());

        for (int i = 0; i < M; i++) {
            Arrays.fill(dp[i], -1);
        }

        dp[M-1][N-1] = 0;

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        dfs(0, 0);
        System.out.println(dp[0][0]);

        br.close();
    }
}