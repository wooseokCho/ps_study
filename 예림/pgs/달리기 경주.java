import java.util.*;

class Solution {
    public String[] solution(String[] players, String[] callings) {
        Map<String, Integer> hm = new HashMap<>();  // 이름, 등수
        
        for(int i = 0; i < players.length; i++) {
            hm.put(players[i], i);
        }
        
        for(String name : callings) {
            int nowRank = hm.get(name);
            String prevPlayer = players[nowRank - 1];
            
            hm.put(name, nowRank - 1);
            hm.put(prevPlayer, nowRank);
            
            players[nowRank - 1] = name;
            players[nowRank] = prevPlayer;
        }
        
        return players;
    }
}