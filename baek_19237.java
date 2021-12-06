package com.company;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
    static int n, m, k;
    static int[] dx = new int[] {0, -1, 1, 0, 0};
    static int[] dy = new int[] {0, 0, 0, -1, 1};
    static int[][] smellCount;
    static int[][] smellCountTemp;
    static int[][] smellShark;
    static int[][] smellSharkTemp;
    static Shark[] sharkList;
    static int[] directionOfShark;
    static int[] pointOfShark;
    static Set<Integer> sharkSet = new HashSet<>();
    static class Shark {
        int[][] priority = new int[5][4];
        void setPriority(int idx, String info) {
            StringTokenizer st = new StringTokenizer(info);
            for (int i = 0; i < 4; i++) {
                priority[idx][i] = Integer.parseInt(st.nextToken());
            }
        }
    }

    static boolean isOutOfBound(int x, int y) {
        return x < 0 || x >= n || y < 0 || y >= n;
    }

    static void moveShark() {
        for (int i = sharkList.length - 1; i > 0; i--) {
            boolean isMoved = false;
            if (sharkSet.contains(i)) {
                Shark currentShark = sharkList[i];
                int x = pointOfShark[i] / 100;
                int y = pointOfShark[i] % 100;
                int[] priorityOfDirection = currentShark.priority[directionOfShark[i]];
                for (int j = 0; j < 4; j++) {
                    int fx = x + dx[priorityOfDirection[j]];
                    int fy = y + dy[priorityOfDirection[j]];
                    if (!isOutOfBound(fx, fy) && smellCount[fx][fy] == 0) {
                        if (smellSharkTemp[fx][fy] != 0) {
                            sharkSet.remove(smellSharkTemp[fx][fy]);
                        }
                        smellCountTemp[fx][fy] = k;
                        smellSharkTemp[fx][fy] = i;
                        pointOfShark[i] = fx * 100 + fy;
                        directionOfShark[i] = priorityOfDirection[j];
                        isMoved = true;
                        break;
                    }
                }
                if (!isMoved) {
                    for (int j = 0; j < 4; j++) {
                        int fx = x + priorityOfDirection[j];
                        int fy = y + priorityOfDirection[j];
                        if (!isOutOfBound(fx, fy) && smellShark[fx][fy] == i) {
                            smellCountTemp[fx][fy] = k;
                            smellSharkTemp[fx][fy] = i;
                            pointOfShark[i] = fx * 100 + fy;
                            directionOfShark[i] = priorityOfDirection[j];
                            break;
                        }
                    }
                }
            }
        }
    }

    static void decreaseSmell() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                smellCount[i][j]--;
                if (smellCount[i][j] <= 0) {
                    smellCount[i][j] = 0;
                    smellShark[i][j] = 0;
                }
            }
        }
    }

    static void clearBoard() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (smellSharkTemp[i][j] != 0) {
                    smellShark[i][j] = smellSharkTemp[i][j];
                    smellSharkTemp[i][j] = 0;
                }
                if (smellCountTemp[i][j] != 0) {
                    smellCount[i][j] = smellCountTemp[i][j];
                    smellCountTemp[i][j] = 0;
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        int answer = 0;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        smellCount = new int[n][n];
        smellCountTemp = new int[n][n];
        smellShark = new int[n][n];
        smellSharkTemp = new int[n][n];
        sharkList = new Shark[m + 1];
        pointOfShark = new int[m + 1];
        directionOfShark = new int[m + 1];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                smellShark[i][j] = Integer.parseInt(st.nextToken());
                if (smellShark[i][j] != 0) {
                    smellCount[i][j] = k;
                    pointOfShark[smellShark[i][j]] = i * 100 + j;
                }
            }
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= m; i++)
            directionOfShark[i] = Integer.parseInt(st.nextToken());

        for (int i = 1; i <= m; i++) {
            sharkList[i] = new Shark();
            sharkSet.add(i);
            for (int j = 1; j <= 4; j++)
                sharkList[i].setPriority(j, br.readLine());
        }

        do {
            answer++;
            moveShark();
            decreaseSmell();
            clearBoard();
        } while (sharkSet.size() > 1);

        System.out.println(answer);

        br.close();
    }
}