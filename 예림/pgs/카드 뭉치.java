class Solution {
    public String solution(String[] cards1, String[] cards2, String[] goal) {
        String answer = "Yes";
        int i = 0, j = 0;
        
        for(String word : goal) {
            if(i < cards1.length && cards1[i].equals(word)) {
                i++;
            } else if(j < cards2.length && cards2[j].equals(word)) {
                j++;
            } else {
                answer = "No";
                break;
            } 
        }
        
        return answer;
    }
}