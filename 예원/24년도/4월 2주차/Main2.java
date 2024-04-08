import java.util.*;
class Node {
    private int index;
    private int distance;

    public Node(int index, int distance){
        this.index = index;
        this.distance = distance;
    }
    public int getIndex(){
        return this.index;
    }
    public int getDistance(){
        return this.distance;
    }
}
public class Main2{
    public static int n,m;
    public static int[][] graph = new int[201][201];
    public static int dx[] = {-1,1,0,0};
    public static int dy[] = {0,0,-1,1};
    public static int bfs(int x, int y){
        Queue<Node> q = new LinkedList<>();
        q.offer(new Node(x,y));
        while (!q.isEmpty()) {
            Node node = q.poll();
            x = node.getIndex();
            y = node.getDistance();
            for (int i = 0; i<4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if (nx<0 || nx>=n||ny<0 || ny>=m) continue;
                if (graph[nx])

            }
            
        }
    }

} 
