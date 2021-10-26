package com.company;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] answer = new int[2];
        int sum = Integer.MAX_VALUE;
        Integer[] arr = Arrays.stream(br.readLine().split(" "))
                .map(Integer::parseInt).toArray(Integer[]::new);
        int idx1 = 0, idx2 = n-1;
        while (idx1 < idx2) {
            int cur = arr[idx1] + arr[idx2];
            if (Math.abs(sum) > Math.abs(cur)) {
                answer[0] = arr[idx1];
                answer[1] = arr[idx2];
                sum = arr[idx1] + arr[idx2];
            }
            if (cur < 0) {
                idx1++;
            } else {
                idx2--;
            }
        }
        System.out.println(answer[0] + " " + answer[1]);
    }
}
