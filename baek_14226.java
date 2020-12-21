package com.company;

import java.util.*;

public class Main {
    public static class Pair {
        int a, b;
        Pair(int a, int b){
            this.a = a;
            this.b = b;
        }
        @Override
        public boolean equals(Object obj){
            Pair tar = (Pair)obj;
            return this.a == tar.a && this.b == tar.b;
        }
        @Override
        public int hashCode(){
            return this.a*10000+this.b;
        }
    }
    public static void main(String[] args) throws Exception {
        int prev = 1, next = 0, lv = 1;
        Queue<Pair> q = new LinkedList<>();
        Set<Pair> set = new HashSet<>();
        Scanner sc = new Scanner(System.in);
        int s = sc.nextInt();
        Pair cur = null;
        q.offer(new Pair(1, 1));
        set.add(new Pair(1,1));
        while(!q.isEmpty()){
            cur = q.poll();
            if(cur.a==s){
                System.out.println(lv);
                break;
            }
            if(set.add(new Pair(cur.a+cur.b, cur.b))){
                q.offer(new Pair(cur.a+cur.b, cur.b));
                next++;
            }
            if(cur.a!=cur.b && set.add(new Pair(cur.a, cur.a))){
                q.offer(new Pair(cur.a, cur.a));
                next++;
            }
            if(cur.a-1>=0 && set.add(new Pair(cur.a-1, cur.b))){
                q.offer(new Pair(cur.a-1, cur.b));
                next++;
            }
            prev--;
            if(prev==0){
                prev = next;
                next = 0;
                lv++;
            }
        }
    }
}

