package com.company;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    static char[][] arr1;
    static char[][] arr2;
    static boolean[][] visited;
    static int[] dx = new int[] {0, -1, 0, 1};
    static int[] dy = new int[] {-1, 0, 1, 0};

    static void bfs(int idx, char[][] arr) {
        Queue<Integer> queue = new LinkedList<>();
        char color = arr[idx/1000][idx%1000];
        visited[idx/1000][idx%1000] = true;
        queue.add(idx);
        while(!queue.isEmpty()) {
            int cur = queue.poll();
            for (int i = 0; i < 4; i++) {
                int x = cur/1000;
                int y = cur%1000;
                if (x+dx[i]>=0 && x+dx[i]<arr[0].length && y+dy[i]>=0 && y+dy[i]<arr[0].length) {
                    if (!visited[x+dx[i]][y+dy[i]] && arr[x+dx[i]][y+dy[i]]==color) {
                        visited[x+dx[i]][y+dy[i]] = true;
                        queue.add((x+dx[i])*1000 + (y+dy[i]));
                    }
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] answer = new int[] {0, 0};
        arr1 = new char[n][n];
        arr2 = new char[n][n];
        visited = new boolean[n][n];

        for (int i = 0; i < n; i++) {
            Arrays.fill(visited[i], false);
            char[] cur = br.readLine().toCharArray();
            arr1[i] = Arrays.copyOf(cur, n);
            arr2[i] = Arrays.copyOf(cur, n);
            for (int j = 0; j < n; j++) {
                if (arr2[i][j] == 'G') {
                    arr2[i][j] = 'R';
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    bfs(i*1000 + j, arr1);
                    answer[0]++;
                }
            }
        }

        for (int i = 0; i < n; i++)
            Arrays.fill(visited[i], false);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    bfs(i*1000 + j, arr2);
                    answer[1]++;
                }
            }
        }

        System.out.println(answer[0] + " " + answer[1]);
    }
}
