package com.company;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int a = 1, b = 2, tmp = 0;
        for (int i = 0; i < n - 2; i++) {
            tmp = (a + b) % 10007;
            a = b;
            b = tmp;
        }
        if (n == 1)
            System.out.println(1);
        else
            System.out.println(b);

        br.close();
    }
}
