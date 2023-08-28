import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) throws IOException {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      PriorityQueue<Integer> pq = new PriorityQueue<>();
      int N = Integer.parseInt(br.readLine());
      
      for(int i = 0; i < N; i++) {
          int x = Integer.parseInt(br.readLine());
          
          if(x == 0) {
              if(pq.isEmpty()) {
                  x = 0;
              }
              else {
                  x = pq.poll();
              }
              System.out.println(x);
          }
          else {
              pq.add(x);
          }
      }
    }
}