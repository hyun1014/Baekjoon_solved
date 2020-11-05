package com.company;

import java.util.*;

public class Main {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        int n, k, cur, next, prev, ans;
        n = sc.nextInt();
        k = sc.nextInt();
        Queue<Integer> q = new LinkedList<>();
        boolean[] visited = new boolean[100001];
        Arrays.fill(visited, false);
        q.offer(n);
        visited[n] = true;
        ans = 0;
        prev = 1;
        next = 0;
        while(!q.isEmpty()){
            cur = q.poll();
            if(cur==k){
                System.out.print(ans);
                return;
            }
            if(cur-1>=0 && cur-1<=100000 && !visited[cur-1]){
                visited[cur-1] = true;
                q.offer(cur-1);
                next++;
            }
            if(cur+1>=0 && cur+1<=100000 && !visited[cur+1]){
                visited[cur+1] = true;
                q.offer(cur+1);
                next++;
            }
            if(cur*2>=0 && cur*2<=100000 && !visited[cur*2]){
                visited[cur*2] = true;
                q.offer(cur*2);
                next++;
            }
            prev--;
            if(prev==0){
                prev = next;
                next = 0;
                ans++;
            }
        }
    }
}
