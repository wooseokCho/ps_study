import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) {
      Scanner sc = new Scanner(System.in);
      String word = sc.next();
      int[] alpha = new int[26];
      
      for(char c : word.toCharArray()) {
          c = Character.toUpperCase(c);
          alpha[c - 'A']++;
      }
      
      char answer = '?';
      int maxVal = 0;
      
      for(int i = 0; i < 26; i++) {
          if(maxVal < alpha[i]) {
              maxVal = alpha[i];
              answer = (char)('A' + i);
          }
          else if(maxVal == alpha[i]) {
              answer = '?';
          }
      }
      
      System.out.println(answer);
      
    }
}