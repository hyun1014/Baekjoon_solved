package com.company;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    static Integer[][] board = new Integer[100][100];
    static boolean[][] visited = new boolean[100][100];
    static int[] dx = new int[] {0, -1, 0, 1};
    static int[] dy = new int[] {-1, 0, 1, 0};
    static int answer = 1;
    static int height = 1;

    static void bfs(int target, int n) {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(target);
        while(!queue.isEmpty()) {
            int cur = queue.poll();
            int x = cur/1000;
            int y = cur%1000;
            for (int i = 0; i < 4; i++) {
                if (x+dx[i]>=0 && x+dx[i]<n && y+dy[i]>=0 && y+dy[i]<n && board[x+dx[i]][y+dy[i]]>height && !visited[x+dx[i]][y+dy[i]]) {
                    queue.add((x+dx[i])*1000 + (y+dy[i]));
                    visited[x+dx[i]][y+dy[i]] = true;
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            Integer[] temp = Arrays.stream(br.readLine().split(" "))
                                .map(Integer::parseInt)
                                .toArray(Integer[]::new);
            board[i] = Arrays.copyOf(temp, n);
        }

        while (true) {
            int tempAnswer = 0;
            for (int i = 0; i < n; i++)
                Arrays.fill(visited[i], false);

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] > height && !visited[i][j]) {
                        visited[i][j] = true;
                        bfs(i*1000 + j, n);
                        tempAnswer++;
                    }
                }
            }

            if (tempAnswer == 0)
                break;
            answer = Integer.max(answer, tempAnswer);
            height++;
        }
        System.out.println(answer);
    }
}
