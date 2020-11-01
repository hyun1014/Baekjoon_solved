import java.util.*;

public class Main {
    static Scanner sc = new Scanner(System.in);
    static int[][] arr;
    static int n, m, t;
    static int[] dx = new int[]{-1,0,1,0};
    static int[] dy = new int[]{0,1,0,-1};
    static class Pair {
        int a, b;
        Pair(int a, int b){this.a = a; this.b = b;}
        int first(){return this.a;}
        int second(){return this.b;}
    }
    static void spin(int idx, int rot, int dir) {
        if(dir==1)
            rot *= -1;
        int[] tmp = arr[idx].clone();
        for(int i=0; i<arr[idx].length; i++){
            arr[idx][i] = i-rot>=0 ? tmp[(i-rot)%m] : tmp[m + (i-rot)%m];
        }
        return;
    }
    static boolean checka(int a){return a >= 1 && a <= n;}
    static int checkb(int b) {return b<0? m-1 : (b==m ? 0 : b);}
    static void bfs(int a, int b){
        Queue<Pair> q = new LinkedList<>();
        boolean[][] v = new boolean[n+1][m];
        for(int i=0; i<=n; i++)
            Arrays.fill(v[i], false);
        q.offer(new Pair(a, b));
        v[a][b] = true;
        while(!q.isEmpty()){
            Pair cur = q.poll();
            for(int i=0; i<4; i++){
                int da = cur.first() + dx[i];
                int db = checkb(cur.second() + dy[i]);
                if(checka(da) && arr[da][db]!=0 && arr[da][db]==arr[a][b] && !v[da][db]){
                    arr[da][db] = 0;
                    v[da][db] = true;
                    q.offer(new Pair(da, db));
                }
            }
        }
    }
    public static void main(String[] args) {
        int x, d, k, sum, cnt;
        double aver;
        n = sc.nextInt();
        m = sc.nextInt();
        t = sc.nextInt();
        arr = new int[n+1][m];
        for(int i=1; i<=n; i++)
            for(int j=0; j<m; j++)
                arr[i][j] = sc.nextInt();

        for(int tc=0; tc<t; tc++) {
            x = sc.nextInt();
            d = sc.nextInt();
            k = sc.nextInt();
            for (int i = 1; i <= n; i++)
                if (i % x == 0)
                    spin(i, k, d);
            boolean same = false;
            for(int a=1; a<=n; a++){
                for(int b=0; b<m; b++){
                    for(int c=0; c<4; c++){
                        int da = a + dx[c];
                        int db = checkb(b + dy[c]);
                        if(checka(da) && arr[a][b]!=0 && arr[da][db]!=0 && arr[da][db]==arr[a][b]){
                            bfs(a, b);
                            same = true;
                            arr[a][b] = 0;
                        }
                    }
                }
            }
            if(!same){
                sum = 0;
                cnt = 0;
                for(int a=1; a<=n; a++){
                    for(int b=0; b<m; b++){
                        if(arr[a][b]!=0){
                            sum += arr[a][b];
                            cnt++;
                        }
                    }
                }
                aver = (double)sum / (double)cnt;
                for(int a=1; a<=n; a++){
                    for(int b=0; b<m; b++) {
                        if(arr[a][b]!=0){
                            if((double)arr[a][b]>aver)
                                arr[a][b]--;
                            else if((double)arr[a][b]<aver)
                                arr[a][b]++;
                        }
                    }
                }
            }
        }
        sum = 0;
        for(int a=1; a<=n; a++)
            for(int b=0; b<m; b++)
                sum += arr[a][b];
        System.out.println(sum);
    }
}
