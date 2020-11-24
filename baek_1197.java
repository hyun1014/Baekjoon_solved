import java.util.*;

public class Main {
    static List<Integer> parent;
    static class Edge implements Comparable<Edge> {
        int a, b, w;
        Edge(int a, int b, int w){
            this.a = a;
            this.b = b;
            this.w = w;
        }
        @Override
        public int compareTo(Edge target){
            if(this.w==target.w)
                return this.a < target.a ? -1 : 1;
            else
                return this.w < target.w ? -1 : 1;
        }
    }
    static int find(int x){
        if(parent.get(x)==x)
            return x;
        else{
            parent.set(x, find(parent.get(x)));
            return parent.get(x);
        }
    }
    static void union(int x, int y){
        int xp = find(x);
        int yp = find(y);
        parent.set(yp, xp);
    }
    static boolean check(int x, int y){
        return find(x)==find(y);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int v, e, a, b, w;
        int result = 0;
        v = sc.nextInt();
        e = sc.nextInt();
        parent = new ArrayList<>();
        for(int i=0; i<=v; i++)
            parent.add(i);
        PriorityQueue<Edge> queue = new PriorityQueue<>();
        for(int i=0; i<e; i++){
            a = sc.nextInt();
            b = sc.nextInt();
            w = sc.nextInt();
            queue.offer(new Edge(a, b, w));
        }
        while(!queue.isEmpty()){
            Edge cur = queue.poll();
            if(!check(cur.a, cur.b)){
                result += cur.w;
                union(cur.a, cur.b);
            }
        }
        System.out.println(result);
    }
}
