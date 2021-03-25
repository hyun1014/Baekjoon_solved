package com.company;

import java.io.FileInputStream;
import java.util.*;
import java.util.regex.Pattern;

public class Main {
    static Set<String> set = new HashSet<>();
    public static void permutation(String prefix, String str){
        int len = str.length();
        if(!prefix.equals(""))
            set.add(prefix);
        for(int i=0; i<len; i++)
            permutation(prefix+str.charAt(i), str.substring(0, i)+str.substring(i+1));
    }

    static boolean[][] board = new boolean[1001][1001];
    static boolean[][] breakVisited = new boolean[1001][1001];
    static boolean[][] unbreakVisited = new boolean[1001][1001];
    static int[] dx = new int[]{0, -1, 0, 1};
    static int[] dy = new int[]{-1, 0, 1, 0};

    static class Node {
        int pos;
        boolean breakChance;

        Node(int pos, boolean breakChance){
            this.pos = pos;
            this.breakChance = breakChance;
        }
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        Queue<Node> queue = new LinkedList<>();
        int n = sc.nextInt(), m = sc.nextInt();
        sc.nextLine();
        int prev = 1, next = 0, lv = 1;
        boolean flag = false;
        String str;
        for(int i=0; i<n; i++){
            str = sc.nextLine();
            for(int j=0; j<m; j++)
                board[i+1][j+1] = str.charAt(j) == '0';
        }

        queue.add(new Node(10001, true));
        while(!queue.isEmpty()){
            Node cur = queue.poll();
            if(cur.pos==(n*10000+m)){
                flag = true;
                break;
            }
            int curX = cur.pos/10000, curY = cur.pos%10000;
            for(int i=0; i<4; i++){
                int tarX = curX + dx[i];
                int tarY = curY + dy[i];
                if(tarX>=1 && tarX<=n && tarY>=1 && tarY<=m){
                    if(board[tarX][tarY]){
                        if(cur.breakChance && !unbreakVisited[tarX][tarY]){
                            unbreakVisited[tarX][tarY] = true;
                            queue.add(new Node(tarX*10000+tarY, true));
                            next++;
                        } else if(!cur.breakChance && !breakVisited[tarX][tarY]){
                            breakVisited[tarX][tarY] = true;
                            queue.add(new Node(tarX*10000+tarY, false));
                            next++;
                        }
                    } else if (cur.breakChance && !breakVisited[tarX][tarY]){
                        breakVisited[tarX][tarY] = true;
                        queue.add(new Node(tarX*10000+tarY, false));
                        next++;
                    }
                }
            }
            prev--;

            if(prev==0){
                prev = next;
                next = 0;
                lv++;
            }
        }

        if(!flag)
            lv = -1;
        System.out.println(lv);
    }
}
