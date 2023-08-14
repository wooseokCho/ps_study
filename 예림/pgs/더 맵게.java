import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for(int scov : scoville) {
            pq.add(scov);
        }
        
        while(pq.peek() < K && pq.size() >= 2) {
            int scov1 = pq.poll();
            int scov2 = pq.poll();
            pq.add(scov1 + scov2 * 2);
            answer++;
        }
        
        return pq.peek() >= K ? answer : -1;
    }
}