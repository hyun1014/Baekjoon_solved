package com.company;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
    static int n;
    static int m;
    static int k;
    static int[] dx = new int[] {0, -1, 1, 0, 0};
    static int[] dy = new int[] {0, 0, 0, -1, 1};
    static Shark[] priorityOfSharks;
    static Set<Integer> setOfRemainingShark = new HashSet<>();

    static Smell[][] smellBoard;
    static int[][] sharkBoard;
    static int[][] sharkBoardTemp;
    static int[] directionOfSharks;
    static int[] positionOfSharks;

    static class Smell {
        int count;
        int sharkNumber;
        Smell(int count, int sharkNumber) {
            this.count = count;
            this.sharkNumber = sharkNumber;
        }
    }
    static class Shark {
        int[][] priorityOfMovement = new int[5][4];
        void setPriorityOfMovement(int idx, String priorityString) {
            StringTokenizer st = new StringTokenizer(priorityString);
            for (int i = 0; i < 4; i++)
                priorityOfMovement[idx][i] = Integer.parseInt(st.nextToken());
        }
    }

    static boolean isOutOfBound(int x, int y) {
        return x < 0 || x >= n || y < 0 || y >= n;
    }

    static void moveShark(int sharkNumber) {
        int cx = positionOfSharks[sharkNumber] / 100;
        int cy = positionOfSharks[sharkNumber] % 100;
        int currentDirection = directionOfSharks[sharkNumber];
        int[] priorityOfMovement = priorityOfSharks[sharkNumber].priorityOfMovement[currentDirection];
        boolean isMoved = false;
        for (int idx = 0; idx < 4; idx++) {
            int dir = priorityOfMovement[idx];
            int fx = cx + dx[dir];
            int fy = cy + dy[dir];
            if (!isOutOfBound(fx, fy) && smellBoard[fx][fy] == null) {
                if (sharkBoardTemp[fx][fy] != 0) {
                    setOfRemainingShark.remove(sharkBoardTemp[fx][fy]);
                }
                sharkBoardTemp[fx][fy] = sharkNumber;
                positionOfSharks[sharkNumber] = fx * 100 + fy;
                directionOfSharks[sharkNumber] = dir;
                isMoved = true;
                break;
            }
        }
        if (isMoved)
            return;

        for (int idx = 0; idx < 4; idx++) {
            int dir = priorityOfMovement[idx];
            int fx = cx + dx[dir];
            int fy = cy + dy[dir];
            if (!isOutOfBound(fx, fy) && smellBoard[fx][fy].sharkNumber == sharkNumber) {
                sharkBoardTemp[fx][fy] = sharkNumber;
                positionOfSharks[sharkNumber] = fx * 100 + fy;
                directionOfSharks[sharkNumber] = dir;
                break;
            }
        }
    }

    static void decreaseSmell() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (smellBoard[i][j] != null) {
                    smellBoard[i][j].count--;
                    if (smellBoard[i][j].count == 0)
                        smellBoard[i][j] = null;
                }
            }
        }
    }

    static void updateBoard() {
        for (int sharkNumber = m; sharkNumber > 0; sharkNumber--) {
            if (setOfRemainingShark.contains(sharkNumber)) {
                smellBoard[positionOfSharks[sharkNumber]/100][positionOfSharks[sharkNumber]%100] = new Smell(k, sharkNumber);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sharkBoard[i][j] = sharkBoardTemp[i][j];
                sharkBoardTemp[i][j] = 0;
            }
        }
    }

    static void doProcess() {
        for (int currentSharkNumber = m; currentSharkNumber > 0; currentSharkNumber--) {
            if (!setOfRemainingShark.contains(currentSharkNumber)) {
                continue;
            }
            moveShark(currentSharkNumber);
        }
        decreaseSmell();
        updateBoard();
    }

    public static void main(String[] args) throws Exception {
        int answer = 0;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        smellBoard = new Smell[n][n];
        sharkBoard = new int[n][n];
        sharkBoardTemp = new int[n][n];
        priorityOfSharks = new Shark[m + 1];
        directionOfSharks = new int[m + 1];
        positionOfSharks = new int[m + 1];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                int sharkNumber = Integer.parseInt(st.nextToken());
                if (sharkNumber != 0) {
                    priorityOfSharks[sharkNumber] = new Shark();
                    positionOfSharks[sharkNumber] = i * 100 + j;
                    setOfRemainingShark.add(sharkNumber);
                    smellBoard[i][j] = new Smell(k, sharkNumber);
                }
            }
        }

        st = new StringTokenizer(br.readLine());
        for (int sharkNumber = 1; sharkNumber <= m; sharkNumber++)
            directionOfSharks[sharkNumber] = Integer.parseInt(st.nextToken());

        for (int sharkNumber = 1; sharkNumber <= m; sharkNumber++) {
            for (int direction = 1; direction <= 4; direction++) {
                priorityOfSharks[sharkNumber].setPriorityOfMovement(direction, br.readLine());
            }
        }

        do {
            answer++;
            if (answer > 1000) {
                answer = -1;
                break;
            }
            doProcess();
        } while (setOfRemainingShark.size() > 1);

        System.out.println(answer);

        br.close();
    }
}