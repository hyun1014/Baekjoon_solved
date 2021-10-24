package com.company;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.function.ToIntFunction;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.comparingInt((ToIntFunction<Integer>) Math::abs)
                .thenComparingInt(integer -> integer));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        int tar;
        for (int i = 0; i < n; i++) {
            tar = Integer.parseInt(br.readLine());
            if (tar == 0) {
                if (pq.isEmpty())
                    sb.append(0).append("\n");
                else
                    sb.append(pq.poll()).append("\n");
            } else {
                pq.add(tar);
            }
        }
        System.out.println(sb);
    }
}
