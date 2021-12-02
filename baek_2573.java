package com.company;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int[][] board = new int[300][300];
    static int[][] tempBoard = new int[300][300];
    static boolean[][] visited = new boolean[300][300];
    static int[] dx = new int[] {0, -1, 0, 1};
    static int[] dy = new int[] {-1, 0, 1, 0};
    static int n = 0;
    static int m = 0;

    static class Point {
        int x;
        int y;
        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static void melt() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    if (i + dx[k] >= 0 && i + dx[k] < n && j + dy[k] >= 0 && j + dy[k] < m &&
                        board[i+dx[k]][j+dy[k]] == 0) {
                        cnt++;
                    }
                }
                tempBoard[i][j] = board[i][j] - cnt;
                if (tempBoard[i][j] < 0)
                    tempBoard[i][j] = 0;
            }
        }
    }

    static void clearBoard() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board[i][j] = tempBoard[i][j];
                tempBoard[i][j] = 0;
                visited[i][j] = false;
            }
        }
    }

    static void bfs(int x, int y) {
        Queue<Point> queue = new LinkedList<>();
        queue.add(new Point(x, y));
        visited[x][y] = true;
        while (!queue.isEmpty()) {
            Point cur = queue.poll();
            for (int i = 0; i < 4; i++) {
                if (cur.x + dx[i] >= 0 && cur.x + dx[i] < n && cur.y + dy[i] >= 0 && cur.y + dy[i] < m &&
                    tempBoard[cur.x+dx[i]][cur.y+dy[i]] != 0 && !visited[cur.x+dx[i]][cur.y+dy[i]]) {
                    visited[cur.x+dx[i]][cur.y+dy[i]] = true;
                    queue.add(new Point(cur.x+dx[i], cur.y+dy[i]));
                }
            }
        }
    }

    static int checkBoard() {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && tempBoard[i][j] != 0) {
                    cnt++;
                    bfs(i, j);
                }
            }
        }
        return cnt;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        int answer = 0;

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        while (true) {
            melt();
            answer++;
            int cnt = checkBoard();
            if (cnt != 1) {
                System.out.println(cnt > 1 ? answer : 0);
                break;
            }
            clearBoard();
        }

        br.close();
    }
}