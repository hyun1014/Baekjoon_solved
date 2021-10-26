package com.company;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static class Node {
        int num;
        int cost;
        Node(int num, int cost) {
            this.num = num;
            this.cost = cost;
        }
    }
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());
        int from, to, c;
        int[][] arr = new int[n+1][n+1];
        int[] cost = new int[n+1];
        for (int i = 1; i <= n; i++) {
            Arrays.fill(arr[i], Integer.MAX_VALUE);
        }
        Arrays.fill(cost, Integer.MAX_VALUE);
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            from = Integer.parseInt(st.nextToken());
            to = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());
            arr[from][to] = Integer.min(arr[from][to], c);

        }
        st = new StringTokenizer(br.readLine());
        from = Integer.parseInt(st.nextToken());
        to = Integer.parseInt(st.nextToken());
        cost[from] = 0;

        PriorityQueue<Node> pq = new PriorityQueue<>(Comparator.comparingInt(o -> o.cost));
        pq.add(new Node(from, 0));

        while(!pq.isEmpty()) {
            Node cur = pq.poll();
            for (int i = 1; i <= n; i++) {
                if (arr[cur.num][i] != Integer.MAX_VALUE && cost[cur.num] + arr[cur.num][i] < cost[i]) {
                    pq.add(new Node(i, cost[cur.num] + arr[cur.num][i]));
                    cost[i] = arr[cur.num][i] + cost[cur.num];
                }
            }
        }
        System.out.println(cost[to]);
    }
}
