package com.company;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        // write your code here
        int answer = 0;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int h = Integer.parseInt(st.nextToken());
        int w = Integer.parseInt(st.nextToken());
        int[] blocks = new int[w];
        int[] rain = new int[w];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < w; i++)
            blocks[i] = Integer.parseInt(st.nextToken());
        int highest = 0;
        rain[0] = blocks[0];
        for (int i = 1; i < w; i++) {
            rain[i] = blocks[i];
            if (blocks[i] > blocks[highest]) {
                for (int j = highest; j < i; j++)
                    rain[j] = blocks[highest];
                highest = i;
            } else {
                int j = i - 1;
                while (j >= 0) {
                    if (blocks[j] < blocks[i])
                        rain[j--] = blocks[i];
                    else
                        break;
                }
            }
        }
        for (int i = 0; i < w; i++)
            answer += (rain[i] - blocks[i]);

        System.out.println(answer);

        br.close();
    }
}

