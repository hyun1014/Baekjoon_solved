package com.modern;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.IntStream;

public class Main {
    static int[] dx = new int[] {-2, -1, 1, 2, 2, 1, -1, -2};
    static int[] dy = new int[] {-1, -2, -2, -1, 1, 2, 2, 1};
    static boolean[][] visited = new boolean[300][300];
    static Queue<Pair> queue = new LinkedList<>();

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int testCount = Integer.parseInt(br.readLine());
        for (int testCase = 0; testCase < testCount; testCase++) {
            int depth = 0;
            int prev = 1;
            int next = 0;
            int l = Integer.parseInt(br.readLine());
            IntStream.range(0, l).forEach(it -> Arrays.fill(visited[it], false));
            int[] start = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            queue.add(new Pair(start[0], start[1]));
            visited[start[0]][start[1]] = true;
            int[] finish = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            Pair target = new Pair(finish[0], finish[1]);

            while (!queue.isEmpty()) {
                Pair current = queue.poll();
                prev--;
                if (current.x == target.x && current.y == target.y) {
                    System.out.println(depth);
                    break;
                }
                for (int i = 0; i < 8; i++) {
                    int nx = current.x + dx[i];
                    int ny = current.y + dy[i];
                    if (nx >= 0 && nx < l && ny >= 0 && ny < l && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        queue.add(new Pair(nx, ny));
                        next++;
                    }
                }
                if (prev == 0) {
                    depth++;
                    prev = next;
                    next = 0;
                }
            }
            queue.clear();
        }
    }

    static class Pair {
        int x;
        int y;
        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
