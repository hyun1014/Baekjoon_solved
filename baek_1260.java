import java.util.*;

public class Main {
    static List<List<Integer>> linkedList;

    static List<Integer> dfs(int start) throws Exception {
        int vertexCount = linkedList.size() - 1;
        int cur, tar, elen;
        boolean[] visited = new boolean[vertexCount+1];
        int[] idx = new int[vertexCount+1];
        Stack<Integer> stk = new Stack<>();
        List<Integer> vList = new ArrayList<>();
        Arrays.fill(visited, false);
        Arrays.fill(idx, -1);
        stk.push(start);
        visited[start] = true;
        while(!stk.empty()){
            cur = stk.peek();
            if(idx[cur]==-1){
                vList.add(cur);
                idx[cur]++;
            }
            elen = linkedList.get(cur).size();
            for( ; idx[cur]<elen; idx[cur]++){
                tar = linkedList.get(cur).get(idx[cur]);
                if(!visited[tar]){
                    visited[tar] = true;
                    stk.push(tar);
                    break;
                }
            }
            if(idx[cur]==linkedList.get(cur).size())
                stk.pop();
        }
        return vList;
    }
    static List<Integer> bfs(int start){
        int vertexCount = linkedList.size() - 1;
        int cur, tar, elen;
        List<Integer> vList = new ArrayList<>();
        Queue<Integer> queue = new LinkedList<>();
        boolean[] visited = new boolean[vertexCount+1];
        Arrays.fill(visited, false);
        queue.offer(start);
        visited[start] = true;
        vList.add(start);
        while(!queue.isEmpty()){
            cur = queue.poll();
            elen = linkedList.get(cur).size();
            for(int i=0; i<elen; i++){
                tar = linkedList.get(cur).get(i);
                if(!visited[tar]){
                    vList.add(tar);
                    visited[tar] = true;
                    queue.offer(tar);
                }
            }
        }
        return vList;
    }

    public static void main(String[] args) throws Exception{
        Scanner sc = new Scanner(System.in);
        int n, m, v, from, to, dfsLen, bfsLen;
        linkedList = new ArrayList<>();
        n = sc.nextInt();
        m = sc.nextInt();
        v = sc.nextInt();
        for(int i=0; i<=n; i++)
            linkedList.add(new ArrayList<>());
        for(int i=0; i<m; i++){
            from = sc.nextInt();
            to = sc.nextInt();
            linkedList.get(from).add(to);
            linkedList.get(to).add(from);
        }
        for(int i=1; i<=n; i++)
            Collections.sort(linkedList.get(i));
        List<Integer> dfsList = dfs(v);
        List<Integer> bfsList = bfs(v);
        dfsLen = dfsList.size();
        bfsLen = bfsList.size();
        for(int i=0; i<dfsLen; i++){
            System.out.print(dfsList.get(i));
            System.out.print(" ");
        }
        System.out.println();
        for(int i=0; i<bfsLen; i++){
            System.out.print(bfsList.get(i));
            System.out.print(" ");
        }
    }
}
