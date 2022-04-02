package com.modern;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = (Integer.parseInt(br.readLine()));
        Set<String> set = new HashSet<>();
        for (int i = 0; i < n; i++) {
            set.add(br.readLine());
        }
        set.stream()
            .sorted((s1, s2) -> s1.length() == s2.length() ? s1.compareTo(s2) : Integer.compare(s1.length(), s2.length()))
            .forEach(it -> sb.append(it + "\n"));

        System.out.println(sb);
    }
}
