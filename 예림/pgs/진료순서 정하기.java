import java.util.*;

class Solution {
    public int[] solution(int[] emergency) {
        int n = emergency.length;
        int[] order = emergency.clone();    // 깊은 복사
        int[] answer = new int[n];
        
        Arrays.sort(order);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(emergency[i] == order[j]) {
                    answer[i] = n - j;
                    break;
                }
            }
        }
        
        return answer;
    }
}