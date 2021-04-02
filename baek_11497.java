package com.company;

import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int[] arr0 = new int[100000];
        int[] arr1 = new int[100000];
        int n, t, ans, idx0, idx1;
        t = sc.nextInt();
        for(int tcase=0; tcase<t; tcase++){
            n = sc.nextInt();
            ans = -1;
            idx0 = 0;
            idx1 = 0;
            for(int i=0; i<n; i++)
                arr0[i] = sc.nextInt();
            Arrays.sort(arr0, 0, n);
            for( ; idx0<n; idx0+=2){
                arr1[idx1] = arr0[idx0];
                idx1++;
            }
            if(idx0==n)
                idx0 = n-1;
            else
                idx0 = n-2;
            for( ; idx0>0; idx0-=2){
                arr1[idx1] = arr0[idx0];
                idx1++;
            }
            for(int i=0; i<n-1; i++) {
                int abs = Math.abs(arr1[i] - arr1[i + 1]);
                if(abs > ans)
                    ans = abs;
            }
            System.out.println(ans);
        }
    }
}
