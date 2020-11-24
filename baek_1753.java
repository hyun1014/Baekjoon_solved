import java.util.*;

public class baek_1753 {
    static List<List<Edge>> linkedList;
    static int[] dis;
    static class Edge implements Comparable<Edge> {
        int tar;
        int cost;
        Edge(int tar, int cost){
            this.tar = tar;
            this.cost = cost;
        }
        @Override
        public int compareTo(Edge target){
            if(this.cost==target.cost)
                return this.tar < target.tar ? -1 : 1;
            else
                return this.cost < target.cost ? -1 : 1;
        }
    }
    static void dijkstra(int start){
        PriorityQueue<Edge> queue = new PriorityQueue<>();
        Edge cur;
        int curNode, curCost, elen, tarNode, tarCost;
        queue.add(new Edge(start, 0));
        dis[start] = 0;
        while(!queue.isEmpty()){
            cur = queue.poll();
            curNode = cur.tar;
            curCost = cur.cost;
            elen = linkedList.get(curNode).size();
            for(int i=0; i<elen; i++){
                tarNode = linkedList.get(curNode).get(i).tar;
                tarCost = linkedList.get(curNode).get(i).cost;
                if(dis[tarNode] > curCost + tarCost){
                    dis[tarNode] = curCost + tarCost;
                    queue.add(new Edge(tarNode, dis[tarNode]));
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        linkedList = new ArrayList<>();
        int v, e, k, from, to, cost;
        v = sc.nextInt();
        e = sc.nextInt();
        k = sc.nextInt();
        dis = new int[v+1];
        Arrays.fill(dis, 99999999);
        for(int i=0; i<=v; i++)
            linkedList.add(new ArrayList<>());
        for(int i=0; i<e; i++){
            from = sc.nextInt();
            to = sc.nextInt();
            cost = sc.nextInt();
            linkedList.get(from).add(new Edge(to, cost));
        }
        dijkstra(k);
        for(int i=1; i<=v; i++){
            if(dis[i]==99999999)
                System.out.println("INF");
            else
                System.out.println(dis[i]);
        }
        sc.close();
    }
}
