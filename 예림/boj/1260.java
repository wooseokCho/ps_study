import java.util.*;

public class Main {
    
    static int N, M, V;
    static int a, b;
    static boolean[][] graph;
    static boolean[] visited;
    
    public static void main(String args[]) {
      Scanner sc = new Scanner(System.in);
      
      N = sc.nextInt();
      M = sc.nextInt();
      V = sc.nextInt();
      
      graph = new boolean[N + 1][N + 1];
      visited = new boolean[N + 1];
      
      for(int i = 0; i < M; i++) {
          a = sc.nextInt();
          b = sc.nextInt();
          graph[a][b] = true;
          graph[b][a] = true;
      }
      
      dfs(V);
      System.out.println();
      
      visited = new boolean[N + 1];
      bfs(V);
    }
    
    static void dfs(int cur) {
        visited[cur] = true;
        System.out.print(cur + " ");
        
        for(int next = 1; next <= N; next++) {
            if(graph[cur][next] && !visited[next]) {
                dfs(next);
            }
        }
    }
    
    static void bfs(int cur) {
        Queue<Integer> q = new LinkedList<>();
        
        q.offer(cur);
        visited[cur] = true;
        
        while(!q.isEmpty()) {
            int now = q.poll();
            System.out.print(now + " ");
            
            for(int next = 1; next <= N; next++) {
                if(graph[now][next] && !visited[next]) {
                    q.offer(next);
                    visited[next] = true;
                }
            }
        }
    }
}