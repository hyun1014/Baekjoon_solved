package com.company;

import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int a=0, b=0, c=0;
        int[][][] w = new int[21][21][21];
        for(int i=0; i<=20; i++){
            for(int j=0; j<=20; j++){
                for(int k=0; k<=20; k++){
                    if(i<=0 || j<=0 || k<=0)
                        w[i][j][k] = 1;
                    else if(i<j && j<k)
                        w[i][j][k] = w[i][j][k-1] + w[i][j-1][k-1] - w[i][j-1][k];
                    else
                        w[i][j][k] = w[i-1][j][k] + w[i-1][j-1][k] + w[i-1][j][k-1] - w[i-1][j-1][k-1];
                }
            }
        }

        while(true){
            a = sc.nextInt();
            b = sc.nextInt();
            c = sc.nextInt();
            if(a==-1 && b==-1 && c==-1)
                break;
            System.out.print("w(" + a + ", " + b + ", " + c + ") = ");
            if(a<=0 || b<=0 || c<=0)
                System.out.println(1);
            else if(a>20 || b>20 || c>20)
                System.out.println(w[20][20][20]);
            else
                System.out.println(w[a][b][c]);
        }
    }
}
