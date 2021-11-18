package com.company;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Deque;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {
    static Deque<Integer> snake = new LinkedList<>();
    static boolean[][] snakeBody = new boolean[101][101];
    static int snakeDir = 1;
    static boolean[][] board = new boolean[101][101];
    static int n = 100;
    static int[] moving = new int[] {-1000, 1, 1000, -1};
    static boolean dead = false;

    static boolean move() {
        int head = snake.getFirst();
        int next = head + moving[snakeDir];
        int x = next / 1000;
        int y = next % 1000;
        if (x > 0 && x <= n && y > 0 && y <= n && !snakeBody[x][y]) {
            if (board[x][y]) {
                board[x][y] = false;
            } else {
                int tail = snake.pollLast();
                snakeBody[tail/1000][tail%1000] = false;
            }
            snake.addFirst(next);
            snakeBody[x][y] = true;
            return true;
        } else {
            dead = true;
            return false;
        }

    }

    public static void main(String[] args) throws Exception {
        int answer = 0;
        snake.addFirst(1001);
        snakeBody[1][1] = true;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        int k = Integer.parseInt(br.readLine());
        for (int i = 0; i < k; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            board[x][y] = true;
        }

        int l = Integer.parseInt(br.readLine());

        while (l > 0 && !dead) {
            st = new StringTokenizer(br.readLine());
            int sec = Integer.parseInt(st.nextToken());
            String dir = st.nextToken();

            while (answer < sec) {
                answer++;
                if (!move()) {
                    break;
                }
            }

            if (dir.equals("L")) {
                snakeDir = (snakeDir + 3) % 4;
            } else {
                snakeDir = (snakeDir + 1) % 4;
            }

            l--;
        }

        if (!dead) {
            do {
                answer++;
            } while (move());
        }

        System.out.println(answer);

        br.close();
    }
}
