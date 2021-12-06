package com.company;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int[] dx = new int[] {-1, 0, 1, 0};
    static int[] dy = new int[] {0, 1, 0, -1};
    static class Robot {
        int x;
        int y;
        int d;
        boolean isRunning = true;
        Robot(int x, int y, int d) {
            this.x = x;
            this.y = y;
            this.d = d;
        }
    }
    public static void main(String[] args) throws Exception {
        int answer = 0;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        boolean[][] isVisited = new boolean[n][m];
        int[][] board = new int[n][m];

        st = new StringTokenizer(br.readLine());
        int r = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());
        Robot robot = new Robot(r, c, d);

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        do {
            if (!isVisited[robot.x][robot.y]) {
                isVisited[robot.x][robot.y] = true;
                answer++;
            }
            for (int i = 0; i < 4; i++) {
                robot.d = (robot.d + 3) % 4;
                if (robot.x + dx[robot.d] >= 0 && robot.x + dx[robot.d] < n && robot.y + dy[robot.d] >= 0 &&
                    robot.y + dy[robot.d] < m) {
                    int x = robot.x + dx[robot.d];
                    int y = robot.y + dy[robot.d];
                    if (board[x][y] != 1 && !isVisited[x][y]) {
                        robot.x = x;
                        robot.y = y;
                        break;
                    }
                }
                if (i == 3) {
                    int x = robot.x + dx[(robot.d + 2) % 4];
                    int y = robot.y + dy[(robot.d + 2) % 4];
                    if (x >= 0 && x < n && y >= 0 && y < m && board[x][y] != 1) {
                        robot.x = x;
                        robot.y = y;
                    } else {
                        robot.isRunning = false;
                    }
                }
            }
        } while (robot.isRunning);

        System.out.println(answer);

        br.close();
    }
}