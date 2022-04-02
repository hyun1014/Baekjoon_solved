package com.modern;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] time = br.readLine().split(" ");
        int hour = Integer.parseInt(time[0]);
        int minute = Integer.parseInt(time[1]);
        int cost = Integer.parseInt(br.readLine());
        hour = (hour + ((minute + cost) / 60)) % 24;
        minute = (minute + cost) % 60;
        System.out.println(hour + " " + minute);
    }
}
