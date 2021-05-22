package com.company;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        int N, kcal, m;
        double M, price;
        int[] kcalArray;
        int[] priceArray;
        int[] dp;
        Scanner sc = new Scanner(System.in);
        while(true){
            N = sc.nextInt();
            M = sc.nextDouble();
            if(N==0 && M==0)
                break;
            m = (int)(M*100+0.5);
            kcalArray = new int[N];
            priceArray = new int[N];
            dp = new int[m+1];
            for(int i=0; i<N; i++){
                kcal = sc.nextInt();
                price = sc.nextDouble();
                kcalArray[i] = kcal;
                priceArray[i] = (int)(price*100+0.5);
            }
            for(int i=0; i<=m; i++)
                for(int j=0; j<N; j++)
                    if(i-priceArray[j]>=0)
                        dp[i] = Math.max(dp[i], dp[i - priceArray[j]] + kcalArray[j]);
            System.out.println(dp[m]);
        }
    }
}
