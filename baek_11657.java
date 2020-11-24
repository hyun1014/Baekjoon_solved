import java.util.*;

public class Main {
    public static final int INF = Integer.MAX_VALUE;
    static class Edge {
        int source, desc, weight;
        Edge(int source, int desc, int weight){
            this.source = source;
            this.desc = desc;
            this.weight = weight;
        }
    }
    static Edge[] edges;
    static long[] dis;
    static boolean bellmanFord(int v, int e){
        dis[1] = 0;
        for(int i=0; i<v-1; i++){
            for(int j=0; j<e; j++){
                Edge cur = edges[j];
                if(dis[cur.source]==INF)
                    continue;
                if(dis[cur.desc] > (dis[cur.source] + cur.weight))
                    dis[cur.desc] = dis[cur.source] + cur.weight;
            }
        }
        for(int i=0; i<e; i++){
            Edge cur = edges[i];
            if(dis[cur.source]!=INF && dis[cur.desc] > dis[cur.source] + cur.weight)
                return false;
        }
        return true;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, m, from, to, cost;
        n = sc.nextInt();
        m = sc.nextInt();
        edges = new Edge[m];
        dis = new long[n+1];
        Arrays.fill(dis, INF);
        for(int i=0; i<m; i++){
            from = sc.nextInt();
            to = sc.nextInt();
            cost = sc.nextInt();
            edges[i] = new Edge(from, to, cost);
        }
        boolean isNegCycle = bellmanFord(n, m);
        if(!isNegCycle){
            System.out.println(-1);
        }
        else{
            for(int i=2; i<=n; i++){
                if(dis[i]==INF)
                    System.out.println(-1);
                else
                    System.out.println(dis[i]);
            }
        }
    }
}
