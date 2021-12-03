package com.company;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, L, cur, lv, answer, tmp;

    static int[][] board = new int[100][100];
    static int[][] tempBoard = new int[100][100];
    static boolean[][] pedal = new boolean[100][100];

    static void cleanPedal() {
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                pedal[i][j] = false;
    }

    static void spinBoard() {
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                tempBoard[N-1-j][i] = board[i][j];

        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                board[i][j] = tempBoard[i][j];
    }

    static void scanBoard() {
        for(int i=0; i<N; i++){
            cur = 0;
            lv = board[i][0];
            while(cur<N-1){
                if(board[i][cur+1]==lv){
                    cur++;
                    continue;
                } else {
                    boolean flag = true;
                    if(lv>board[i][cur+1]){
                        if(cur+L>=N || lv-board[i][cur+1]!=1)
                            break;
                        tmp = board[i][cur+1];
                        for(int j=1; j<=L; j++){
                            if(board[i][cur+j]!=tmp || pedal[i][cur+j]){
                                flag = false;
                                break;
                            }
                        }
                        if(!flag)
                            break;
                        else {
                            for(int j=1; j<=L; j++)
                                pedal[i][cur+j] = true;
                            cur += L;
                            lv = tmp;
                        }
                    } else {
                        if(cur-L+1<0 || board[i][cur+1]-lv!=1)
                            break;
                        tmp = board[i][cur];
                        for(int j=1; j<=L-1; j++){
                            if(board[i][cur-j]!=tmp || pedal[i][cur-j]){
                                flag = false;
                                break;
                            }
                        }
                        if(flag && (cur-L==-1 || board[i][cur-L]==tmp || board[i][cur-L]==tmp-1)){
                            for(int j=0; j<=L-1; j++)
                                pedal[i][cur-j] = true;
                            cur++;
                            lv = board[i][cur];
                        } else {
                            break;
                        }
                    }
                }
            }
            if(cur==N-1){
                answer++;
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        answer = 0;
        N = Integer.parseInt(st.nextToken());
        L = Integer.parseInt(st.nextToken());

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        scanBoard();
        spinBoard();
        cleanPedal();
        scanBoard();

        System.out.println(answer);

        br.close();
    }
}