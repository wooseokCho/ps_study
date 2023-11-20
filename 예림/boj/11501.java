import java.util.*;

public class Main {
    public static void main(String args[]) {
      Scanner sc = new Scanner(System.in);
      int T = sc.nextInt();
      
      while(T-- > 0) {
          int N = sc.nextInt();
          int[] A = new int[N];
          
          for(int i = 0; i < N; i++) {
              A[i] = sc.nextInt();
          }
          
          long answer = 0;
          int maxProfit = A[N - 1];
          
          for(int i = N-2; i >= 0; i--) {
              if(maxProfit < A[i]) {
                  maxProfit = A[i];
              } else {
                  answer += maxProfit - A[i];
              }
          }
          
          System.out.println(answer);
      }
    }
}