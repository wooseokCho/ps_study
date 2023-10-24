class Solution {
    public int solution(int[] numbers) {
        int answer = 9 * 10 / 2;    // 0 ~ 9 까지 합

        for(int number : numbers) {
            answer -= number;
        }
        
        return answer;
    }
}