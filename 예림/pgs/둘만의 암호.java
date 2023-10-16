import java.util.*;

class Solution {
    public String solution(String s, String skip, int index) {
        String answer = "";
        List<Character> list = new ArrayList<>();
        
        for(int i = 0; i < 26; i++) {
            list.add((char)('a' + i));
        }
        
        for(Character c : skip.toCharArray()) {
            list.remove(c);
        }
        
        for(Character c : s.toCharArray()) {
            int idx = (list.indexOf(c) + index) % list.size();
            answer += list.get(idx);
        }
        
        return answer;
    }
}