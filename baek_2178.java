package com.company;

import java.util.*;

public class Main {
    static Scanner sc = new Scanner(System.in);
    static int n, m;
    static int[][] arr;
    static boolean[][] visited;
    static int[] dx = new int[]{-1, 0, 1, 0};
    static int[] dy = new int[]{0, 1, 0, -1};
    static class Pair{
        int a, b;
        Pair(int a, int b){this.a = a; this.b = b;}
        int first(){return this.a;}
        int second(){return this.b;}
    }
    static boolean check(int a, int b){
        return a >= 0 && a < n && b >= 0 && b < m;
    }
    public static void main(String[] args) {
        n = sc.nextInt();
        m = sc.nextInt();
        sc.nextLine();
        arr = new int[n][m];
        visited = new boolean[n][m];
        String tmp;
        String[] ar;
        for(int i=0; i<n; i++){
            Arrays.fill(visited[i], false);
            ar = sc.nextLine().split("");
            for(int j=0; j<m; j++)
                arr[i][j] = Integer.parseInt(ar[j]);
        }
        Queue<Pair> q = new LinkedList<>();
        q.offer(new Pair(0,0));
        visited[0][0] = true;
        int next = 0;
        int prev = 1;
        int ans = 0;
        while(!q.isEmpty()){
            Pair cur = q.poll();
            prev--;
            if(cur.first()==n-1 && cur.second()==m-1){
                System.out.println(ans+1);
                return;
            }
            for(int i=0; i<4; i++){
                int da = cur.first() + dx[i];
                int db = cur.second() + dy[i];
                if(check(da, db) && !visited[da][db] && arr[da][db]==1){
                    visited[da][db] = true;
                    q.offer(new Pair(da, db));
                    next++;
                }
            }
            if(prev==0){
                prev = next;
                next = 0;
                ans++;
            }
        }
    }
}
