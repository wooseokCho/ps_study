import java.io.*;
import java.util.*;

public class Main {
    
    static int w, h;
    static int[][] A;
    static boolean[][] visited;
    static int[] dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int[] dy = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    static boolean isOut(int x, int y) {
        return (x < 0 || x >= h || y < 0 || y >= w);
    }
    
    static void dfs(int x, int y) {
        visited[x][y] = true;
        
        for(int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(!isOut(nx, ny) && !visited[nx][ny] && A[nx][ny] == 1) {
                dfs(nx, ny);
            }
        }
    }
    
    public static void main(String args[]) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st;
      String line;
      
      while(!(line = br.readLine()).equals("0 0")) {
          st = new StringTokenizer(line);
          
          w = Integer.parseInt(st.nextToken());
          h = Integer.parseInt(st.nextToken());
          
          A = new int[h][w];
          visited = new boolean[h][w];
          
          for(int i = 0; i < h; i++) {
              st = new StringTokenizer(br.readLine());
              for(int j = 0; j < w; j++) {
                  A[i][j] = Integer.parseInt(st.nextToken());
              }
          }
          
          int island = 0;
          
          for(int i = 0; i < h; i++) {
              for(int j = 0; j < w; j++) {
                  if(A[i][j] == 1 && !visited[i][j]) {
                      dfs(i, j);
                      island++;
                  }
              }
          }
          
          System.out.println(island);
      }
    }
}