package com.company;

import java.util.*;

public class Main {
    static class Score implements Comparable<Score>{
        int first, second;
        Score(int first, int second){
            this.first = first;
            this.second = second;
        }

        @Override
        public int compareTo(Score score) {
            return Integer.compare(this.first, score.first);
        }
    }
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        List<Score> list = new ArrayList<>();
        int n, t, a, b, ans, tmp;
        t = sc.nextInt();
        for(int tcase=0; tcase<t; tcase++){
            list.clear();
            n = sc.nextInt();
            for(int i=0; i<n; i++){
                a = sc.nextInt();
                b = sc.nextInt();
                list.add(new Score(a,b));
            }
            Collections.sort(list);
            ans = 1;
            tmp = list.get(0).second;
            for(int i=1; i<n; i++){
                if(tmp>list.get(i).second){
                    tmp = list.get(i).second;
                    ans++;
                    if(tmp==1)
                        break;
                }
            }
            System.out.println(ans);
        }
    }
}
